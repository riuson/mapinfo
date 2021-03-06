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

#include "mapscontroller.h"
#include "maps.h"
#include "mapitem.h"

MapsController::MapsController(Maps *maps, QObject *parent) :
    QObject(parent)
{
    this->mMaps = maps;
    this->mLastIndex = -1;
    this->mFixed = false;
}

void MapsController::init()
{
    const QImage *image = this->mMaps->mainMap();
    emit this->imageChanged(image);
}

void MapsController::applyMap(int index)
{
    const QImage *imageMap = this->mMaps->mainMap();
    QString info;

    if (index >= 0)
    {
        const MapItem *item = this->mMaps->item(index);
        imageMap = item->masked();
        info = *item->info();
    }

    emit this->imageChanged(imageMap);
    emit this->infoChanged(info);
}

void MapsController::mouseMoving(int x, int y)
{
    if (!this->mFixed)
    {
        int index = this->mMaps->indexByPoint(x, y);
        if (index != this->mLastIndex)
        {
            this->mLastIndex = index;
            this->applyMap(index);
        }
    }
}

void MapsController::mouseReleased(int x, int y)
{
    int index = this->mMaps->indexByPoint(x, y);
    if (index != this->mLastIndex)
    {
        this->mLastIndex = index;
        this->applyMap(index);

        if (index >= 0)
        {
            this->mFixed = true;
        }
        else
        {
            this->mFixed = false;
        }
    }
    else
    {
        if (!this->mFixed && index >= 0)
        {
            this->mFixed = true;
        }
        else
        {
            this->mFixed = false;
        }
    }
}
