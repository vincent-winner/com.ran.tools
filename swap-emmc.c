#include <stdio.h>
#include <stdlib.h>
int cls()
{
	system("/data/data/com.ran.tools/files/bin/clear");
}
int swap_emmc_check()
{
	//system("cp -f ./resource/swap-emmc-check.sh /data/data/com.ran.tools/files");
	//system("chmod 0755 /data/data/com.ran.tools/files/swap-emmc-check.sh");
	system("sh /data/data/com.ran.tools/files/swap-emmc-check.sh");
}
int swap_emmc_on()
{
	system("su -c /data/data/com.ran.tools/files/usr/bin2/swapon /data/data/com.ran.tools/files/swap/swapblock");
	printf("完成\n");
}
int swap_emmc_off()
{
	system("su -c /data/data/com.ran.tools/files/usr/bin2/swapoff /data/data/com.ran.tools/files/swap/swapblock");
	printf("完成\n");
}
int main()
{
	static char v;
	printf("正在检查swap分区\n");
	swap_emmc_check();
	printf("完成\n\n");
	choose:printf("1.开启swap分区\n2.关闭swap分区\n3.删除swap分区\n\n");
	printf("输入选项(数字):\n");
	scanf("%s",&v);
	switch(v)
	{
		case '1':
			cls();
			swap_emmc_on();
		break;
		case '2':
			cls();
			swap_emmc_off();
		break;
		case '3':
			cls();
			system("/data/data/com.ran.tools/files/bin/swapoff /data/data/com.ran.tools/files/swap/swapblock;rm -rf /data/data/com.ran.tools/files/swap");
		break;
		default:
			cls();
			printf("发生错误，请检查选项输入是否错误，设备是否有root权限\n");
			printf("请重新输入选项\n");
			goto choose;
		break;
	}
}