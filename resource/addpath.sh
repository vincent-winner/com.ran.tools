#!/system/bin/sh

cd /data/data/com.ran.tools/files/home

export HOME=/data/data/com.ran.tools/files/home

export TMPDIR=/data/data/com.ran.tools/files/usr/tmp

export PREFIX=/data/data/com.ran.tools/files/usr

export LD_LIBRARY_PATH=/data/data/com.ran.tools/files/usr/lib

export LD_PRELOAD=${LD_PRELOAD}:/data/data/com.ran.tools/files/usr/lib/libtermux-exec.so

export PATH=/data/data/com.ran.tools/files:/data/data/com.ran.tools/files/usr/bin:/data/data/com.ran.tools/files/usr/bin/applets:$PATH