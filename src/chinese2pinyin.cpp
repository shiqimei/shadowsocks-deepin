// Copyright (c) 2015 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

// copy from deepin-system-monitor
#include "chinese2pinyin.h"

#include <QDebug>
#include <QHash>
#include <QTextStream>
#include <QFile>

namespace Pinyin {

    static QHash<uint, QString> dict = {};

    const char kDictFile[] = ":/misc/dict/pinyin.dict";

    void InitDict() {
        if (!dict.isEmpty()) {
            return;
        }

        dict.reserve(25333);

        QFile file(kDictFile);

        if (!file.open(QIODevice::ReadOnly)) {
            qCritical() << "open dict failed";
            return;
        }

        QByteArray content = file.readAll();

        file.close();

        QTextStream stream(&content, QIODevice::ReadOnly);

        while (!stream.atEnd()) {
            const QString line = stream.readLine();
            const QStringList items = line.split(QChar(':'));

            if (items.size() == 2) {
                dict.insert(items[0].toInt(nullptr, 16), items[1]);
            }
        }
    }

    QString Chinese2Pinyin(const QString& words) {
        InitDict();

        QString result;

        for (int i = 0; i < words.length(); ++i) {
            const uint key = words.at(i).unicode();
            auto find_result = dict.find(key);

            if (find_result != dict.end()) {
                result.append(find_result.value());
            } else {
                result.append(words.at(i));
            }
        }

        return result;
    }

    inline bool isAlphabeta(const QChar &c)
    {
        QRegExp re("[A-Za-z]*");
        return re.exactMatch(c);
    }

    inline bool isNumber(const QChar &c)
    {
        QRegExp re("[0-9]*");
        return re.exactMatch(c);
    }

    inline bool isChinese(const QChar &c)
    {
        return c.unicode() < 0x9FBF && c.unicode() > 0x4E00;
    }

    inline QString toChinesePinyin(const QString &c)
    {
        QString pinyin = Pinyin::Chinese2Pinyin(c);
        if (pinyin.length() >= 2
            && isNumber(pinyin.at(pinyin.length() - 1))) {
            return pinyin.left(pinyin.length() - 1);
        }
        return pinyin;
    }

    QStringList splitChineseToPinyin(QString &pinyin)
    {
        QStringList wordList;
        bool isLastAlphabeta = false;
        for (auto &c : pinyin) {
            bool isCurAlphabeta = isAlphabeta(c);
            if (isCurAlphabeta) {
                if (!isLastAlphabeta) {
                    wordList << c;
                } else {
                    wordList.last().append(c);
                }
                continue;
            }
            isLastAlphabeta = isCurAlphabeta;
            if (isNumber(c)) {
                wordList << c;
                continue;
            }
            if (isChinese(c)) {
                wordList << toChinesePinyin(c);
                continue;
            }
        }
        return wordList;
    }

    QStringList splitChinese(QString &pinyin)
    {
        QStringList wordList;
        bool isLastAlphabeta = false;
        for (auto &c : pinyin) {
            bool isCurAlphabeta = isAlphabeta(c);
            if (isCurAlphabeta) {
                if (!isLastAlphabeta) {
                    wordList << c;
                } else {
                    wordList.last().append(c);
                }
                continue;
            }
            isLastAlphabeta = isCurAlphabeta;
            if (isNumber(c)) {
                wordList << c;
                continue;
            }
            if (isChinese(c)) {
                wordList << c;
                continue;
            }
        }
        return wordList;
    }
}  // namespace Pinyin end
