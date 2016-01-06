#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <stdio.h>
#include <string.h>
#include <XPLMDisplay.h>
#include <XPLMGraphics.h>
#include <XPWidgets.h>
#include <XPStandardWidgets.h>

void create_window();

void draw_callback(XPLMWindowID inWindowID, void * inRefcon);

void handle_key_callback(XPLMWindowID inWindowID, char inKey, XPLMKeyFlags inFlags, char inVirtualKey, void * inRefcon, int losingFocus);

int handle_mouse_click_callback(XPLMWindowID inWindowID, int x, int y, XPLMMouseStatus inMouse, void * inRefcon);

#endif // MAINWINDOW_H
