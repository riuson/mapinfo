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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maps.h"
#include "mapscontroller.h"
#include "scaledlabel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->mLabelView = new ScaledLabel(this);
    this->mLabelView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->ui->frameImageContainer->layout()->addWidget(this->mLabelView);

    this->mMaps = new Maps(this);
    this->mController = new MapsController(this->mMaps, this);

    this->connect(this->mController, SIGNAL(imageChanged(const QImage*)), SLOT(imageChanged(const QImage*)));
    QObject::connect(this->mLabelView, SIGNAL(mouseMoved(int,int)), this->mController, SLOT(mouseMoving(int,int)));

    this->mController->init();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete this->mLabelView;

    delete this->mMaps;
}

void MainWindow::imageChanged(const QImage *image)
{
    this->mLabelView->setImage(image);
}
