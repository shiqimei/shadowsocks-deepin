#include <util/Util.h>
#include "ListView.h"

ListView::ListView(QWidget *parent) : QWidget(parent) {
    // Init.
    installEventFilter(this);   // add event filter
    setMouseTracking(true);    // make MouseMove can response

    scrollDistance = 0;
    renderOffset = 0;
    titleHeight = 0;
    titleArrowPadding = 4;
    titlePadding = 14;

    scrollAnimationTimer = NULL;
    scrollAnimationTicker = 0;
    scrollAnimationFrames = 16;
    scrollAnimationDuration = 25;

    searchContent = "";
    searchAlgorithm = NULL;

    titleHoverColumn = -1;
    titlePressColumn = -1;

    arrowUpDarkNormalImage = QImage(Util::getQrcPath("arrow_up_dark_normal.png"));
    arrowUpDarkHoverImage = QImage(Util::getQrcPath("arrow_up_dark_hover.png"));
    arrowUpDarkPressImage = QImage(Util::getQrcPath("arrow_up_dark_press.png"));
    arrowDownDarkNormalImage = QImage(Util::getQrcPath("arrow_down_dark_normal.png"));
    arrowDownDarkHoverImage = QImage(Util::getQrcPath("arrow_down_dark_hover.png"));
    arrowDownDarkPressImage = QImage(Util::getQrcPath("arrow_down_dark_press.png"));

    arrowUpLightNormalImage = QImage(Util::getQrcPath("arrow_up_light_normal.png"));
    arrowUpLightHoverImage = QImage(Util::getQrcPath("arrow_up_light_hover.png"));
    arrowUpLightPressImage = QImage(Util::getQrcPath("arrow_up_light_press.png"));
    arrowDownLightNormalImage = QImage(Util::getQrcPath("arrow_down_light_normal.png"));
    arrowDownLightHoverImage = QImage(Util::getQrcPath("arrow_down_light_hover.png"));
    arrowDownLightPressImage = QImage(Util::getQrcPath("arrow_down_light_press.png"));

    arrowUpNormalImage = arrowUpLightNormalImage;
    arrowUpHoverImage = arrowUpLightHoverImage;
    arrowUpPressImage = arrowUpLightPressImage;
    arrowDownNormalImage = arrowDownLightNormalImage;
    arrowDownHoverImage = arrowDownLightHoverImage;
    arrowDownPressImage = arrowDownLightPressImage;

    listItems = new QList<ListItem *>();
    renderItems = new QList<ListItem *>();
    selectionItems = new QList<ListItem *>();
    lastSelectItem = NULL;
    lastHoverItem = NULL;
    lastHoverColumnIndex = -1;

    mouseAtScrollArea = false;
    mouseDragScrollbar = false;
    scrollbarDefaultWidth = 4;
    scrollbarDragWidth = 8;
    scrollbarMinHeight = 30;
    scrollbarPadding = 4;
    hideScrollbarDuration = 2000;

    oldRenderOffset = 0;
    clipRadius = 8;

    hideScrollbarTimer = NULL;

    sortingAlgorithms = new QList<SortAlgorithm>();
    sortingOrderes = new QList<bool>();
}

ListView::~ListView() {
    delete lastHoverItem;
    delete lastSelectItem;
    delete listItems;
    delete renderItems;
    delete selectionItems;
    delete sortingAlgorithms;
    delete sortingOrderes;
    delete hideScrollbarTimer;
    delete scrollAnimationTimer;
}

void ListView::setRowHeight(int height) {
    rowHeight = height;
    scrollUnit = rowHeight * 9;
}

void ListView::setColumnTitleInfo(QList<QString> titles, QList<int> widths, int height) {
    // Set column titles.
    columnTitles = titles;

    // Calcuate column title widths.
    columnWidths.clear();
    QFont font;
    font.setPointSize(titleSize);
    QFontMetrics fm(font);

    for (int i = 0; i < widths.length(); i++) {
        if (widths[i] == -1) {
            columnWidths << widths[i];
        } else {
            int renderTitleWidth =
                    fm.width(titles[i]) + titlePadding + arrowUpNormalImage.width() + titleArrowPadding * 2;
            columnWidths << std::max(widths[i], renderTitleWidth);
        }
    }

    // Set title height.
    titleHeight = height;
}

void ListView::setColumnHideFlags(QList<bool> toggleHideFlags, int visibleColumnIndex) {
//    Q_ASSERT_X(toggleHideFlags.contains(false), "toggleHideFlags", "at least have one 'false' in list.");
    Q_ASSERT_X(toggleHideFlags.count() == columnTitles.count(), "toggleHideFlags",
               "hide flags length is not same as titles list.");

    alwaysVisibleColumn = visibleColumnIndex;

    columnVisibles.clear();
    for (int i = 0; i < toggleHideFlags.count(); i++) {
        columnVisibles.append(toggleHideFlags[i]);
    }
}

void ListView::setColumnSortingAlgorithms(QList<SortAlgorithm> *algorithms, int sortColumn, bool descendingSort) {
    // Add sort algorithms.
    sortingAlgorithms = algorithms;

    for (int i = 0; i < sortingAlgorithms->count(); i++) {
        sortingOrderes->append(false);
    }

    // If sort column is -1, don't sort default.
    defaultSortingColumn = sortColumn;
    defaultSortingOrder = descendingSort;
}

void ListView::setSearchAlgorithm(SearchAlgorithm algorithm) {
    searchAlgorithm = algorithm;
}

void ListView::setClipRadius(int radius) {
    clipRadius = radius;
}


void ListView::addItems(QList<ListItem *> items) {
    // Add item to list.
    listItems->append(items);
    QList<ListItem *> searchItems = getSearchItems(items);
    renderItems->append(searchItems);

    // If user has click title to sort, sort items after add items to list.
    if (defaultSortingColumn != -1) {
        sortItemsByColumn(defaultSortingColumn, defaultSortingOrder);
    }
}

void ListView::clearItems() {
    // NOTE:
    // We need delete items in QList before clear QList to avoid *MEMORY LEAK* .
    qDeleteAll(listItems->begin(), listItems->end());
    listItems->clear();
    renderItems->clear();
}

void ListView::addSelections(QList<ListItem *> items, bool recordLastSelection) {
    // Add item to selection list.
    selectionItems->append(items);

    // Record last selection item to make selected operation continuously.
    if (recordLastSelection && selectionItems->count() > 0) {
        lastSelectItem = selectionItems->last();
    }
}

void ListView::clearSelections(bool clearLastSelection) {
    // Clear selection list.
    selectionItems->clear();

    if (clearLastSelection) {
        lastSelectItem = NULL;
    }
}

void ListView::refreshItems(QList<ListItem *> items) {
    // Init.
    QList<ListItem *> *newSelectionItems = new QList<ListItem *>();
    ListItem *newLastSelectionItem = NULL;
    ListItem *newLastHoverItem = NULL;

    // Save selection items and last selection item.
    for (ListItem *item:items) {
        for (ListItem *selectionItem:*selectionItems) {
            if (item->sameAs(selectionItem)) {
                newSelectionItems->append(item);
                break;
            }
        }
    }

    if (lastSelectItem != NULL) {
        for (ListItem *item:items) {
            if (item->sameAs(lastSelectItem)) {
                newLastSelectionItem = item;
                break;
            }
        }
    }

    if (lastHoverItem != NULL) {
        for (ListItem *item:items) {
            if (item->sameAs(lastHoverItem)) {
                newLastHoverItem = item;
                break;
            }
        }
    }
    lastHoverItem = NULL;

    // Update items.
    clearItems();
    listItems->append(items);
    QList<ListItem *> searchItems = getSearchItems(items);
    renderItems->append(searchItems);

    // Sort once if default sort column hasn't init.
    if (defaultSortingColumn != -1) {
        sortItemsByColumn(defaultSortingColumn, defaultSortingOrder);
    }

    // Restore selection items and last selection item.
    clearSelections();
    addSelections(*newSelectionItems, false);
    lastSelectItem = newLastSelectionItem;
    lastHoverItem = newLastHoverItem;

    // Keep scroll position.
    renderOffset = adjustRenderOffset(renderOffset);

    // Render.
    repaint();
}

void ListView::search(QString content) {
    if (content == "" && searchContent != content) {
        searchContent = content;

        renderItems->clear();
        renderItems->append(*listItems);
    } else {
        searchContent = content;

        QList<ListItem *> searchItems = getSearchItems(*listItems);
        renderItems->clear();
        renderItems->append(searchItems);
    }

    repaint();
}

void ListView::selectAllItems() {
    // Record old render offset to control scrollbar whether display.
    oldRenderOffset = renderOffset;

    // Select all items.
    clearSelections();
    addSelections(*renderItems);

    // Scroll to top.
    renderOffset = getTopRenderOffset();

    // Repaint.
    repaint();
}

void ListView::selectFirstItem() {
    // Record old render offset to control scrollbar whether display.
    oldRenderOffset = renderOffset;

    // Select first item.
    clearSelections();

    QList<ListItem *> items = QList<ListItem *>();
    items << renderItems->first();
    addSelections(items);

    // Scroll to top.
    renderOffset = getTopRenderOffset();

    // Repaint.
    repaint();
}

void ListView::selectLastItem() {
    // Record old render offset to control scrollbar whether display.
    oldRenderOffset = renderOffset;

    // Select last item.
    clearSelections();

    QList<ListItem *> items = QList<ListItem *>();
    items << renderItems->last();
    addSelections(items);

    // Scroll to bottom.
    renderOffset = getBottomRenderOffset();

    // Repaint.
    repaint();
}

void ListView::selectPrevItem() {
    selectPrevItemWithOffset(1);
}

void ListView::selectNextItem() {
    selectNextItemWithOffset(1);
}

void ListView::shiftSelectPageDown() {
    shiftSelectNextItemWithOffset(getScrollAreaHeight() / rowHeight);
}

void ListView::shiftSelectPageUp() {
    shiftSelectPrevItemWithOffset(getScrollAreaHeight() / rowHeight);
}

void ListView::shiftSelectToEnd() {
    // Select last item if nothing selected yet.
    if (selectionItems->empty()) {
        selectLastItem();
    }
        // Select items from last selected item to last item.
    else {
        // Found last selected index and do select operation.
        int lastSelectionIndex = renderItems->indexOf(lastSelectItem);
        shiftSelectItemsWithBound(lastSelectionIndex, renderItems->count() - 1);

        // Scroll to bottom.
        renderOffset = getBottomRenderOffset();

        // Repaint.
        repaint();
    }
}

void ListView::shiftSelectToHome() {
    // Select first item if nothing selected yet.
    if (selectionItems->empty()) {
        selectFirstItem();
    }
        // Select items from last selected item to first item.
    else {
        // Found last selected index and do select operation.
        int lastSelectionIndex = renderItems->indexOf(lastSelectItem);
        shiftSelectItemsWithBound(0, lastSelectionIndex);

        // Scroll to top.
        renderOffset = getTopRenderOffset();

        // Repaint.
        repaint();
    }
}

void ListView::shiftSelectToNext() {
    shiftSelectNextItemWithOffset(1);
}

void ListView::shiftSelectToPrev() {
    shiftSelectPrevItemWithOffset(1);
}

void ListView::scrollPageDown() {
    selectNextItemWithOffset(getScrollAreaHeight() / rowHeight);
}

void ListView::scrollPageUp() {
    selectPrevItemWithOffset(getScrollAreaHeight() / rowHeight);
}

void ListView::ctrlScrollPageUp() {
    renderOffset = adjustRenderOffset(renderOffset - getScrollAreaHeight());

    repaint();
}

void ListView::ctrlScrollPageDown() {
    renderOffset = adjustRenderOffset(renderOffset + getScrollAreaHeight());

    repaint();
}

void ListView::ctrlScrollToHome() {
    renderOffset = getTopRenderOffset();

    repaint();
}

void ListView::ctrlScrollToEnd() {
    renderOffset = getBottomRenderOffset();

    repaint();
}

void ListView::leaveEvent(QEvent *event) {
    hideScrollbar();

    QWidget::leaveEvent(event);
}

void ListView::scrollAnimation() {
    if (scrollAnimationTicker <= scrollAnimationFrames) {
        renderOffset = adjustRenderOffset(
                scrollStartY + Util::easeInOut(scrollAnimationTicker / (scrollAnimationFrames * 1.0)) * scrollDistance);

        repaint();

        scrollAnimationTicker++;
    } else {
        scrollAnimationTimer->stop();
    }
}

void ListView::hideScrollbar() {
    // Record old render offset to control scrollbar whether display.
    mouseAtScrollArea = false;
    oldRenderOffset = renderOffset;

    repaint();
}

bool ListView::eventFilter(QObject *, QEvent *) {
    return false;
}

void ListView::keyPressEvent(QKeyEvent *keyEvent) {
    if (keyEvent->key() == Qt::Key_Home) {
        if (keyEvent->modifiers() == Qt::ControlModifier) {
            ctrlScrollToHome();
        } else if (keyEvent->modifiers() == Qt::ShiftModifier) {
            shiftSelectToHome();
        } else {
            selectFirstItem();
        }
    } else if (keyEvent->key() == Qt::Key_End) {
        if (keyEvent->modifiers() == Qt::ControlModifier) {
            ctrlScrollToEnd();
        } else if (keyEvent->modifiers() == Qt::ShiftModifier) {
            shiftSelectToEnd();
        } else {
            selectLastItem();
        }
    } else if (keyEvent->key() == Qt::Key_Up) {
        if (keyEvent->modifiers() == Qt::ShiftModifier) {
            shiftSelectToPrev();
        } else {
            selectPrevItem();
        }
    } else if (keyEvent->key() == Qt::Key_Down) {
        if (keyEvent->modifiers() == Qt::ShiftModifier) {
            shiftSelectToNext();
        } else {
            selectNextItem();
        }
    } else if (keyEvent->key() == Qt::Key_PageUp) {
        if (keyEvent->modifiers() == Qt::ControlModifier) {
            ctrlScrollPageUp();
        } else if (keyEvent->modifiers() == Qt::ShiftModifier) {
            shiftSelectPageUp();
        } else {
            scrollPageUp();
        }
    } else if (keyEvent->key() == Qt::Key_PageDown) {
        if (keyEvent->modifiers() == Qt::ControlModifier) {
            ctrlScrollPageDown();
        } else if (keyEvent->modifiers() == Qt::ShiftModifier) {
            shiftSelectPageDown();
        } else {
            scrollPageDown();
        }
    } else if (keyEvent->key() == Qt::Key_A) {
        if (keyEvent->modifiers() == Qt::ControlModifier) {
            selectAllItems();
        }
    }
}

void ListView::mouseMoveEvent(QMouseEvent *mouseEvent) {
    // Scroll if mouse drag at scrollbar.
    if (mouseDragScrollbar) {
        int barHeight = getScrollbarHeight();
        renderOffset = adjustRenderOffset(
                (mouseEvent->y() - barHeight / 2 - titleHeight) / (getScrollAreaHeight() * 1.0) *
                getItemsTotalHeight());

        repaint();
    }
        // Update scrollbar status with mouse position.
    else if (isMouseAtScrollArea(mouseEvent->x()) != mouseAtScrollArea) {
        mouseAtScrollArea = isMouseAtScrollArea(mouseEvent->x());
        repaint();
    }
        // Otherwise to check titlebar arrow status.
    else {
        bool atTitleArea = isMouseAtTitleArea(mouseEvent->y());

        if (atTitleArea) {
            int hoverColumn = -1;

            if (sortingAlgorithms->count() != 0 && sortingAlgorithms->count() == columnTitles.count() &&
                sortingOrderes->count() == columnTitles.count()) {
                // Calcuate title widths;
                QList<int> renderWidths = getRenderWidths();

                int columnCounter = 0;
                int columnRenderX = 0;
                for (int renderWidth:renderWidths) {
                    if (renderWidth > 0) {
                        if (mouseEvent->x() > columnRenderX && mouseEvent->x() < columnRenderX + renderWidth) {
                            hoverColumn = columnCounter;

                            break;
                        }

                        columnRenderX += renderWidth;
                    }

                    columnCounter++;
                }
            }

            if (hoverColumn != titleHoverColumn) {
                titleHoverColumn = hoverColumn;

                repaint();
            }
        } else {
            int hoverItemIndex = (renderOffset + mouseEvent->y() - titleHeight) / rowHeight;

            // NOTE: hoverItemIndex may be less than 0, we need check index here.
            if (hoverItemIndex >= 0 && hoverItemIndex < (*renderItems).length()) {
                ListItem *item = (*renderItems)[hoverItemIndex];

                QList<int> renderWidths = getRenderWidths();

                int columnCounter = 0;
                int columnRenderX = 0;
                for (int renderWidth:renderWidths) {
                    if (renderWidth > 0) {
                        if (mouseEvent->x() > columnRenderX && mouseEvent->x() < columnRenderX + renderWidth) {
                            break;
                        }

                        columnRenderX += renderWidth;
                    }

                    columnCounter++;
                }

                if (lastHoverItem == NULL || !item->sameAs(lastHoverItem) || columnCounter != lastHoverColumnIndex) {
                    lastHoverItem = item;
                    lastHoverColumnIndex = columnCounter;

                    changeHoverItem(this->mapToGlobal(mouseEvent->pos()), lastHoverItem, columnCounter);
                }
            }
        }
    }
}

void ListView::mousePressEvent(QMouseEvent *mouseEvent) {
    setFocus();

    bool atTitleArea = isMouseAtTitleArea(mouseEvent->y());
    bool atScrollArea = isMouseAtScrollArea(mouseEvent->x());

    // Sort items with column's sorting algorithms when click on title area.
    if (atTitleArea) {
        if (mouseEvent->button() == Qt::LeftButton) {
            if (sortingAlgorithms->count() != 0 && sortingAlgorithms->count() == columnTitles.count() &&
                sortingOrderes->count() == columnTitles.count()) {
                // Calcuate title widths;
                QList<int> renderWidths = getRenderWidths();

                int columnCounter = 0;
                int columnRenderX = 0;
                for (int renderWidth:renderWidths) {
                    if (renderWidth > 0) {
                        if (mouseEvent->x() > columnRenderX && mouseEvent->x() < columnRenderX + renderWidth) {
                            // If switch other column, default order is from top to bottom.
                            if (columnCounter != defaultSortingColumn) {
                                (*sortingOrderes)[columnCounter] = true;
                            }
                                // If user click same column, just switch reverse order.
                            else {
                                (*sortingOrderes)[columnCounter] = !(*sortingOrderes)[columnCounter];
                            }

                            defaultSortingColumn = columnCounter;
                            defaultSortingOrder = (*sortingOrderes)[columnCounter];

                            changeSortingStatus(defaultSortingColumn, defaultSortingOrder);

                            sortItemsByColumn(columnCounter, (*sortingOrderes)[columnCounter]);

                            if (columnCounter != titlePressColumn) {
                                titlePressColumn = columnCounter;
                            }

                            repaint();
                            break;
                        }

                        columnRenderX += renderWidth;
                    }

                    columnCounter++;
                }
            }
        } else if (mouseEvent->button() == Qt::RightButton) {
            if (columnVisibles.count() == columnTitles.count()) {
                QMenu *menu = new QMenu();
                menu->setStyle(QStyleFactory::create("dlight"));

                for (int i = 0; i < columnVisibles.count(); i++) {
                    if (i != alwaysVisibleColumn) {
                        QAction *action = new QAction(menu);
                        action->setText(columnTitles[i]);

                        action->setCheckable(true);
                        action->setChecked(columnVisibles[i]);

                        connect(action, &QAction::triggered, this, [this, action, i] {
                            columnVisibles[i] = !columnVisibles[i];

                            changeColumnVisible(i, columnVisibles[i], columnVisibles);

                            repaint();
                        });

                        menu->addAction(action);
                    }
                }

                menu->exec(this->mapToGlobal(mouseEvent->pos()));
            }
        }
    }
        // Scroll when click on scrollbar area.
    else if (atScrollArea) {
        int barHeight = getScrollbarHeight();
        int barY = getScrollbarY();

        // Flag mouseDragScrollbar when click on scrollbar.
        if (mouseEvent->y() > barY && mouseEvent->y() < barY + barHeight) {
            mouseDragScrollbar = true;
        }
            // Scroll if click out of scrollbar area.
        else {
            renderOffset = adjustRenderOffset(
                    (mouseEvent->y() - barHeight / 2 - titleHeight) / (getScrollAreaHeight() * 1.0) *
                    getItemsTotalHeight());
            repaint();
        }
    }
        // Select items.
    else {
        int pressItemIndex = (renderOffset + mouseEvent->y() - titleHeight) / rowHeight;
        if (mouseEvent->button() == Qt::LeftButton) {
            if (pressItemIndex < renderItems->count()) {
                // Scattered selection of items when press ctrl modifier.
                if (mouseEvent->modifiers() == Qt::ControlModifier) {
                    ListItem *item = (*renderItems)[pressItemIndex];

                    if (selectionItems->contains(item)) {
                        selectionItems->removeOne(item);
                    } else {
                        QList<ListItem *> items = QList<ListItem *>();
                        items << item;
                        addSelections(items);
                    }
                }
                    // Continuous selection of items when press shift modifier.
                else if ((mouseEvent->modifiers() == Qt::ShiftModifier) && !selectionItems->empty()) {
                    int lastSelectionIndex = renderItems->indexOf(lastSelectItem);
                    int selectionStartIndex = std::min(pressItemIndex, lastSelectionIndex);
                    int selectionEndIndex = std::max(pressItemIndex, lastSelectionIndex);

                    shiftSelectItemsWithBound(selectionStartIndex, selectionEndIndex);
                }
                    // Just select item under mouse if user not press any modifier.
                else {
                    clearSelections();

                    QList<ListItem *> items = QList<ListItem *>();
                    items << (*renderItems)[pressItemIndex];
                    addSelections(items);
                }

                repaint();
            }
        } else if (mouseEvent->button() == Qt::RightButton) {
            ListItem *pressItem = (*renderItems)[pressItemIndex];
            bool pressInSelectionArea = false;

            for (ListItem *item : *selectionItems) {
                if (item == pressItem) {
                    pressInSelectionArea = true;

                    break;
                }
            }

            if (!pressInSelectionArea && pressItemIndex < renderItems->length()) {
                clearSelections();

                QList<ListItem *> items = QList<ListItem *>();
                items << (*renderItems)[pressItemIndex];
                addSelections(items);

                repaint();
            }

            if (selectionItems->length() > 0) {
                rightClickItems(this->mapToGlobal(mouseEvent->pos()), *selectionItems);
            }
        }
    }
}

void ListView::mouseReleaseEvent(QMouseEvent *) {
    if (mouseDragScrollbar) {
        // Reset mouseDragScrollbar.
        mouseDragScrollbar = false;

        repaint();
    } else {
        if (titlePressColumn != -1) {
            titlePressColumn = -1;
            repaint();
        }
    }
}

void ListView::wheelEvent(QWheelEvent *event) {
    if (event->orientation() == Qt::Vertical) {
        // Record old render offset to control scrollbar whether display.
        oldRenderOffset = renderOffset;

        int scrollStep = event->angleDelta().y() / 120;
        int newRenderOffset = renderOffset - scrollStep * scrollUnit;
        newRenderOffset = adjustRenderOffset(newRenderOffset);

        if (newRenderOffset != renderOffset) {
            // If timer is inactive, start scroll timer.
            if (scrollAnimationTimer == NULL || !scrollAnimationTimer->isActive()) {
                scrollStartY = renderOffset;
                scrollDistance = newRenderOffset - renderOffset;

                startScrollAnimation();
            }
                // If timer is active, just add scroll offset make scroll faster and *smooth*.
            else {
                scrollDistance -= scrollStep * rowHeight;
            }
        }
    }

    event->accept();
}

void ListView::paintEvent(QPaintEvent *) {
    // Init.
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Calcuate title widths;
    QList<int> renderWidths = getRenderWidths();

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setOpacity(0.05);

    int penWidth = 1;
    QPainterPath clipPath;
    clipPath.addRoundedRect(QRect(rect().x() + penWidth, rect().y() + penWidth, rect().width() - penWidth * 2,
                                  rect().height() - penWidth * 2), clipRadius, clipRadius);
    painter.setClipPath(clipPath);

    // Draw title.
    QPainterPath titlePath;
    titlePath.addRect(QRectF(rect().x(), rect().y(), rect().width(), titleHeight));
    painter.setOpacity(titleAreaOpacity);
    painter.fillPath(titlePath, QColor(titleAreaColor));

    int renderY = 0;
    int renderHeight = 0;
    if (titleHeight > 0) {
        int columnCounter = 0;
        int columnRenderX = 0;
        for (int renderWidth:renderWidths) {
            if (renderWidth > 0) {
                painter.setOpacity(1);
                Util::setFontSize(painter, titleSize);
                painter.setPen(QPen(QColor(titleColor)));
                painter.drawText(QRect(columnRenderX + titlePadding, 0, renderWidth, titleHeight),
                                 Qt::AlignVCenter | Qt::AlignLeft, columnTitles[columnCounter]);

                columnRenderX += renderWidth;

                if (columnCounter < renderWidths.size() - 1) {
                    painter.setOpacity(0.05);
                    QPainterPath separatorPath;
                    separatorPath.addRect(QRectF(rect().x() + columnRenderX - 1, rect().y() + 4, 1, titleHeight - 8));
                    painter.fillPath(separatorPath, QColor(titleLineColor));
                }

                // Draw sort arrow.
                if (defaultSortingColumn == columnCounter) {
                    painter.setOpacity(1);
                    int arrowX = rect().x() + columnRenderX - titleArrowPadding - arrowUpNormalImage.width();
                    int arrowY = rect().y() + (titleHeight - arrowDownNormalImage.height()) / 2;

                    if (defaultSortingOrder) {
                        if (titlePressColumn == defaultSortingColumn) {
                            painter.drawImage(QPoint(arrowX, arrowY), arrowDownPressImage);
                        } else if (titleHoverColumn == defaultSortingColumn) {
                            painter.drawImage(QPoint(arrowX, arrowY), arrowDownHoverImage);
                        } else {
                            painter.drawImage(QPoint(arrowX, arrowY), arrowDownNormalImage);
                        }
                    } else {
                        if (titlePressColumn == defaultSortingColumn) {
                            painter.drawImage(QPoint(arrowX, arrowY), arrowUpPressImage);
                        } else if (titleHoverColumn == defaultSortingColumn) {
                            painter.drawImage(QPoint(arrowX, arrowY), arrowUpHoverImage);
                        } else {
                            painter.drawImage(QPoint(arrowX, arrowY), arrowUpNormalImage);
                        }
                    }
                }
            }
            columnCounter++;
        }

        renderY += titleHeight;
        renderHeight += titleHeight;
    }

    // Draw background.
    painter.setOpacity(backgroundOpacity);
    QPainterPath backgroundPath;
    backgroundPath.addRect(QRectF(rect().x(), rect().y() + titleHeight, rect().width(), rect().height() - titleHeight));
    painter.fillPath(backgroundPath, QColor(backgroundColor));

    // Draw context.
    QPainterPath scrollAreaPath;
    scrollAreaPath.addRect(QRectF(rect().x(), rect().y() + titleHeight, rect().width(), getScrollAreaHeight()));

    int rowCounter = 0;
    for (ListItem *item:*renderItems) {
        if (rowCounter > ((renderOffset - rowHeight) / rowHeight)) {
            // Clip item rect.
            QPainterPath itemPath;
            itemPath.addRect(QRect(0, renderY + rowCounter * rowHeight - renderOffset, rect().width(), rowHeight));
            painter.setClipPath((clipPath.intersected(scrollAreaPath)).intersected(itemPath));

            // Draw item backround.
            bool isSelect = selectionItems->contains(item);
            item->drawBackground(QRect(0, renderY + rowCounter * rowHeight - renderOffset, rect().width(), rowHeight),
                                 &painter, rowCounter, isSelect);

            // Draw item foreground.
            int columnCounter = 0;
            int columnRenderX = 0;
            for (int renderWidth:renderWidths) {
                if (renderWidth > 0) {
                    item->drawForeground(
                            QRect(columnRenderX, renderY + rowCounter * rowHeight - renderOffset, renderWidth,
                                  rowHeight), &painter, columnCounter, rowCounter, isSelect);

                    columnRenderX += renderWidth;
                }
                columnCounter++;
            }

            renderHeight += rowHeight;

            if (renderHeight > rect().height()) {
                break;
            }
        }

        rowCounter++;
    }

    // Keep clip area.
    painter.setClipPath(clipPath);

    // Draw search tooltip.
    if (searchContent != "" && renderItems->size() == 0) {
        painter.setOpacity(1);
        painter.setPen(QPen(QColor(searchColor)));
        Util::setFontSize(painter, 20);
        painter.drawText(QRect(rect().x(), rect().y() + titleHeight, rect().width(), rect().height() - titleHeight),
                         Qt::AlignCenter, tr("No search result"));
    }

    // Draw frame.
    QPainterPath framePath;
    framePath.addRoundedRect(QRect(rect().x() + penWidth, rect().y() + penWidth, rect().width() - penWidth * 2,
                                   rect().height() - penWidth * 2), clipRadius, clipRadius);

    QPen framePen;
    framePen.setColor(frameColor);

    painter.setOpacity(frameOpacity);
    painter.drawPath(framePath);

    // Draw scrollbar.
    if (mouseAtScrollArea) {
        paintScrollbar(&painter);
    } else if (oldRenderOffset != renderOffset) {
        paintScrollbar(&painter);

        startScrollbarHideTimer();
    }
}

void ListView::paintScrollbar(QPainter *painter) {
    if (getItemsTotalHeight() > getScrollAreaHeight()) {
        // Init scrollbar opacity with scrollbar status.
        qreal barOpacitry = 0;
        qreal barFrameOpacitry = 0;

        // Press.
        if (mouseDragScrollbar) {
            barOpacitry = scrollbarPressOpacity;
            barFrameOpacitry = scrollbarFramePressOpacity;
        } else {
            // Hover.
            if (mouseAtScrollArea) {
                barOpacitry = scrollbarHoverOpacity;
                barFrameOpacitry = scrollbarFrameHoverOpacity;
            }
                // Normal.
            else {
                barOpacitry = scrollbarNormalOpacity;
                barFrameOpacitry = scrollbarFrameNormalOpacity;
            }
        }

        int barWidth = (mouseAtScrollArea || mouseDragScrollbar) ? scrollbarDragWidth : scrollbarDefaultWidth;
        int barRadius = 4;

        int barY = getScrollbarY();
        int barHeight = getScrollbarHeight();

        painter->setOpacity(barOpacitry);
        QPainterPath path;
        path.addRoundedRect(
                QRectF(rect().x() + rect().width() - barWidth - scrollbarPadding,
                       barY + barRadius,
                       barWidth,
                       barHeight - barRadius * 2), barRadius, barRadius);
        painter->fillPath(path, QColor(scrollbarColor));

        QPen pen;
        pen.setColor(QColor(scrollbarColor));
        pen.setWidth(1);
        painter->setOpacity(barFrameOpacitry);
        painter->setPen(pen);
        painter->drawPath(path);
    }
}

void ListView::selectNextItemWithOffset(int scrollOffset) {
    // Record old render offset to control scrollbar whether display.
    oldRenderOffset = renderOffset;

    if (selectionItems->empty()) {
        selectFirstItem();
    } else {
        int lastIndex = 0;
        for (ListItem *item:*selectionItems) {
            int index = renderItems->indexOf(item);
            if (index > lastIndex) {
                lastIndex = index;
            }
        }

        if (lastIndex != -1) {
            lastIndex = std::min(renderItems->count() - 1, lastIndex + scrollOffset);

            clearSelections(false);

            QList<ListItem *> items = QList<ListItem *>();
            items << (*renderItems)[lastIndex];

            addSelections(items);

            int itemIndex = lastIndex + 1;
            int itemOffset = adjustRenderOffset(itemIndex * rowHeight - rect().height() + titleHeight);
            if (((renderOffset + getScrollAreaHeight()) / rowHeight) < itemIndex) {
                renderOffset = itemOffset;
            }

            repaint();
        }
    }
}

void ListView::selectPrevItemWithOffset(int scrollOffset) {
    // Record old render offset to control scrollbar whether display.
    oldRenderOffset = renderOffset;

    if (selectionItems->empty()) {
        selectFirstItem();
    } else {
        int firstIndex = renderItems->count();
        for (ListItem *item:*selectionItems) {
            int index = renderItems->indexOf(item);
            if (index < firstIndex) {
                firstIndex = index;
            }
        }

        if (firstIndex != -1) {
            firstIndex = std::max(0, firstIndex - scrollOffset);

            clearSelections();

            QList<ListItem *> items = QList<ListItem *>();
            items << (*renderItems)[firstIndex];

            addSelections(items);

            int itemIndex = firstIndex - 1;
            int itemOffset = adjustRenderOffset(itemIndex * rowHeight + titleHeight);
            if ((renderOffset / rowHeight) > itemIndex) {
                renderOffset = itemOffset;
            }

            repaint();
        }
    }
}

void ListView::shiftSelectItemsWithBound(int selectionStartIndex, int selectionEndIndex) {
    // Note: Shift operation always selection bound from last selection index to current index.
    // So we don't need *clear* lastSelectionIndex for keep shift + button is right logic.
    clearSelections(false);
    QList<ListItem *> items = QList<ListItem *>();
    int index = 0;
    for (ListItem *item:*renderItems) {
        if (index >= selectionStartIndex && index <= selectionEndIndex) {
            items << item;
        }

        index++;
    }

    // Note: Shift operation always selection bound from last selection index to current index.
    // So we don't need *record* lastSelectionIndex for keep shift + button is right logic.
    addSelections(items, false);
}

void ListView::shiftSelectPrevItemWithOffset(int scrollOffset) {
    // Record old render offset to control scrollbar whether display.
    oldRenderOffset = renderOffset;

    if (selectionItems->empty()) {
        selectFirstItem();
    } else {
        int firstIndex = renderItems->count();
        int lastIndex = 0;
        for (ListItem *item:*selectionItems) {
            int index = renderItems->indexOf(item);

            if (index < firstIndex) {
                firstIndex = index;
            }

            if (index > lastIndex) {
                lastIndex = index;
            }
        }

        if (firstIndex != -1) {
            int lastSelectionIndex = renderItems->indexOf(lastSelectItem);
            int selectionStartIndex, selectionEndIndex;

            if (lastIndex == lastSelectionIndex) {
                selectionStartIndex = std::max(0, firstIndex - scrollOffset);
                selectionEndIndex = lastSelectionIndex;
            } else {
                selectionStartIndex = firstIndex;
                selectionEndIndex = std::max(0, lastIndex - scrollOffset);
            }

            shiftSelectItemsWithBound(selectionStartIndex, selectionEndIndex);

            renderOffset = adjustRenderOffset((selectionStartIndex - 1) * rowHeight + titleHeight);

            repaint();
        }
    }
}

void ListView::shiftSelectNextItemWithOffset(int scrollOffset) {
    // Record old render offset to control scrollbar whether display.
    oldRenderOffset = renderOffset;

    if (selectionItems->empty()) {
        selectFirstItem();
    } else {
        int firstIndex = renderItems->count();
        int lastIndex = 0;
        for (ListItem *item:*selectionItems) {
            int index = renderItems->indexOf(item);

            if (index < firstIndex) {
                firstIndex = index;
            }

            if (index > lastIndex) {
                lastIndex = index;
            }
        }

        if (firstIndex != -1) {
            int lastSelectionIndex = renderItems->indexOf(lastSelectItem);
            int selectionStartIndex, selectionEndIndex;

            if (firstIndex == lastSelectionIndex) {
                selectionStartIndex = firstIndex;
                selectionEndIndex = std::min(renderItems->count() - 1, lastIndex + scrollOffset);
            } else {
                selectionStartIndex = std::min(renderItems->count() - 1, firstIndex + scrollOffset);
                selectionEndIndex = lastIndex;
            }

            shiftSelectItemsWithBound(selectionStartIndex, selectionEndIndex);

            renderOffset = adjustRenderOffset((selectionEndIndex + 1) * rowHeight + titleHeight - rect().height());

            repaint();
        }
    }
}

QList<int> ListView::getRenderWidths() {
    QList<int> renderWidths;
    if (columnWidths.contains(-1)) {
        for (int i = 0; i < columnWidths.count(); i++) {
            if (columnWidths[i] != -1) {
                if (columnVisibles[i]) {
                    renderWidths << columnWidths[i];
                } else {
                    renderWidths << 0;
                }
            } else {
                if (columnVisibles[i]) {
                    int totalWidthOfOtherColumns = 0;

                    for (int j = 0; j < columnWidths.count(); j++) {
                        if (columnWidths[j] != -1 && columnVisibles[j]) {
                            totalWidthOfOtherColumns += columnWidths[j];
                        }
                    }

                    renderWidths << rect().width() - totalWidthOfOtherColumns;
                } else {
                    renderWidths << 0;
                }
            }
        }
    } else {
        for (int i = 0; i < columnWidths.count(); i++) {
            if (columnVisibles[i]) {
                renderWidths << columnWidths[i];
            } else {
                renderWidths << 0;
            }
        }
    }

    return renderWidths;
}

bool ListView::isMouseAtScrollArea(int x) {
    return (x > rect().x() + rect().width() - scrollbarDragWidth) && (x < rect().x() + rect().width());
}

bool ListView::isMouseAtTitleArea(int y) {
    return (y > rect().y() && y < rect().y() + titleHeight);
}

int ListView::adjustRenderOffset(int offset) {
    return std::max(0, std::min(offset, getBottomRenderOffset()));
}

int ListView::getItemsTotalHeight() {
    return renderItems->count() * rowHeight;
}

int ListView::getScrollAreaHeight() {
    return rect().height() - titleHeight;
}

int ListView::getScrollbarY() {
    return static_cast<int>((renderOffset / (getItemsTotalHeight() * 1.0)) * getScrollAreaHeight() + titleHeight);
}

int ListView::getScrollbarHeight() {
    return std::max(static_cast<int>(getScrollAreaHeight() / (getItemsTotalHeight() * 1.0) * rect().height()),
                    scrollbarMinHeight);
}

int ListView::getTopRenderOffset() {
    return 0;
}

QList<ListItem *> ListView::getSearchItems(QList<ListItem *> items) {
    if (searchContent == "" || searchAlgorithm == NULL) {
        return items;
    } else {
        QList<ListItem *> *searchItems = new QList<ListItem *>();

        for (ListItem *item : items) {
            if (searchAlgorithm(item, searchContent)) {
                searchItems->append(item);
            }
        }

        return *searchItems;
    }
}

int ListView::getBottomRenderOffset() {
    int itemsHeight = getItemsTotalHeight();
    if (itemsHeight > rect().height() - titleHeight) {
        return getItemsTotalHeight() - rect().height() + titleHeight;
    } else {
        return 0;
    }
}

void ListView::sortItemsByColumn(int column, bool descendingSort) {
    if (sortingAlgorithms->count() != 0 && sortingAlgorithms->count() == columnTitles.count() &&
        sortingOrderes->count() == columnTitles.count()) {
        qSort(renderItems->begin(), renderItems->end(), [&](const ListItem *item1, const ListItem *item2) {
            return (*sortingAlgorithms)[column](item1, item2, descendingSort);
        });
    }
}

void ListView::startScrollAnimation() {
    if (scrollAnimationTimer == NULL || !scrollAnimationTimer->isActive()) {
        scrollAnimationTicker = 0;
        scrollAnimationTimer = new QTimer();
        connect(scrollAnimationTimer, SIGNAL(timeout()), this, SLOT(scrollAnimation()));
        scrollAnimationTimer->start(scrollAnimationDuration);
    }
}

void ListView::startScrollbarHideTimer() {
    if (hideScrollbarTimer != NULL) {
        hideScrollbarTimer->stop();
    }

    hideScrollbarTimer = new QTimer();
    connect(hideScrollbarTimer, SIGNAL(timeout()), this, SLOT(hideScrollbar()));
    hideScrollbarTimer->start(hideScrollbarDuration);
}
