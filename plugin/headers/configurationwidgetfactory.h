#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H

#include <iostream>
#include <vector>
#include <XPLMDisplay.h>
#include <XPWidgets.h>
#include <XPStandardWidgets.h>

#define Q_UNUSED(x) (void)x;

class ConfigurationWidgetFactory
{
public:
    //WidgetFactory() {}
    static std::vector<XPWidgetID> Create(int x, int y, int w, int h);
};

#endif // WIDGETFACTORY_H
