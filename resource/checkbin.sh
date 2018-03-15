#!/system/bin/sh
#添加环境变量
export PATH=/data/data/com.ran.tools/files/usr/bin:/data/data/com.ran.tools/files:$PATH
export LD_LIBRARY_PATH="/data/data/com.ran.tools/files"
#检查是否存在bin文件夹
if [ ! -d /data/data/com.ran.tools/files/usr ];
then
#创建路径
echo "正在创建家目录"
mkdir /data/data/com.ran.tools/files/home
echo "家目录创建完成"
#下载支持
echo "正在做下载前的准备"
mv ./resource/wget /data/data/com.ran.tools/
chmod 0755 /data/data/com.ran.tools/wget
busybox tar -C /data/data/com.ran.tools/files -xvf ./resource/wgetlib.tar
rm -f ./resource/wgetlib.tar
echo "下载功能添加完毕"
#下载数据
echo "开始下载数据文件"
wget -O /data/data/com.ran.tools/files/usr.data https://vincent-winner.github.io/resDL/com.ran.tools-usr.data
echo "数据文件下载完毕"
#解压数据
echo "开始解压数据"
busybox tar -C /data/data/com.ran.tools/files -zxvf /data/data/com.ran.tools/files/usr.data
rm -f /data/data/com.ran.tools/files/usr.data
rm -f /data/data/com.ran.tools/files/lib*
rm -f /data/data/com.ran.tools/files/wget
echo "数据解压完毕"

#更改权限
echo "正在更改权限中"
chmod -R 4755 /data/data/com.ran.tools/files/usr/bin
chmod -R 4755 /data/data/com.ran.tools/files/usr/bin2
chmod -R 4755 /data/data/com.ran.tools/files/home
echo "权限修改完毕"
fi