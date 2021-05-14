#include <stdio.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>

int main(int argc, char **argv)
{
    XEvent e;
    Display *d;

    if (!(d = XOpenDisplay(NULL))) {
        fprintf(stderr, "cannot open display\n");
        return 1;
    }

    int xkbEventType;
    XKeysymToKeycode(d, XK_F1);
    XkbQueryExtension(d, 0, &xkbEventType, 0, 0, 0);
    XkbSelectEvents(d, XkbUseCoreKbd, XkbAllEventsMask, XkbAllEventsMask);
    XSync(d, False);

    int prevlang = 0;
    while (1) {
        XNextEvent(d, &e);
        if (e.type != xkbEventType) continue;
        XkbEvent* xkbEvent = (XkbEvent*) &e;
        if (xkbEvent->any.xkb_type != XkbStateNotify) continue;
        int lang = xkbEvent->state.group;
        if (lang == prevlang) continue;
        prevlang = lang;
        fprintf(stdout, "%u\n", lang);
        fflush(stdout);
    }

    return(0);
}
