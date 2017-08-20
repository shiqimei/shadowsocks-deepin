//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_LISTITEM_H
#define SHADOWSOCKS_CLIENT_LISTITEM_H


#include <QObject>
#include <QPainter>

class ListItem : public QObject {
Q_OBJECT

public:
    ListItem();

    /*
     * The interface function that used to compare the two ListItem
     * The ListView requires this interface to keep the selected items unchanged when refreshed
     *
     * @item any subclass of ListItem, you can use static_cast in implementation to access any attribute to compare two items
     * @return return true if two items have same attribute, the compare method implement by subclass of ListItem
     */
    virtual bool sameAs(ListItem *item)=0;

    /*
     * The interface function that used to draw background of ListItem.
     * Such as background and selected effect.
     *
     * @rect row corresponding to the drawing of the rectangular area
     * @painter the painter used to draw anything you want
     * @index the index of ListItem, you can draw different rows effect based on the index, such as the zebra crossing
     * @isSelect current item is selected, you can draw selected effect under content when isSelect is true
     */
    virtual void drawBackground(QRect rect, QPainter *painter, int index, bool isSelect)=0;

    /*
     * The interface function that used to draw foreground of ListItem.
     *
     * @rect column corresponding to the drawing of the rectangular area
     * @painter the painter used to draw anything you want
     * @column the column of ListItem, you can draw different column content based on the column index
     * @index the index of ListItem, you can draw different rows effect based on the index, such as the zebra crossing
     * @isSelect current item is selected, you can draw selected effect under content when isSelect is true
     */
    virtual void drawForeground(QRect rect, QPainter *painter, int column, int index, bool isSelect)=0;
};


#endif //SHADOWSOCKS_CLIENT_LISTITEM_H
