#!/bin/bash
#set -o xtrace
set -o errexit -o nounset -o pipefail -o errtrace
IFS=$'\n\t'

disp_num=1

disp=:$disp_num
Xephyr -screen 2560x1440 $disp -ac -br -sw-cursor &
pid=$!
while [ ! -e /tmp/.X11-unix/X${disp_num} ] ; do
    sleep 0.1
done

export DISPLAY=$disp

xrdb "${XDG_CONFIG_HOME:-$HOME/.config}/x11/xresources" & xrdbpid=$!
setbg &
remaps &
[ -n "$xrdbpid" ] && wait "$xrdbpid"
./dwm

kill $pid
exit 0
