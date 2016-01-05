#include "../headers/mainwindow.h"

void create_window()
{
    gWindow = XPLMCreateWindow(50, 600, 300, 200,
                               1,
                               draw_callback,
                               handle_key_callback,
                               handle_mouse_click_callback,
                               NULL);
}

void draw_callback(XPLMWindowID inWindowID, void * inRefcon)
{


}

void handle_key_callback(XPLMWindowID        inWindowID,
                        char                 inKey,
                        XPLMKeyFlags         inFlags,
                        char                 inVirtualKey,
                        void *               inRefcon,
                        int                  losingFocus)
{

}

int handle_mouse_click_callback(XPLMWindowID          inWindowID,
                                 int                  x,
                                 int                  y,
                                 XPLMMouseStatus      inMouse,
                                 void *               inRefcon)
{

    return 1;
}
