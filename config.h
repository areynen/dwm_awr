/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 10;       /* snap pixel */
static const unsigned int gappih    = 4;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 4;       /* vert inner gap between windows */
static const unsigned int gappoh    = 4;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 4;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Symbols Nerd Font:style:size=14", "DejaVu Sans:size=12", "Noto Color Emoji:size=8" };
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
//static const unsigned int baralpha = 0xcc;
static const unsigned int baralpha = 0xff;
static const unsigned int borderalpha = OPAQUE;
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", " " };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      		instance    	title       	tags mask	switchtotag	iscentered	isfloating   monitor */
	// 1 - Terminal
	{ "St",  	  		"st",       	NULL,       	1 << 0,  		1 << 0,		0,    		0,           -1 },
	{ "newsboat",  		"st",       	NULL,       	1 << 0,  		1 << 0,		0,    		0,           -1 },
	// 2 - Web
	{ "FireFox",  		NULL,       	NULL,       	1 << 1,       	1 << 1,		0,			0,           -1 },	
	{ "firefox",  		NULL,       	NULL,       	1 << 1,       	1 << 1,		0,			0,           -1 },	
	{ "LibreWolf", 		NULL,       	NULL,       	1 << 1,       	1 << 1,		0,			0,           -1 },	
	{ "librewolf", 		NULL,       	NULL,       	1 << 1,       	1 << 1,		0,			0,           -1 },	
	// 3 - Code/IDE (not vim)
	{ "code-oss", 		NULL,       	NULL,       	1 << 2,       	1 << 2,		0,			0,           -1 },
	// 4 - Files
	{ "Thunar", 		NULL,       	NULL,       	1 << 3,       	1 << 3,		0,			0,           -1 },
		// st -c "ranger" -e ranger
	{ "ranger",			NULL,       	NULL,   		1 << 3,       	1 << 3,		0,			0,           -1 },
	{ "JDownloader",	NULL,       	NULL,   		1 << 3,       	1 << 3,		0,			0,           -1 },
	{ NULL,         	NULL,       	"JDownloader 2",1 << 3,       	1 << 3,		0,			0,           -1 },
	// 5 - Office/Other Editors
	{ NULL,		 		"libreoffice",	NULL,       	1 << 4,      	1 << 4,		0,			0,           -1 },
	{ NULL,				NULL,			"LibreOffice",  1 << 4,       	1 << 4,		0,			0,           -1 },
	{ "Gimp",	 		NULL,       	NULL,		   	1 << 4,       	1 << 4,		0,			0,           -1 },
	{ "Inkscape", 		NULL,       	NULL,		   	1 << 4,       	1 << 4,		0,			0,           -1 },
	// 6 - Games
	{ "Steam", 			"Steam",       	NULL,       	1 << 5,       	1 << 5,		0,			0,           -1 },
	{ "Lutris", 		NULL,       	NULL,       	1 << 5,       	1 << 5,		0,			0,           -1 },
	{ "retroarch", 		NULL,       	NULL,       	1 << 5,       	1 << 5,		0,			0,           -1 },
	{ NULL, 			"multimc",     	NULL,       	1 << 5,       	1 << 5,		0,			0,           -1 },
	// 7- Video
	{ "mpv", 			NULL,       	NULL,       	1 << 6,       	1 << 6,		0,			0,           -1 },
	// 8 - Music
		// st -c "ncmpcpp" -e ncmpcpp
	{ "ncmpcpp", 		NULL,       	NULL,       	1 << 7,       	1 << 7,		0,			0,           -1 },
	{ "Ario",    		NULL,       	NULL,       	1 << 7,       	1 << 7,		0,			0,           -1 },
	// 9 - Social
	{ "discord", 		NULL,       	NULL,       	1 << 8,       	1 << 8,		0,			0,           -1 },
	{ "neomutt", 		NULL,       	NULL,       	1 << 8,       	1 << 8,		0,			0,           -1 },
	{ "Discord Updater",NULL,       	NULL,       	1 << 8,       	0,			0,			0,           -1 },
	{ "Thunderbird",	NULL,       	NULL,       	1 << 8,       	1 << 8,		0,			0,           -1 },
	// Floating
	{ "firefox",    	"Browser",     	"About Mozilla Firefox",0,     	0,			1,			1,           -1 },
	{ NULL,    	"Browser",   	"About LibreWolf",  0,       	0,			1,			1,           -1 },
	{ "Galculator",		NULL,       	NULL,       	0,		       	0,			1,			1,           -1 },
	{ "Gpick",			NULL,       	NULL,       	0,		       	0,			1,			1,           -1 },
	{ "Pavucontrol",	NULL,       	NULL,       	0,		       	0,			1,			1,           -1 },
	{ "fehfloat",   	"feh",       	NULL,       	0,		       	0,			1,			1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int decorhints  = 1;    /* 1 means respect decoration hints */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "TTT",      bstack },
	{ "[M]",      monocle },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-n", scratchpadname, "-g", "120x34", NULL };

// DWM binds here, for programs using sxhkd
#include "focusurgent.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
//	{ MODKEY,                       XK_u,      focusurgent,    {0} },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|Mod1Mask,              XK_h,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_l,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_Tab,    focusmon,       {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_Tab,    focusstack,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,			            XK_f,      togglefullscr,  {0} },
	{ MODKEY|ControlMask,			XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_e,      quit,           {0} },
	{ MODKEY|ShiftMask, 			XK_r,      quit,           {1} }, 

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkRootWin,           0,              Button2,        desktopmenu,    {0} },
};

void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum           function */
	{ "focusstack",     focusstack },
	{ "setmfact",       setmfact },
	{ "togglebar",      togglebar },
	{ "incnmaster",     incnmaster },
	{ "togglefloating", togglefloating },
	{ "focusmon",       focusmon },
	{ "tagmon",         tagmon },
	{ "zoom",           zoom },
	{ "view",           view },
	{ "viewall",        viewall },
	{ "viewex",         viewex },
	{ "toggleview",     view },
	{ "toggleviewex",   toggleviewex },
	{ "tag",            tag },
	{ "tagall",         tagall },
	{ "tagex",          tagex },
	{ "toggletag",      tag },
	{ "toggletagex",    toggletagex },
	{ "killclient",     killclient },
	{ "quit",           quit },
	{ "setlayout",      setlayout },
	{ "setlayoutex",    setlayoutex },
	{ "xrdb",    		xrdb },
	{ "focusurgent",    focusurgent },
};
