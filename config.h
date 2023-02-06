/* See LICENSE file for copyright and license details. */
#define BROWSER "librewolf"
#define TERMINAL "kitty"
#define PLAYERCTL "firefox" /* this is currently only passed to playerctl as the client to control */

/* appearance */
static const unsigned int borderpx = 2;
static const unsigned int snap = 20;
static const int showbar = 1;
static const int topbar = 1;
static const int swallowfloating = 0;
static const unsigned int systraypinning = 0;
static const unsigned int systrayonleft = 0;
static const unsigned int systrayspacing = 2;
static const int systraypinningfailfirst = 1;
static const int showsystray = 1;
static const char *fonts[] = {
    "monospace:pixelsize=14",
    "monospace:pixelsize=20",
    "monospace:pixelsize=30",
};

static char color0[]     = "#000000";
static char color1[]     = "#7f0000";
static char color2[]     = "#007f00";
static char color3[]     = "#7f7f00";
static char color4[]     = "#00007f";
static char color5[]     = "#7f007f";
static char color6[]     = "#007f7f";
static char color7[]     = "#cccccc";
static char color8[]     = "#333333"; 
static char color9[]     = "#ff0000"; 
static char color10[]    = "#00ff00"; 
static char color11[]    = "#ffff00"; 
static char color12[]    = "#0000ff"; 
static char color13[]    = "#ff00ff"; 
static char color14[]    = "#00ffff"; 
static char color15[]    = "#ffffff";
static char bordernorm[] = "#222222";
static char bordersel[]  = "#444444";

static char *barschemes[][3]        = {
    /*                    fg       bg       border   */
    [SchemeNorm]      = { color15, color0, bordernorm },
    [SchemeSel]       = { color15, color4, bordersel },
    [SchemeStatus]    = { color7,  color0, "#000000" }, // Statusbar right
    [SchemeTagsSel]   = { color0,  color4, "#000000" }, // Tagbar left selected
    [SchemeTagsNorm]  = { color7,  color0, "#000000" }, // Tagbar left unselected
    [SchemeInfoSel]   = { color7,  color0, "#000000" }, // infobar middle selected
    [SchemeInfoNorm]  = { color7,  color0, "#000000" }, // infobar middle unselected
};

// static const char *colors[] = {
//     [0]  = "#000000", [1]  = "#7f0000", [2]  = "#007f00", [3]  = "#7f7f00",
//     [4]  = "#00007f", [5]  = "#7f007f", [6]  = "#007f7f", [7]  = "#cccccc",
//     [8]  = "#333333", [9]  = "#ff0000", [10] = "#00ff00", [11] = "#ffff00",
//     [12] = "#0000ff", [13] = "#ff00ff", [14] = "#00ffff", [15] = "#ffffff",
//     /* Extra Colors (not accessible with SGR escapes) */
//     [16] = "#222222", [17] = "#444444", 
// };
//
// static char *barschemes[][3] = {
//     /*                  fg          bg         border */
//     [SchemeNorm]     = {colors[15], colors[0], colors[16]},
//     [SchemeSel]      = {colors[15], colors[4], colors[17]},
//     [SchemeStatus]   = {colors[7],  colors[0], "#000000"}, // Statusbar right
//     [SchemeTagsSel]  = {colors[0],  colors[4], "#000000"}, // Tagbar left selected
//     [SchemeTagsNorm] = {colors[7],  colors[0], "#000000"}, // Tagbar left unselected
//     [SchemeInfoSel]  = {colors[7],  colors[0], "#000000"}, // infobar middle selected
//     [SchemeInfoNorm] = {colors[7],  colors[0], "#000000"}, // infobar middle unselected
// };

/* tagging */
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const Rule rules[] = {
    /* xprop(1):
     * WM_CLASS(STRING) = instance, class
     * WM_NAME(STRING) = title
     * If X, Y, W or H are between 0 and 1 (inclusive), their values interpreted as percentages of the current monitor resolution.
     * If X or Y are negative, they are subtracted from the current monitor resolution and then that value is interpreted.
       class           instance            title           scratch key tags mask   isfloating isterminal noswallow   x,    y,   w,    h     borderpx */
    { NULL,            NULL,               "Event Tester", 0,          0,          0,         0,         1,         0,    0,   0,    0,   -1 },
    { "Xournalpp",     "xournalpp",        NULL,           0,          0,          0,         0,        -1,         0,    0,   0,    0,   -1 },
    { "Zathura",       "org.pwmt.zathura", NULL,           0,          0,          0,         0,        -1,         0,    0,   0,    0,   -1 },
    { NULL,            "kitty",            NULL,           0,          0,          0,         1,         0,         0,    0,   0,    0,   -1 },
    { "Qalculate-gtk", NULL,               NULL,           'q',        0,          1,         0,         0,        .5,   .5,   722,  512, -1 },
    { NULL,            "sphelp",           NULL,           'n',        0,          1,         1,         0,        .5,   .5,  .3,   .8,   -1 },
    { NULL,            "splf",             NULL,           'l',        0,          1,         0,         0,        .5,   .5,  .8,   .8,   -1 },
    { NULL,            "sphtop",           NULL,           'h',        0,          1,         0,         0,        .5,   .5,  .8,   .8,   -1 },
    { NULL,            "spmix",            NULL,           'm',        0,          1,         0,         0,        -4,   -4,   900,  600, -1 },
};

/* layout(s) */
static const float mfact = 0.50;     /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;        /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol arrange function */
    { "[]=",  tile },
    { "TTT",  bstack },
    { "|M|",  centeredmaster },
    { ":::",  gaplessgrid },
    { "[M]",  monocle },
    { "===",  bstackhoriz },
    { ">M>",  centeredfloatingmaster },
    { "><>",  NULL }, /* Floating */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL } }

/* commands */
// static const char *spterm[] = { "t", "/bin/sh", "-c", "$TERMINAL --name spterm --config ~/.config/kitty/kitty.conf --config ~/.config/kitty/kittyfullscreen.conf" };
static const char *spqalc[] = { "q", "qalculate-gtk", NULL };
static const char *splf[] = { "l", TERMINAL, "--name", "splf", "-d", "~", "-e", "lf", NULL };
static const char *sphtop[] = { "h", TERMINAL, "--name", "sphtop", "-e", "htop", NULL };
static const char *spmix[] = { "m", "/bin/sh", "-c", TERMINAL "--name spmix -e pulsemixer; pkill -RTMIN+10 dwmblocks" };
static const char *sphelp[] = { "n", TERMINAL, "--name", "sphelp", "-e", "/bin/sh", "-c", "lowdown -Tterm /usr/local/share/dwm/dwm.md | less" };

/* Xresources preferences to load at startup */
ResourcePref resources[] = {
    { "color0",     STRING, &color0 },
    { "color1",     STRING, &color1 },
    { "color2",     STRING, &color2 },
    { "color3",     STRING, &color3 },
    { "color4",     STRING, &color4 },
    { "color5",     STRING, &color5 },
    { "color6",     STRING, &color6 },
    { "color7",     STRING, &color7 },
    { "color8",     STRING, &color8 },
    { "color9",     STRING, &color9 },
    { "color10",    STRING, &color10 },
    { "color11",    STRING, &color11 },
    { "color12",    STRING, &color12 },
    { "color13",    STRING, &color13 },
    { "color14",    STRING, &color14 },
    { "color15",    STRING, &color15 },
    { "bordernorm", STRING, &bordernorm },
    { "bordersel",  STRING, &bordersel },
};

#include <X11/XF86keysym.h>

static const Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,              XK_F1,              togglescratch,      {.v = sphelp} },
    // { MODKEY,              XK_F2,              spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_F3,              togglescratch,      {.v = spmix} },
    // { MODKEY,              XK_F4,              spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_F5,              spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_F6,              spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_F7,              spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_F8,              spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_F9,              spawn,              {.v = (const char *[]){"dmenumount", NULL}} },
    { MODKEY,              XK_F10,             spawn,              {.v = (const char *[]){"dmenuumount", NULL}} },
    { MODKEY,              XK_F11,             spawn,              {.v = (const char *[]){"displayselect", NULL}} },
    { MODKEY,              XK_F12,             spawn,              {.v = (const char *[]){"remaps", NULL}} },
    { MODKEY,              XK_grave,           spawn,              {.v = (const char *[]){"dmenuunicode", NULL}} },
    // { MODKEY | ShiftMask,  XK_grave,           spawn,              {.v = (const char *[]){NULL}} },
    TAGKEYS(               XK_1,                                   0)
    TAGKEYS(               XK_2,                                   1)
    TAGKEYS(               XK_3,                                   2)
    TAGKEYS(               XK_4,                                   3)
    TAGKEYS(               XK_5,                                   4)
    TAGKEYS(               XK_6,                                   5)
    TAGKEYS(               XK_7,                                   6)
    TAGKEYS(               XK_8,                                   7)
    TAGKEYS(               XK_9,                                   8)
    { MODKEY,              XK_0,               view,               {.ui = ~0} },
    { MODKEY | ShiftMask,  XK_0,               tag,                {.ui = ~0} },
    // { MODKEY,              XK_bracketleft,     spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_bracketleft,     spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_bracketright,    spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_bracketright,    spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_BackSpace,       spawn,              {.v = (const char *[]){"sysact", NULL}} },
    // { MODKEY | ShiftMask,  XK_BackSpace,       spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_Tab,             focusstack,         {.i = 0} },
    { MODKEY | ShiftMask,  XK_Tab,             pushstack,          {.i = 0} },
    { MODKEY,              XK_apostrophe,      killclient,         {0} },
    // { MODKEY | ShiftMask,  XK_apostrophe,      spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_comma,           focusmon,           {.i = -1} },
    { MODKEY | ShiftMask,  XK_comma,           tagmon,             {.i = -1} },
    { MODKEY,              XK_period,          focusmon,           {.i = +1} },
    { MODKEY | ShiftMask,  XK_period,          tagmon,             {.i = +1} },
    { MODKEY,              XK_p,               spawn,              {.v = (const char *[]){"playerctl", "play-pause", NULL}} },
    // { MODKEY | ShiftMask,  XK_p,               spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_y,               spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_y,               spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_f,               togglefullscr,      {0} },
    // { MODKEY | ShiftMask,  XK_f,               setlayout,          {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_g,               spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_g,               spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_c,               incnmaster,         {.i = -1} },
    { MODKEY | ShiftMask,  XK_c,               resetnmaster,       {0} },
    { MODKEY,              XK_r,               incnmaster,         {.i = +1} },
    { MODKEY | ShiftMask,  XK_r,               resetnmaster,       {0} },
    { MODKEY,              XK_l,               setmfact,           {.f = +0.05} },
    // { MODKEY | ShiftMask,  XK_l,               spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_slash,           spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_slash,           spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_equal,           spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_equal,           spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_a,               spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_a,               spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_o,               togglescratch,      {.v = sphtop} },
    { MODKEY | ShiftMask,  XK_o,               spawn,              {.v = (const char *[]){TERMINAL, "-e", "htop", NULL}} },
    { MODKEY,              XK_e,               togglescratch,      {.v = splf} },
    { MODKEY | ShiftMask,  XK_e,               spawn,              SHCMD(TERMINAL "-e $SHELL -c \"lf; $SHELL\"")},
    { MODKEY,              XK_u,               spawn,              {.v = (const char *[]){"dmenu_run", NULL}} },
    // { MODKEY | ShiftMask,  XK_u,               spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_i,               spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_i,               spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_d,               spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_d,               spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_h,               setmfact,           {.f = -0.05} },
    // { MODKEY | ShiftMask,  XK_h,               spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_t,               spawn,              {.v = (const char *[]){BROWSER, NULL}} },
    { MODKEY | ShiftMask,  XK_t,               spawn,              {.v = (const char *[]){TERMINAL, "-e", "sudo", "nmtui", NULL}} },
    { MODKEY,              XK_n,               setlayout,          {.v = &layouts[0]} },
    { MODKEY | ShiftMask,  XK_n,               setlayout,          {.v = &layouts[1]} },
    { MODKEY,              XK_s,               setlayout,          {.v = &layouts[2]} },
    { MODKEY | ShiftMask,  XK_s,               setlayout,          {.v = &layouts[3]} },
    { MODKEY,              XK_minus,           setlayout,          {.v = &layouts[4]} },
    { MODKEY | ShiftMask,  XK_minus,           setlayout,          {.v = &layouts[5]} },
    { MODKEY,              XK_backslash,       togglescratch,      {.v = spqalc} },
    // { MODKEY | ShiftMask,  XK_backslash,       spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_Return,          spawn,              {.v = (const char *[]){TERMINAL, "-d", "~", NULL}} },
    { MODKEY | ShiftMask,  XK_Return,          spawn,              {.v = (const char *[]){"samedir", NULL}} },
    // { MODKEY,              XK_semicolon,       spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_semicolon,       spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_q,               spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_q,               spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_j,               focusstack,         {.i = INC(+1)} },
    { MODKEY | ShiftMask,  XK_j,               pushstack,          {.i = INC(+1)} },
    { MODKEY,              XK_k,               focusstack,         {.i = INC(-1)} },
    { MODKEY | ShiftMask,  XK_k,               pushstack,          {.i = INC(-1)} },
    // { MODKEY,              XK_x,               spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_x,               spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_b,               togglebar,          {0} },
    // { MODKEY | ShiftMask,  XK_b,               spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_m,               spawn,              {.v = (const char *[]){BROWSER, "listen.tidal.com", NULL }} },
    { MODKEY | ShiftMask,  XK_m,               spawn,              SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
    { MODKEY,              XK_w,               spawn,              {.v = (const char *[]){"ferdium", NULL}} },
    // { MODKEY | ShiftMask,  XK_w,               spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_v,               focusstack,         {.i = PREVSEL} },
    { MODKEY | ShiftMask,  XK_v,               pushstack,          {.i = PREVSEL} },
    // { MODKEY,              XK_z,               spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_z,               spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_space,           zoom,               {0} },
    { MODKEY | ShiftMask,  XK_space,           togglefloating,     {0} },
    { 0,                   XK_Print,           spawn,              SHCMD("maim ~/Photos/Screenshots/pic-full-$(date '+%y%m%d-%H%M-%S').png") },
    { ShiftMask,           XK_Print,           spawn,              {.v = (const char *[]){"maimpick", NULL}} },
    { MODKEY,              XK_Print,           spawn,              {.v = (const char *[]){"dmenurecord", NULL}} },
    { MODKEY | ShiftMask,  XK_Print,           spawn,              {.v = (const char *[]){"dmenurecord", "kill", NULL}} },
    // { MODKEY,              XK_Scroll_Lock,     spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_Scroll_Lock,     spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_Pause,           spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_Pause,           spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_Insert,          spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_Insert,          spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_Home,            spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_Home,            spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_Page_Up,         spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_Page_Up,         spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_Delete,          spawn,              {.v = (const char *[]){"dmenurecord", "kill", NULL}} },
    // { MODKEY | ShiftMask,  XK_Delete,          spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY,              XK_End,             spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY | ShiftMask,  XK_End,             quit,               {0} },
    // { MODKEY,              XK_Page_Down,       spawn,              {.v = (const char *[]){NULL}} },
    // { MODKEY | ShiftMask,  XK_Page_Down,       spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_Left,            spawn,              {.v = (const char *[]){"playerctl", "-p", PLAYERCTL, "previous", NULL}} },
    { MODKEY | ShiftMask,  XK_Left,            spawn,              {.v = (const char *[]){"playerctl", "-p", PLAYERCTL, "position", "0", NULL}} },
    { MODKEY,              XK_Right,           spawn,              {.v = (const char *[]){"playerctl", "-p", PLAYERCTL, "next", NULL}} },
    // { MODKEY | ShiftMask,  XK_Right,          spawn,              {.v = (const char *[]){NULL}} },
    { MODKEY,              XK_Up,              spawn,              SHCMD("pamixer --allow-boost -i 5; pkill -RTMIN+10 dwmblocks") },
    { MODKEY | ShiftMask,  XK_Up,              spawn,              SHCMD("pamixer --allow-boost -i 20; pkill -RTMIN+10 dwmblocks") },
    { MODKEY,              XK_Down,            spawn,              SHCMD("pamixer --allow-boost -d 5; pkill -RTMIN+10 dwmblocks") },
    { MODKEY | ShiftMask,  XK_Down,            spawn,              SHCMD("pamixer --allow-boost -d 20; pkill -RTMIN+10 dwmblocks") },

    { 0, XF86XK_AudioMute,                     spawn,              SHCMD("pamixer -t; pkill -RTMIN+10 dwmblocks") },
    { 0, XF86XK_AudioRaiseVolume,              spawn,              SHCMD("pamixer --allow-boost -i 5; pkill -RTMIN+10 dwmblocks") },
    { 0, XF86XK_AudioLowerVolume,              spawn,              SHCMD("pamixer --allow-boost -d 5; pkill -RTMIN+10 dwmblocks") },
    { 0, XF86XK_AudioPrev,                     spawn,              {.v = (const char *[]){"playerctl", "-p", PLAYERCTL, "previous", NULL}} },
    { 0, XF86XK_AudioNext,                     spawn,              {.v = (const char *[]){"playerctl", "-p", PLAYERCTL, "next", NULL}} },
    { 0, XF86XK_AudioPause,                    spawn,              {.v = (const char *[]){"playerctl", "-p", PLAYERCTL, "pause", NULL}} },
    { 0, XF86XK_AudioPlay,                     spawn,              {.v = (const char *[]){"playerctl", "-p", PLAYERCTL, "play", NULL}} },
    { 0, XF86XK_AudioStop,                     spawn,              {.v = (const char *[]){"playerctl", "-p", PLAYERCTL, "stop", NULL}} },
    { 0, XF86XK_AudioRewind,                   spawn,              {.v = (const char *[]){"playerctl", "-p", PLAYERCTL, "position", "10-", NULL}} },
    { 0, XF86XK_AudioForward,                  spawn,              {.v = (const char *[]){"playerctl", "-p", PLAYERCTL, "position", "10+", NULL}} },
    // { 0, XF86XK_AudioMedia,                    spawn,              {.v = (const char *[]){NULL}} },
    { 0, XF86XK_AudioMicMute,                  spawn,              SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
    { 0, XF86XK_PowerOff,                      spawn,              {.v = (const char *[]){"sysact", NULL}} },
    { 0, XF86XK_Calculator,                    spawn,              {.v = (const char *[]){TERMINAL, "-e", "bc", "-l", NULL}} },
    { 0, XF86XK_Sleep,                         spawn,              {.v = (const char *[]){"sudo", "-A", "zzz", NULL}} },
    { 0, XF86XK_WWW,                           spawn,              {.v = (const char *[]){BROWSER, NULL}} },
    { 0, XF86XK_WLAN,                          spawn,              SHCMD("sleep 0.1; pkill -RTMIN+4 dwmblocks") },
    { 0, XF86XK_DOS,                           spawn,              {.v = (const char *[]){TERMINAL, NULL}} },
    { 0, XF86XK_ScreenSaver,                   spawn,              SHCMD("xset s activate & mpc pause & pauseallmpv") },
    { 0, XF86XK_TaskPane,                      spawn,              {.v = (const char *[]){TERMINAL, "-e", "htop", NULL}} },
    { 0, XF86XK_Mail,                          spawn,              SHCMD("$TERMINAL -e neomutt; pkill -RTMIN+12 dwmblocks") },
    { 0, XF86XK_MyComputer,                    spawn,              {.v = (const char *[]){TERMINAL, "-e", "lfub", "/", NULL}} },
    // { 0, XF86XK_Battery,                       spawn,              {.v = (const char *[]){NULL}} },
    { 0, XF86XK_Launch1,                       spawn,              {.v = (const char *[]){"xset", "dpms", "force", "off", NULL}} },
    { 0, XF86XK_TouchpadToggle,                spawn,              SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || " "synclient TouchpadOff=1") },
    { 0, XF86XK_TouchpadOff,                   spawn,              {.v = (const char *[]){"synclient", "TouchpadOff=1", NULL}} },
    { 0, XF86XK_TouchpadOn,                    spawn,              {.v = (const char *[]){"synclient", "TouchpadOff=0", NULL}} },
    /* WARN: If you have multiple backlight controllers this will fail */
    { 0, XF86XK_MonBrightnessUp,               spawn,              SHCMD("echo $(($(cat /sys/class/backlight/*/brightness) + 5)) | tee /sys/class/backlight/*/brightness") },
    { 0, XF86XK_MonBrightnessDown,             spawn,              SHCMD("echo $(($(cat /sys/class/backlight/*/brightness) - 5)) | tee /sys/class/backlight/*/brightness") },
};

/* button definitions */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    // { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    // { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    // { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    // { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    // { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    // { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
