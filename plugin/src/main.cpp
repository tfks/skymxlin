#include <stdio.h>
#include <string.h>
#include <XPLMDisplay.h>
#include <XPLMGraphics.h>
#include <XPLMMenus.h>
#include <XPWidgets.h>
#include <XPStandardWidgets.h>
#include <XPWidgetDefs.h>

#include "../headers/main.h"
#include "../headers/configurationwidgetfactory.h"

static XPLMMenuID menu;

static int configWindowCreated;

// Widgets
static std::vector<XPWidgetID> ConfigurationWidgets(8);

// Intitial window size
static int x = 0, y = 0, w = 700, h = 500;

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

    if ((ConfigurationWidgets.size() > 0) && configWindowCreated == 1)
    {
        for (int i = sizeof(ConfigurationWidgets); i --> 0;) {
            XPLMDestroyWindow(ConfigurationWidgets[i]);
        }

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
    Q_UNUSED(from);
    Q_UNUSED(msg);
    Q_UNUSED(param);
}

int ConfigurationWidgetHandler(XPWidgetMessage	inMessage,
                               XPWidgetID		inWidget,
                               intptr_t			inParam1,
                               intptr_t			inParam2)
{
    Q_UNUSED(inWidget);
    Q_UNUSED(inParam1);
    Q_UNUSED(inParam2);

    if (inMessage == xpMessage_CloseButtonPushed)
    {
        if (configWindowCreated == 1)
        {
            XPHideWidget(ConfigurationWidgets[0]);
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


void menu_callback(void *inMenuRef, void *inItemRef)
{
    Q_UNUSED(inMenuRef);

    if (!strcmp((char *) inItemRef, "Configuration"))
    {
        if (configWindowCreated == 0)
        {
            ConfigurationWidgets = ConfigurationWidgetFactory::Create(x, y, w, h);

            // Register our widget handler
            XPAddWidgetCallback(((XPWidgetID)ConfigurationWidgets[0]), ConfigurationWidgetHandler);

            configWindowCreated = 1;
        }
        else {
            if (!XPIsWidgetVisible(ConfigurationWidgets[0])) {
                XPShowWidget(ConfigurationWidgets[0]);
            }
        }

    }
}
