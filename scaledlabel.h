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

#ifndef SCALEDLABEL_H
#define SCALEDLABEL_H

#include <QWidget>
#include <QImage>
#include <QPixmap>

class ScaledLabel : public QWidget
{
    Q_OBJECT
public:
    explicit ScaledLabel(QWidget *parent = 0);

    void setImage(const QImage *image);

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QImage mImage;
    QPixmap mPixmap;

signals:

public slots:

};

#endif // SCALEDLABEL_H
