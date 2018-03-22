#include <stdio.h>
#include <stdlib.h>
int cls()
{
	system("/data/data/com.ran.tools/files/bin/clear");
}
int swap_sdcard_check()
{
	//system("cp -f ./resource/swap-sdcard-check.sh /data/data/com.ran.tools/files");
	//system("chmod 0755 /data/data/com.ran.tools/files/swap-sdcard-check.sh");
	system("sh /data/data/com.ran.tools/files/swap-sdcard-check.sh");
}
int swap_sdcard_on()
{
	system("su -c /data/data/com.ran.tools/files/usr/bin2/swapon /storage/sdcard1/swap/swapblock");
	printf("完成\n");
}
int swap_sdcard_off()
{
	system("su -c /data/data/com.ran.tools/files/usr/bin2/swapoff /storage/sdcard1/swap/swapblock");
	printf("完成\n");
}
int main()
{
	static int m;
	printf("正在检查swap分区\n");
	swap_sdcard_check();
	printf("完成\n\n");
	bb:printf("1.开启swap分区\n2.关闭swap分区\n3.删除swap分区\n\n");
	printf("输入选项(数字):\n");
	scanf("%d",&m);
	switch(m)
	{
		case 1:
			cls();
			swap_sdcard_on();
		break;
		case 2:
			cls();
			swap_sdcard_off();
		break;
		case 3:
			cls();
			system("/data/data/com.ran.tools/files/bin/swapoff /storage/sdcard1/swap/swapblock;rm -rf /storage/sdcard1/swap");
		break;
		default:
			cls();
			printf("发生错误，请检查选项输入是否错误，设备是否有root权限\n重新输入选项:");
			goto bb;
		break;
	}
}