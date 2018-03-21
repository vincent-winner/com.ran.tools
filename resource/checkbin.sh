#!/system/bin/sh
#添加环境变量
export PATH=/data/data/com.ran.tools/files/usr/bin:/data/data/com.ran.tools/files:$PATH
#检查是否存在bin文件夹
if [ ! -d /data/data/com.ran.tools/files/home ];
then
	#创建路径
	echo "正在创建家目录"
	busybox sleep 1
	mkdir /data/data/com.ran.tools/files/home
	busybox sleep 1
	echo "家目录创建完成"
fi

if [ ! -d /data/data/com.ran.tools/files/usr ];
then
	echo "添加下载功能支持"
	busybox sleep 1
	cp ./resource/wget /data/data/com.ran.tools/files/wget
	chmod 0755 /data/data/com.ran.tools/files/wget
	echo "下载功能添加完毕"
	if [ ! -f /data/data/com.ran.tools/files/usr.data ];
	then
		echo "开始下载数据文件"
		wget -O /data/data/com.ran.tools/files/usr.data https://vincent-winner.github.io/resDL/com.ran.tools-usr.data --no-check-certificate
		echo "数据文件下载完毕"
		echo "开始解压数据"
		busybox sleep 1
		busybox tar -C /data/data/com.ran.tools/files -zxvf /data/data/com.ran.tools/files/usr.data
		rm -f /data/data/com.ran.tools/files/usr.data
		echo "数据解压完毕"
	else
		echo "数据文件未下载完成，正在继续下载"
		wget -c -O /data/data/com.ran.tools/files/usr.data https://vincent-winner.github.io/resDL/com.ran.tools-usr.data --no-check-certificate
		echo "数据文件下载完毕"
		echo "开始解压数据"
		busybox sleep 1
		busybox tar -C /data/data/com.ran.tools/files -zxvf /data/data/com.ran.tools/files/usr.data
		rm -f /data/data/com.ran.tools/files/usr.data
		echo "数据解压完毕"
	fi
#更改权限
echo "正在更改权限中"
chmod -R 4755 /data/data/com.ran.tools/files/usr
chmod -R 4755 /data/data/com.ran.tools/files/home
echo "权限修改完毕"
busybox sleep 2
busybox clear
fi