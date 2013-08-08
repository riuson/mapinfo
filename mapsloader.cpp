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

#include "mapsloader.h"
#include <QApplication>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include "mapitem.h"

void MapsLoader::load(QObject *parent, QImage *mainMap, QList<MapItem *> *items)
{
    QDir appDir = QDir(QApplication::applicationDirPath());

    QDir mapDir = appDir;
    mapDir.cd("map");

    QFileInfo fileMainMap = QFileInfo(mapDir.absoluteFilePath("main.png"));
    mainMap->load(fileMainMap.absoluteFilePath());

    QFileInfoList subdirs = mapDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name);

    for (int i = 0; i < subdirs.length(); i++)
    {
        if (subdirs.at(i).isDir() )
        {
            QString path = subdirs.at(i).absoluteFilePath();
            QDir subdir = QDir(path);

            QFileInfo fileMask = QFileInfo(subdir.absoluteFilePath("mask.png"));
            QFileInfo fileInfo = QFileInfo(subdir.absoluteFilePath("info.html"));

            if (fileMask.exists() && fileInfo.exists())
            {
                MapItem *item = new MapItem(parent);

                if (item->loadFiles(
                            fileMask.absoluteFilePath(),
                            fileInfo.absoluteFilePath()) &&
                    item->setMainMap(mainMap))
                {
                    items->append(item);
                }
                else
                {
                    delete item;
                }
            }
        }
    }
}

