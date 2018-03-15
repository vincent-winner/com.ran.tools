#!/bin/bash
gcc emmcclr.c -o emmcclr
gcc memclr.c -o memclr
gcc filehide.c -o filehide
gcc fileunhide.c -o fileunhide
gcc swap-emmc.c -o swap-emmc
gcc swap-sdcard.c -o swap-sdcard
gcc net_tool.c -o net_tool