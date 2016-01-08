#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <XPLMMenus.h>

#define Q_UNUSED(x) (void)x;

int ConfigurationWidgetHandler(XPWidgetMessage	inMessage,
                               XPWidgetID		inWidget,
                               intptr_t			inParam1,
                               intptr_t			inParam2);

void menu_callback(void *inMenuRef, void *inItemRef);

#endif // MAIN_H
