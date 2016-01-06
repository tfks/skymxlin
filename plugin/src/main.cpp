#include <stdio.h>
#include <string.h>
#include <XPLMDisplay.h>
#include <XPLMGraphics.h>
#include <XPLMMenus.h>
#include <XPWidgets.h>
#include <XPStandardWidgets.h>
#include <XPWidgetDefs.h>

#include "../headers/main.h"

static XPLMMenuID menu;

static int itemShow;

static int configWindowCreated;

// Widgets
static XPWidgetID	ConfigurationWidget = NULL, ConfigurationWindow = NULL;

// Intitial window size
static int x = 300, y = 500, w = 600, h = 400;

void menu_callback(void *inMenuRef, void *inItemRef)
{
    if (!strcmp((char *) inItemRef, "Configuration"))
    {
        if (configWindowCreated == 0)
        {
            int x2 = x + w;
            int y2 = y - h;

            ConfigurationWidget = XPCreateWidget(x, y, x2, y2,
                                1,	// Visible
                                "Configuration",	// desc
                                1,		// root
                                NULL,	// no container
                                xpWidgetClass_MainWindow);

            // Add Close Box decorations to the Main Widget
            XPSetWidgetProperty(ConfigurationWidget, xpProperty_MainWindowHasCloseBoxes, 1);

            // Create the Sub Widget window
            ConfigurationWindow = XPCreateWidget(x+10, y-30, x2-10, y2+10,
                                                 1,	// Visible
                                                 "",	// desc
                                                 0,		// root
                                                 ConfigurationWidget,
                                                 xpWidgetClass_SubWindow);

            // Set the style to sub window
            XPSetWidgetProperty(ConfigurationWindow, xpProperty_SubWindowType, xpSubWindowStyle_SubWindow);

            // Register our widget handler
            XPAddWidgetCallback(ConfigurationWidget, ConfigurationWidgetHandler);

            configWindowCreated = 1;
        }
        else {
            if (!XPIsWidgetVisible(ConfigurationWidget)) {
                XPShowWidget(ConfigurationWidget);
            }
        }

    }
}

PLUGIN_API int XPluginStart(char *name, char *sig, char *desc)
{
    // Flag to tell us if the widget is being displayed.
    configWindowCreated = 0;

    XPLMMenuID menuId;

    int configurationMenuItem;

    strcpy(name, "SkyMxLin");
    strcpy(sig, "pjrc.SkyMxLin");
    strcpy(desc, "SkyMaxx implementation for X-Plane on Linux");

    configurationMenuItem = XPLMAppendMenuItem(XPLMFindPluginsMenu(), "SkyMx Linux", NULL, 1);
    menuId = XPLMCreateMenu("Configuration", XPLMFindPluginsMenu(), configurationMenuItem, menu_callback, NULL);
    XPLMAppendMenuItem(menuId, "Configuration", (void *)"Configuration", 1);

    return 1; // 1 = plugin started ok
}

PLUGIN_API void XPluginStop(void)
{
    printf("Plugin Stop\n");

    if (ConfigurationWidget && configWindowCreated == 1) {
        XPLMDestroyWindow(ConfigurationWidget);

        configWindowCreated = 0;
    }

    if (menu) {
        XPLMDestroyMenu(menu);
    }

    printf("Plugin End\n");
}

PLUGIN_API int XPluginEnable(void)
{
    printf("Plugin Enable\n");

    return 1;
}

PLUGIN_API void XPluginDisable(void)
{
    printf("Plugin Disable\n");
}


PLUGIN_API void XPluginReceiveMessage(XPLMPluginID from, long msg, void *param)
{
}

int ConfigurationWidgetHandler(XPWidgetMessage	inMessage,
                               XPWidgetID		inWidget,
                               intptr_t			inParam1,
                               intptr_t			inParam2)
{
    if (inMessage == xpMessage_CloseButtonPushed)
    {
        if (configWindowCreated == 1)
        {
            XPHideWidget(ConfigurationWidget);
        }

        return 1;
    }

    // Handle any check box selections
    if (inMessage == xpMsg_ButtonStateChanged)
    {
        return 1;
    }

    return 0;
}
