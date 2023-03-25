typedef struct Scroll {
	/* scroll position */
	int row, ydiff;
} Scroll;

typedef enum {
	WIDGET_NONE,
	WIDGET_INTERNAL,
	WIDGET_CONTEXT,
	WIDGET_CLOSE,
	WIDGET_OPEN,
	WIDGET_PREV,
	WIDGET_NEXT,
	WIDGET_REFRESH,
	WIDGET_GOTO,
	WIDGET_KEYPRESS,
	WIDGET_DROPASK,
	WIDGET_DROPCOPY,
	WIDGET_DROPMOVE,
	WIDGET_DROPLINK,
	WIDGET_ERROR,
} WidgetEvent;

enum {
	CURSOR_NORMAL,
	CURSOR_WATCH,
	CURSOR_DRAG,
	CURSOR_NODROP,
	CURSOR_LAST,
};

enum {
	/* item elements */
	ITEM_NAME,   /* indexes the label displayed for the item */
	ITEM_PATH,   /* indexes the path given in PRIMARY selection */
	ITEM_STATUS, /* indexes the status displayed on titlebar when item is selected */
	ITEM_LAST,
};

typedef struct Widget Widget;

Widget *initwidget(
	const char *class,
	const char *name,
	const char *geom,
	int argc,
	char *argv[]
);

unsigned long widgetwinid(Widget *widget);

int widopenicons(Widget *widget, char **xpms[], int nxpms);

int setwidget(
	Widget *widget,
	const char *title,
	char **items[],
	int itemicons[],
	size_t nitems,
	Scroll *scrl
);

void mapwidget(Widget *widget);

WidgetEvent pollwidget(Widget *widget, int *selitems, int *nselitems, Scroll *scrl, char **sel);

void setthumbnail(Widget *widget, char *path, int index);

void closewidget(Widget *widget);

void widget_busy(Widget *widget);
