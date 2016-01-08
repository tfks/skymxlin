#include "headers/configurationwidgetfactory.h"

std::vector<XPWidgetID> ConfigurationWidgetFactory::Create(int x, int y, int w, int h)
{
    std::vector<XPWidgetID> createdWidgets(8);

    XPWidgetID configurationWidget = NULL;

    int x2 = x + w;
    int y2 = y - h;

    createdWidgets[0] = ConfigurationWidgetFactory::createMainWidget(&x, &y, &x2, &y2, w, h);

    configurationWidget = createdWidgets[0];

    createdWidgets[1] = ConfigurationWidgetFactory::createMainSubWidget(configurationWidget, x+10, y-30, x2-10, y2+10);

    std::vector<XPWidgetID> cloudDetailAndDistanceSubWidgets =
            ConfigurationWidgetFactory::createCloudDetailAndDistanceSubWidgets(configurationWidget, &x, &y, &x2, &y2, w, h);

    createdWidgets.reserve(cloudDetailAndDistanceSubWidgets.size());
    createdWidgets.insert(createdWidgets.end(), cloudDetailAndDistanceSubWidgets.begin(), cloudDetailAndDistanceSubWidgets.end());

    cloudDetailAndDistanceSubWidgets.clear();

    return createdWidgets;
}

XPWidgetID ConfigurationWidgetFactory::createMainWidget(int * outX, int * outY, int * outX2, int * outY2, int width, int height)
{
    int screenWidth, screenHeight;

    XPLMGetScreenSize(&screenWidth, &screenHeight);

    *outX = (screenWidth / 2) - (width / 2);
    *outY = (screenHeight / 2) + (height / 2);

    *outX2 = (*outX + width);
    *outY2 = (*outY - height);

    XPWidgetID mainWidget = XPCreateWidget(*outX, *outY, *outX2, *outY2,
                                           1,                   // Visible
                                           "Configuration",     // desc
                                           1,                   // root
                                           NULL,                // no container
                                           xpWidgetClass_MainWindow);

    // Add Close Box decorations to the Main Widget
    XPSetWidgetProperty(mainWidget, xpProperty_MainWindowHasCloseBoxes, 1);

    return mainWidget;
}

XPWidgetID ConfigurationWidgetFactory::createMainSubWidget(XPWidgetID configurationWidget, int x, int y, int x2, int y2)
{
    XPWidgetID mainSubWidget = XPCreateWidget(x, y, x2, y2,
                                              1,        // Visible
                                              "",       // desc
                                              0,		// root
                                              configurationWidget,
                                              xpWidgetClass_SubWindow);
    // Set the style to sub window
    XPSetWidgetProperty(mainSubWidget, xpProperty_SubWindowType, xpSubWindowStyle_SubWindow);

    return mainSubWidget;
}

std::vector<XPWidgetID> ConfigurationWidgetFactory::createCloudDetailAndDistanceSubWidgets(XPWidgetID configurationWidget, int * outX, int * outY, int * outX2, int * outY2, int width, int height)
{
    std::vector<XPWidgetID> cloudDetailAndDistanceSubWidgets(6);

    *outX = *outX + 20;
    *outY = *outY - 40;

    *outX2 = *outX + (width / 2)-20;
    *outY2 = *outY - (height / 2)+100;

    // Create Sub Widget window Cloud Detail and Distance
    cloudDetailAndDistanceSubWidgets[0] = XPCreateWidget(*outX, *outY, *outX2, *outY2,
                                                         1,  // Visible
                                                         "", // Description,
                                                         0,  // root
                                                         configurationWidget,
                                                         xpWidgetClass_SubWindow);

    XPWidgetID subWidgetCloudDetailAndDistance = cloudDetailAndDistanceSubWidgets[0];

    // Set the style to sub window
    XPSetWidgetProperty(subWidgetCloudDetailAndDistance, xpProperty_SubWindowType, xpSubWindowStyle_SubWindow);

    *outX = *outX + 10;
    *outY = *outY - 10;

    *outX2 = *outX + (width / 2)-30;
    *outY2 = *outY - 20;

    // Add informational label
    cloudDetailAndDistanceSubWidgets[1] = XPCreateWidget(*outX, *outY, *outX2, *outY2,
                                                         1,
                                                         "These settings will effect memory and performance!",
                                                         0,
                                                         configurationWidget,
                                                         xpWidgetClass_Caption);
    *outY = *outY - 20;

    *outX2 = *outX2 - 10;
    *outY2 = *outY - 20;

    // Add label for Cloud Detail slider
    cloudDetailAndDistanceSubWidgets[2] = XPCreateWidget(*outX, *outY, *outX2, *outY2,
                                                         1,
                                                         "Cloud detail",
                                                         0,
                                                         configurationWidget,
                                                         xpWidgetClass_Caption);

    *outY = *outY - 20;
    *outY2 = *outY - 20;

    // Add slider control for Cloud Detail
    cloudDetailAndDistanceSubWidgets[3] = XPCreateWidget(*outX, *outY, *outX2, *outY2,
                                                         1,
                                                         "",
                                                         0,
                                                         configurationWidget,
                                                         xpWidgetClass_ScrollBar);
    // Set slider options
    XPSetWidgetProperty(cloudDetailAndDistanceSubWidgets[3], xpProperty_ScrollBarMin, 0);
    XPSetWidgetProperty(cloudDetailAndDistanceSubWidgets[3], xpProperty_ScrollBarMax, 100);
    XPSetWidgetProperty(cloudDetailAndDistanceSubWidgets[3], xpProperty_ScrollBarSliderPosition, 50);
    XPSetWidgetProperty(cloudDetailAndDistanceSubWidgets[3], xpProperty_ScrollBarType, xpScrollBarTypeSlider);

    *outY = *outY - 30;
    *outY2 = *outY - 20;

    // Add label for Cloud Detail slider
    cloudDetailAndDistanceSubWidgets[4] = XPCreateWidget(*outX, *outY, *outX2, *outY2,
                                                         1,
                                                         "Cloud distance",
                                                         0,
                                                         configurationWidget,
                                                         xpWidgetClass_Caption);

    *outY = *outY - 20;
    *outY2 = *outY - 20;

    // Add slider control for Cloud Draw Distance
    cloudDetailAndDistanceSubWidgets[5] = XPCreateWidget(*outX, *outY, *outX2, *outY2,
                                                         1,
                                                         "",
                                                         0,
                                                         configurationWidget,
                                                         xpWidgetClass_ScrollBar);

    // Set slider options
    XPSetWidgetProperty(cloudDetailAndDistanceSubWidgets[5], xpProperty_ScrollBarMin, 0);
    XPSetWidgetProperty(cloudDetailAndDistanceSubWidgets[5], xpProperty_ScrollBarMax, 100);
    XPSetWidgetProperty(cloudDetailAndDistanceSubWidgets[5], xpProperty_ScrollBarSliderPosition, 10);
    XPSetWidgetProperty(cloudDetailAndDistanceSubWidgets[5], xpProperty_ScrollBarType, xpScrollBarTypeSlider);

    return cloudDetailAndDistanceSubWidgets;
}


