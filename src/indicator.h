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
@file indicator.h
@brief Implementacja komponentu Indicator - plik nagłówkowy

@class Indicator
@brief Implementacja komponentu
*/

#ifndef CLASSINDICATOR_H
#define CLASSINDICATOR_H

#define INACTIVE_COLOR "green"
#define ACTIVE_COLOR "red"
#define BLOCK_COLOR "black"
#define BLINK1_COLOR "green"
#define BLINK2_COLOR "red"
#define INDICATOR_DEFAULT_LABEL "Indicator Label"
#define BLINK_DELAY 500

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>
#include <QtDesigner/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT Indicator : public QWidget
{
	Q_OBJECT

	public:
		Indicator(QWidget *parent = 0,const char* label = INDICATOR_DEFAULT_LABEL);
		void setLabel(const char*);
	
	public slots:
		void block();
		void active();
		void activeBlink();
		void inactive();

	private slots:
		void timeout();
	
	signals:
	
	private:
		QLabel *label;
		QWidget *light;
		QTimer	*timer;
		bool on;
};

#endif
