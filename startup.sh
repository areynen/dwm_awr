#!/bin/sh
# Setting screens
~/.screenlayout/dual-offset-home.sh
# Wallpaper
feh --bg-center ~/Pictures/wallpaper_blurry.png
# Theme
wal --theme ~/theme >/dev/null
# Picom compositor
pgrep -x picom >/dev/null || picom &
# Dunst notifcations
pgrep -x dunst >/dev/null || dunst &
# Udiskie for automounting drives and such
pgrep -x udiskie >/dev/null || udiskie &
# Clipboard manager
pgrep -x parcellite >/dev/null || parcellite &
# DWM Blocks
pgrep -x dwmblocks >/dev/null || dwmblocks &
# MPD
mpd &
mdpscribbler &
# Stop PC Beep
xset -b
