#!/system/bin/sh
#添加环境变量
export PATH=/data/data/com.ran.tools/files/usr/bin:/data/data/com.ran.tools/files:$PATH
#检查是否存在bin文件夹
if [ ! -d /data/data/com.ran.tools/files/usr ];
then
#创建路径
mkdir /data/data/com.ran.tools/files/home
#解压资源
busybox tar -C /data/data/com.ran.tools/files -zxf ./resource/usr.data

#更改权限
chmod -R 4755 /data/data/com.ran.tools/files/usr
chmod -R 4755 /data/data/com.ran.tools/files/home
fi