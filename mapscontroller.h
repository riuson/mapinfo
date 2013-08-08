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

#ifndef MAPSCONTROLLER_H
#define MAPSCONTROLLER_H

#include <QObject>

class Maps;

class MapsController : public QObject
{
    Q_OBJECT
public:
    explicit MapsController(Maps *maps, QObject *parent = 0);
    void init();

private:
    Maps *mMaps;
    int mLastIndex;
    bool mFixed;

    void applyMap(int index);

signals:
    void imageChanged(const QImage *image);
    void infoChanged(const QString &info);

public slots:
    void mouseMoving(int x, int y);
    void mouseReleased(int x, int y);
};

#endif // MAPSCONTROLLER_H
