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

#include "scaledlabel.h"
#include <QPainter>
#include <QMouseEvent>

ScaledLabel::ScaledLabel(QWidget *parent) :
    QWidget(parent)
{
    this->mImage = QImage();
    this->mPixmap = QPixmap();
    this->mScaleFactor = 1.0f;
    this->setMouseTracking(true);
}

void ScaledLabel::setImage(const QImage *image)
{
    this->mImage = QImage(*image);
    this->updatePixmap();
    this->update();
}

void ScaledLabel::resizeEvent(QResizeEvent *)
{
    this->updatePixmap();
}

void ScaledLabel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->mPixmap);
    painter.end();
}

void ScaledLabel::mouseMoveEvent(QMouseEvent *event)
{
    if (this->rect().contains(event->pos()))
    {
        int x = event->x();
        int y = event->y();

        x = ((float)x) * this->mScaleFactor;
        y = ((float)y) * this->mScaleFactor;

        if (this->mImage.rect().contains(x, y))
        {
            emit this->mouseMoved(x, y);
        }
        else
        {
            emit this->mouseExit();
        }
    }
}

void ScaledLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if (this->rect().contains(event->pos()))
    {
        int x = event->x();
        int y = event->y();

        x = ((float)x) * this->mScaleFactor;
        y = ((float)y) * this->mScaleFactor;

        if (this->mImage.rect().contains(x, y))
        {
            emit this->mouseReleased(x, y);
        }
    }
}

void ScaledLabel::updatePixmap()
{
    QPixmap pixmap = QPixmap::fromImage(this->mImage);
    pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio);
    this->mPixmap = pixmap;
    this->mScaleFactor = ((float)this->mImage.width()) / ((float)pixmap.width());
}
