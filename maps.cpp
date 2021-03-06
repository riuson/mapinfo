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

#include "maps.h"
#include "mapitem.h"
#include "mapsloader.h"
#include <QDebug>

Maps::Maps(QObject *parent) :
    QObject(parent)
{
    this->mItems = new QList<MapItem *>();
    this->mMainMap = new QImage();

    MapsLoader loader;
    loader.load(this, this->mMainMap, this->mItems);
    qDebug() << this->mItems->length();
}

Maps::~Maps()
{
    qDeleteAll(*this->mItems);
    this->mItems->clear();
    delete this->mItems;

    delete this->mMainMap;
}

const MapItem *Maps::item(int index) const
{
    if (index < this->mItems->length())
    {
        return this->mItems->at(index);
    }
    return NULL;
}

int Maps::itemsCount() const
{
    return this->mItems->length();
}

const QImage *Maps::mainMap() const
{
    return this->mMainMap;
}

int Maps::indexByPoint(int x, int y) const
{
    int result = -1;

    for (int i = 0; i < this->mItems->length(); i++)
    {
        MapItem *item = this->mItems->at(i);
        if (item->contains(x, y))
        {
            result = i;
            break;
        }
    }

    return result;
}
