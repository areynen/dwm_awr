#!/bin/sh
# Setting screens
~/.screenlayout/dual-offset-home.sh
# Wallpaper
feh --bg-center ~/Pictures/wallpaper.png
# Theme
wal --theme ~/theme >/dev/null
dwmc xrdb
# Picom compositor
pgrep -x picom >/dev/null || picom &
# Dunst notifcations
pgrep -x dunst >/dev/null || dunst &
# Udiskie for automounting drives and such
pgrep -x udiskie >/dev/null || udiskie &
# Clipboard manager
pgrep -x parcellite >/dev/null || parcellite -n &
# DWM Blocks
pgrep -x dwmblocks >/dev/null || dwmblocks &
# sxhkd startup
pgrep -x sxhkd >/dev/null || sxhkd &
# MPD
mpd &
pgrep -x mpdscribble >/dev/null || mpdscribble &
# Stop PC Beep
xset -b
