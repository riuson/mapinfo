/*
 * MapInfo. Shows info about map's regions.
 * Copyright (C) 2013 riuson
 * mailto: riuson@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/
 */

#ifndef MAPITEM_H
#define MAPITEM_H

#include <QObject>
#include <QImage>
#include <QString>

class MapItem : public QObject
{
    Q_OBJECT
public:
    explicit MapItem(QObject *parent = 0);
    ~MapItem();

    bool loadFiles(const QString &mask, const QString &masked, const QString &info);

    const QImage & mask() const;
    const QImage & masked() const;
    const QString & info() const;

    bool contains(int x, int y) const;

private:
    QImage mMask;
    QImage mMasked;
    QString mInfo;
};

#endif // MAPITEM_H
