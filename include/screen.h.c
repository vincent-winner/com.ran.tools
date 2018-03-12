#include <stdlib.h>
#include <stdio.h>
const char apath[]="sh /data/data/com.ran.tools/files/addpath.sh;";
//清屏
int cls()
{
	system("/data/data/com.ran.tools/files/bin/clear");
}

//创建窗口并进入
int screen(char *pscreen_name)
{
	char *screen_name;
	char screen[100];
	screen_name = &*pscreen_name;
	sprintf(screen,"%sscreen -S %s",apath,screen_name);
	system(screen);
	return 1;
}

//创建后台窗口
int dscreen(char *pscreen_name)
{
	char *screen_name;
	char dscreen[100];
	screen_name = &*pscreen_name;
	sprintf(dscreen,"%sscreen -dmS %s",apath,screen_name);
	system(dscreen);
	return 1;
}

//进入一个窗口
int rscreen(char *pscreen_name)
{
	char *screen_name;
	char rscreen[100];
	screen_name = &*pscreen_name;
	sprintf(rscreen,"%sscreen -x %s",apath,screen_name);
	system(screen);
	return 1;
}

//退出一个窗口
int escreen(char *pscreen_name)
{
	char *screen_name;
	char escreen[100];
	screen_name = &*pscreen_name;
	sprintf(escreen,"%sscreen -d %s",apath,screen_name);
	system(escreen);
	return 1;
}

//向窗口发送信息
int cmdscreen(char *pscreen_name,char *)
{
	char *screen_name;
	char cmdscreen[100];
	screen_name = &*pscreen_name;
	sprintf(cmdscreen,"%sscreen -x %s -p 0 -X stuff \"%s\"",apath,screen_name,cmd);
	system(cmdscreen);
	return 1;
}

//向窗口发送一个回车
int enterscreen()
{
	
}

//指定窗口执行一个命令
int exescreen()
{
	
}