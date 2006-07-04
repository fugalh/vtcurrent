#!/bin/sh
if [ "8" = `vtcurrent` ]; then
    chvt 7
else
    chvt 8
fi
