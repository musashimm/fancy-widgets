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
@file indicator_plugin.cpp
@brief Implementacja pluginu komponentu Indicator
*/

#include "indicator.h"
#include "indicator_plugin.h"

#include <QtPlugin>

IndicatorPlugin::IndicatorPlugin(QObject *parent)
		: QObject(parent)
{
		initialized = false;
}

void IndicatorPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
		if (initialized)
				return;

		initialized = true;
}

bool IndicatorPlugin::isInitialized() const
{
		return initialized;
}

QWidget *IndicatorPlugin::createWidget(QWidget *parent)
{
		return new Indicator(parent,"Indicator Label");
}

QString IndicatorPlugin::name() const
{
		return "Indicator";
}

QString IndicatorPlugin::group() const
{
		return "Fancy Widgets";
}

QIcon IndicatorPlugin::icon() const
{
		return QIcon();
}

QString IndicatorPlugin::toolTip() const
{
		return "";
}

QString IndicatorPlugin::whatsThis() const
{
		return "";
}

bool IndicatorPlugin::isContainer() const
{
		return false;
}

QString IndicatorPlugin::domXml() const
{
		return "<widget class=\"Indicator\" name=\"indicator\">\n"
						" <property name=\"geometry\">\n"
						"  <rect>\n"
						"   <x>0</x>\n"
						"   <y>0</y>\n"
						"   <width>90</width>\n"
						"   <height>20</height>\n"
						"  </rect>\n"
						" </property>\n"
						" <property name=\"toolTip\" >\n"
						"  <string>The indicator</string>\n"
						" </property>\n"
						" <property name=\"whatsThis\" >\n"
						"  <string>Indicates something.</string>\n"
						" </property>\n"
						"</widget>\n";
}

QString IndicatorPlugin::includeFile() const
{
		return "indicator.h";
}

