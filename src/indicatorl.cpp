/*

Fancy Widgets - bibliteka elementów interfejsu dla aplikacji Qt
Copyright (C) 2009  Wojciech Todryk (wojciech(at)todryk(dot)pl)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

$Id$

*/

/**
@file indicatorl.cpp
@brief Implementacja komponentu IndicatorL
*/

#include "indicatorl.h"

/** Konstruktor klasy
@param label etykieta wskaźnika
@param parent rodzic
*/
IndicatorL::IndicatorL(QWidget *parent,const char* label) 
	: QWidget(parent)
{
	QHBoxLayout *layout = new QHBoxLayout;
	light = new QWidget();
	light->setPalette(QPalette(QColor(INACTIVE_COLOR)));
	light->setAutoFillBackground(true);
	layout->addWidget(light);
	this->label = new QLabel(label);
	layout->addWidget(this->label);
	setLayout(layout);
	light->setMaximumSize(17,17);
	light->setMinimumSize(17,17);
	this->label->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
	timer = new QTimer;
	on = false;
	resize(90,20);
	connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
}

/** Ustawia wskaźnik w stan zablokowania
*/
void IndicatorL::block() {
	light->setPalette(QPalette(QColor(BLOCK_COLOR)));
}

/** Ustawia wskaźnik w stan aktywny
*/
void IndicatorL::active() {
	light->setPalette(QPalette(QColor(ACTIVE_COLOR)));
}

/** Ustawia wskaźnik w stan aktywny mrugający
*/
void IndicatorL::activeBlink() {
	timer->start(BLINK_DELAY);
}

/** Ustawia wskaźnik w stan nieaktywny
*/
void IndicatorL::inactive() {
	timer->stop();
	light->setPalette(QPalette(QColor(INACTIVE_COLOR)));
}

/** Ustawia etykietę wsaźnika
@param label etykieta
*/
void IndicatorL::setLabel(const char* label) {
	this->label->setText(QString(tr(label)));
}

/** Zmienia stan zgodnie z timerem
*/
void IndicatorL::timeout() {
	if (on) {
		light->setPalette(QPalette(QColor(BLINK1_COLOR)));
		on = false;
	} else {
		light->setPalette(QPalette(QColor(BLINK2_COLOR)));
		on = true;
	}
}


