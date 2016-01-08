#include "headers/configurationwidgetfactory.h"

std::vector<XPWidgetID> ConfigurationWidgetFactory::Create(int x, int y, int w, int h)
{
    std::vector<XPWidgetID> createdWidgets(8);

    XPWidgetID configurationWidget = NULL;

    XPWidgetID configurationWindow = NULL,
               configurationWindowCloudDetailAndDistance = NULL,
               configurationWindowCloudSize = NULL;

    XPWidgetID configurationWindowCloudDetailSliderControl = NULL,
               configurationWindowCloudDistanceSliderControl = NULL;

    int screenWidth, screenHeight;

    XPLMGetScreenSize(&screenWidth, &screenHeight);

    x = (screenWidth / 2) - (w / 2);
    y = (screenHeight / 2) + (h / 2);

    int x2 = x + w;
    int y2 = y - h;

    createdWidgets[0] = XPCreateWidget(x, y, x2, y2,
                                       1,                 // Visible
                                       "Configuration",	// desc
                                       1,                 // root
                                       NULL,              // no container
                                       xpWidgetClass_MainWindow);

    configurationWidget = createdWidgets[0];

    // Add Close Box decorations to the Main Widget
    XPSetWidgetProperty(configurationWidget, xpProperty_MainWindowHasCloseBoxes, 1);

    // Create the Sub Widget window
    createdWidgets[1] = XPCreateWidget(x+10, y-30, x2-10, y2+10,
                                       1,       // Visible
                                       "",      // desc
                                       0,		// root
                                       configurationWidget,
                                       xpWidgetClass_SubWindow);

    configurationWindow = createdWidgets[1];


    // Set the style to sub window
    XPSetWidgetProperty(configurationWindow, xpProperty_SubWindowType, xpSubWindowStyle_SubWindow);

    x = x + 20;
    y = y - 40;

    x2 = x + (w/2)-20;
    y2 = y - (h/2)+100;

    // Create Sub Widget window Cloud Detail and Distance
    createdWidgets[2] = XPCreateWidget(x, y, x2, y2,
                                       1,  // Visible
                                       "", // Description,
                                       0,  // root
                                       configurationWidget,
                                       xpWidgetClass_SubWindow);

    configurationWindowCloudDetailAndDistance = createdWidgets[2];

    // Set the style to sub window
    XPSetWidgetProperty(configurationWindowCloudDetailAndDistance, xpProperty_SubWindowType, xpSubWindowStyle_SubWindow);

    x = x + 10;
    y = y - 10;

    x2 = x + (w/2)-30;
    y2 = y - 20;

    // Add informational label
    createdWidgets[3] = XPCreateWidget(x, y, x2, y2,
                                       1,
                                       "These settings will effect memory and performance!",
                                       0,
                                       configurationWidget,
                                       xpWidgetClass_Caption);
    y = y - 20;

    x2 = x2 - 10;
    y2 = y - 20;

    // Add label for Cloud Detail slider
    createdWidgets[4] = XPCreateWidget(x, y, x2, y2,
                                       1,
                                       "Cloud detail",
                                       0,
                                       configurationWidget,
                                       xpWidgetClass_Caption);
    y = y - 20;
    y2 = y - 20;

    // Add slider control for Cloud Detail
    createdWidgets[5] = XPCreateWidget(x, y, x2, y2,
                                       1,
                                       "",
                                       0,
                                       configurationWidget,
                                       xpWidgetClass_ScrollBar);

    configurationWindowCloudDetailSliderControl = createdWidgets[5];

    // Set slider options
    XPSetWidgetProperty(configurationWindowCloudDetailSliderControl, xpProperty_ScrollBarMin, 0);
    XPSetWidgetProperty(configurationWindowCloudDetailSliderControl, xpProperty_ScrollBarMax, 100);
    XPSetWidgetProperty(configurationWindowCloudDetailSliderControl, xpProperty_ScrollBarSliderPosition, 50);
    XPSetWidgetProperty(configurationWindowCloudDetailSliderControl, xpProperty_ScrollBarType, xpScrollBarTypeSlider);

    y = y - 30;
    y2 = y - 20;

    // Add label for Cloud Detail slider
    createdWidgets[6] = XPCreateWidget(x, y, x2, y2,
                                       1,
                                       "Cloud distance",
                                       0,
                                       configurationWidget,
                                       xpWidgetClass_Caption);
    y = y - 20;
    y2 = y - 20;

    // Add slider control for Cloud Draw Distance
    createdWidgets[7] = XPCreateWidget(x, y, x2, y2,
                                       1,
                                       "",
                                       0,
                                       configurationWidget,
                                       xpWidgetClass_ScrollBar);

    configurationWindowCloudDistanceSliderControl = createdWidgets[7];

    // Set slider options
    XPSetWidgetProperty(configurationWindowCloudDistanceSliderControl, xpProperty_ScrollBarMin, 0);
    XPSetWidgetProperty(configurationWindowCloudDistanceSliderControl, xpProperty_ScrollBarMax, 100);
    XPSetWidgetProperty(configurationWindowCloudDistanceSliderControl, xpProperty_ScrollBarSliderPosition, 10);
    XPSetWidgetProperty(configurationWindowCloudDistanceSliderControl, xpProperty_ScrollBarType, xpScrollBarTypeSlider);

    return createdWidgets;
}


