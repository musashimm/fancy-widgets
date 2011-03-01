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

#include "fancy_widgets.h"

FancyWidgets::FancyWidgets(QObject *parent)
				: QObject(parent)
{
		widgets.append(new IndicatorLPlugin(this));
		widgets.append(new IndicatorPlugin(this));
}

QList<QDesignerCustomWidgetInterface*> FancyWidgets::customWidgets() const
{
		return widgets;
}

Q_EXPORT_PLUGIN2(customwidgetsplugin, FancyWidgets)

/**
@file fancy_widgets.cpp
@brief Implementacja biblioteki komponentów

@class FancyWidgets
@brief Implementuje interfejs \ref QDesignerCustomWidgetCollectionInterface .


@mainpage 
Biblioteka <em>Fancy Widgets</em> zawiera zbiór komponentów graficznych pomocnych przy projektowaniu i programowaniu interefejsów graficznych z wykorzystaniem biblioteki <em>Qt</em>. Komponenty mogą być wykorzystywane jako pluginy w <em>Qt Designerze</em>. Aby komponenty były widoczne w programie Qt Designer należy skompilowaną bibliotekę umieścić w katalogu z pluginami ($$[QT_INSTALL_PLUGINS]/designer).

@section project_structure Struktura projektu:

- src - katalog ze źródłami
- docs - katalog z dokumentacją
- dist - katalog z binariami
- files - pliki związane z projektem
- Doxyfile - konfiguracja tworzenia dokumentacji
- COPYING - pełny tekst licencji GPL v2
- README - podstawowe informacje o projekcie

@section components Komponenty

- Indicator - wskaźnik z opisem po lewej
@image html indicator.jpg
- IndicatorL - wskaźnik z opisem po prawej
@image html indicatorl.jpg

@section adds Dodatkowe strony
- \ref changes

@page changes Historia zmian
- 2009-11-11
	- wydanie wersji 1.0.0

*/
