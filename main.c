#include <stdio.h>
#include <stdlib.h>
int cls()
{
	system("/data/data/com.ran.tools/files/usr/bin/clear");
}
int szip()
{
	static int n;
	printf("1.制作特殊压缩文件\n");
	printf("2.解压特殊压缩文件\n\n");
	printf("输入选项(数字):\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			cls();
			system("/data/data/com.ran.tools/files/usr/bin2/filehide");
		break;
		case 2:
			cls();
			system("/data/data/com.ran.tools/files/usr/bin2/fileunhide");
		break;
		default:
			cls();
			printf("错误的选项");
		break;
	}
}
int swap()
{
	static int a;
	printf("1.内部存储swap分区\n");
	printf("2.SD卡swap分区\n\n");
	printf("输入选项(数字):\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			cls();
			system("/data/data/com.ran.tools/files/usr/bin2/swap-emmc");
		break;
		case 2:
			cls();
			system("/data/data/com.ran.tools/files/usr/bin2/swap-sdcard");
		break;
		default:
			cls();
			printf("错误的选项\n");
		break;
	}
}
int zdmnq()
{
	static int zd;
	printf("1.shell\n");
	printf("2.Python2.7\n");
	printf("3.Python3.6\n");
	printf("4.bash\n\n");
	scanf("%d",&zd);
	switch(zd)
	{
		case 1:
		cls();
		system("/data/data/com.ran.tools/files/addpath.sh;/system/bin/sh");
		break;
		case 2:
		cls();
		system("/data/data/com.ran.tools/files/addpath.sh;python2");
		break;
		case 3:
		cls();
		system("/data/data/com.ran.tools/files/addpath.sh;python");
		break;
		case 4:
		system("/data/data/com.ran.tools/files/addpath.sh;bash");
		break;
		default:
		cls();
		printf("错误的选项");
		break;
	}
}
int main()
{
	static int x;
	system("mv ./resource/*.sh /data/data/com.ran.tools/files");
	system("chmod 0755 /data/data/com.ran.tools/files/*.sh");
	system("sh /data/data/com.ran.tools/files/checkbin.sh");
	printf("!!!!!带'*'的选项需要root权限!!!!!\n\n");
	signone:printf("1.清理内部存储空间\n");
	printf("2.清理运行内存\n");
	printf("3.文件特殊处理\n");
	printf("4.网络工具\n");
	printf("5.终端模拟器\n");
	printf("6.swap分区*\n");
	printf("7.帮助\n\n");
	printf("输入选项(数字):\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			cls();
			system("/data/data/com.ran.tools/files/usr/bin2/emmcclr");
		break;
		case 2:
			cls();
			system("/data/data/com.ran.tools/files/usr/bin2/memclr");
		break;
		case 3:
			cls();
			szip();
		break;
		case 4:
			cls();
			system("/data/data/com.ran.tools/files/usr/bin2/net_tool");
		break;
		case 5:
			cls();
			zdmnq();
		break;
		case 6:
			cls();
			swap();
		break;
		case 7:
			cls();
			system("/data/data/com.ran.tools/files/usr/bin/cat ./resource/readme");
		break;
		default:
			cls();
			printf("错误的选项,请重新输入");
			goto signone;
		break;
	}
}