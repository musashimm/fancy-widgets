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

#ifndef FANCYWIDGETS_H
#define FANCYWIDGETS_H

#include "indicator_plugin.h"
#include "indicatorl_plugin.h"

#include <QtDesigner/QtDesigner>
#include <QtCore/qplugin.h>

 class FancyWidgets: public QObject, public QDesignerCustomWidgetCollectionInterface
 {
     Q_OBJECT
     Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)

 public:
     FancyWidgets(QObject *parent = 0);

     virtual QList<QDesignerCustomWidgetInterface*> customWidgets() const;

 private:
     QList<QDesignerCustomWidgetInterface*> widgets;
 };

#endif

/**
@file fancy_widgets.h
@brief Implementacja biblioteki komponentów - plik nagłówkowy
*/
