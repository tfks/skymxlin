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
private:
    static XPWidgetID createMainWidget(int *outX, int *outY, int *outX2, int *outY2, int width, int height);
    static XPWidgetID createMainSubWidget(XPWidgetID configurationWidget, int x, int y, int x2, int y2);
    static std::vector<XPWidgetID> createCloudDetailAndDistanceSubWidgets(XPWidgetID configurationWidget, int *outX, int *outY, int *outX2, int *outY2, int width, int height);
    static std::vector<XPWidgetID> createCloudSizeSubWidgets(XPWidgetID configurationWidget, int *outX, int *outY, int *outX2, int *outY2, int width, int height);

public:
    //WidgetFactory() {}
    static std::vector<XPWidgetID> Create(int x, int y, int w, int h);
};

#endif // WIDGETFACTORY_H
