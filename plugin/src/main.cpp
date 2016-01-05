#include <stdio.h>
#include <string.h>
#include <XPLMDisplay.h>
#include <XPLMGraphics.h>
#include <XPLMMenus.h>

#include "../headers/main.h"
#include "../headers/mainwindow.h"

static XPLMMenuID menu;

static int itemShow;

void menu_callback(void *inMenuRef, void *inItemRef)
{
    skymxlinshow = !skymxlinshow;

    create_window();

    //TeensyControls_display_init();
    //XPLMSetMenuItemName(menu, itemShow, (TeensyControls_show) ?
        //"Hide Communication" : "Show Communication", 1);


}

PLUGIN_API int XPluginStart(char *name, char *sig, char *desc)
{
    XPLMMenuID pmenu;
    int mitem;

    strcpy(name, "SkyMxLin");
    strcpy(sig, "pjrc.SkyMxLin");
    strcpy(desc, "SkyMaxx implementation for X-Plane on Linux");

    pmenu = XPLMFindPluginsMenu();
    mitem = XPLMAppendMenuItem(pmenu, "SkyMx Linux", NULL, 1);
    menu = XPLMCreateMenu("SkyMx Linux", pmenu, mitem, menu_callback, NULL);
    itemShow = XPLMAppendMenuItem(menu, "Configuration", const_cast<char*>("show"), 1);

    return 1; // 1 = plugin started ok
}

PLUGIN_API void XPluginStop(void)
{
    printf("Plugin Stop\n");


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
