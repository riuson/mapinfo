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

#include "mapitem.h"
#include <QFile>
#include <QTextStream>
#include <QRgb>

MapItem::MapItem(QObject *parent) :
    QObject(parent)
{
}

MapItem::~MapItem()
{
}

bool MapItem::loadFiles(const QString &mask, const QString &masked, const QString &info)
{
    bool result = false;

    QFile file(info);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        this->mInfo = stream.readAll();
        file.close();

        result = this->mMask.load(mask);
        result &= this->mMasked.load(masked);
    }

    return result;
}

const QImage *MapItem::mask() const
{
    return &this->mMask;
}

const QImage *MapItem::masked() const
{
    return &this->mMasked;
}

const QString *MapItem::info() const
{
    return &this->mInfo;
}

bool MapItem::contains(int x, int y) const
{
    bool result = false;

    if (this->mMask.rect().contains(x, y))
    {
        QRgb pixelColor = this->mMask.pixel(x, y);
        // if transparent
        if (qAlpha(pixelColor) == 0)
        {
            result = true;
        }
    }

    return result;
}
