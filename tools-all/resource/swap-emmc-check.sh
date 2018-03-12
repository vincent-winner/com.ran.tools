#!/system/bin/sh
export PATH=/data/data/com.ran.tools/files/bin:/data/data/com.ran.tools/files:$PATH
if [ ! -d /data/data/com.ran.tools/files/swap ];
then
mkdir /data/data/com.ran.tools/files/swap
busybox chmod 4777 /data/data/com.ran.tools/files/swap
fi
if [ ! -f /data/data/com.ran.tools/files/swap/swapblock ];
then
echo '未找到swap分区文件'
echo '是否创建swap分区文件(y/n)'
read yesorno
else
echo "swap分区文件已存在"
fi
if [ "$yesorno" == "y" ];
then
echo '输入想要创建分区文件的大小(MB)'
read size
busybox dd if=/dev/zero of=/data/data/com.ran.tools/files/swap/swapblock bs=1M count=$size
busybox chmod 4777 /data/data/com.ran.tools/files/swap/swapblock
busybox mkswap /data/data/com.ran.tools/files/swap/swapblock
echo "分区文件创建完成，文件大小\"${size}M\""
elif [ "$yesorno" == "n" ];
then
echo "操作取消"
fi