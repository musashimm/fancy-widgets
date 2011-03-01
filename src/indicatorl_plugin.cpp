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
@file indicatorl_plugin.cpp
@brief Implementacja pluginu komponentu IndicatorL
*/

#include "indicatorl.h"
#include "indicatorl_plugin.h"

#include <QtPlugin>

IndicatorLPlugin::IndicatorLPlugin(QObject *parent)
		: QObject(parent)
{
		initialized = false;
}

void IndicatorLPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
		if (initialized)
				return;

		initialized = true;
}

bool IndicatorLPlugin::isInitialized() const
{
		return initialized;
}

QWidget *IndicatorLPlugin::createWidget(QWidget *parent)
{
		return new IndicatorL(parent,"IndicatorL Label");
}

QString IndicatorLPlugin::name() const
{
		return "IndicatorL";
}

QString IndicatorLPlugin::group() const
{
		return "Fancy Widgets";
}

QIcon IndicatorLPlugin::icon() const
{
		return QIcon();
}

QString IndicatorLPlugin::toolTip() const
{
		return "";
}

QString IndicatorLPlugin::whatsThis() const
{
		return "";
}

bool IndicatorLPlugin::isContainer() const
{
		return false;
}

QString IndicatorLPlugin::domXml() const
{
		return "<widget class=\"IndicatorL\" name=\"indicatorl\">\n"
						" <property name=\"geometry\">\n"
						"  <rect>\n"
						"   <x>0</x>\n"
						"   <y>0</y>\n"
						"   <width>90</width>\n"
						"   <height>20</height>\n"
						"  </rect>\n"
						" </property>\n"
						" <property name=\"toolTip\" >\n"
						"  <string>The indicatorl</string>\n"
						" </property>\n"
						" <property name=\"whatsThis\" >\n"
						"  <string>Indicates something.</string>\n"
						" </property>\n"
						"</widget>\n";
}

QString IndicatorLPlugin::includeFile() const
{
		return "indicatorl.h";
}
