#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int folder_log()/*a*/
{
	printf("日志文件夹\n");
	system("export PATH=/data/data/com.ran/files:$PATH;busybox find /storage/emulated/0/ -name 'log' -type d -print -exec rm -rf {} \+");
}
int folder_cache()/*b*/
{
	printf("缓存文件夹\n");
	system("export PATH=/data/data/com.ran/files:$PATH;busybox find /storage/emulated/0/ -name 'cache' -type d -print -exec rm -rf {} \+");
}
int file_log()/*c*/
{
	printf("标准日志文件\n");
	system("export PATH=/data/data/com.ran/files:$PATH;busybox find /storage/emulated/0/ -name '*.log' -print -exec rm -rf {} \+");
}
int file_olog()/*d*/
{
	printf("另类日志文件\n");
	system("export PATH=/data/data/com.ran/files:$PATH;busybox find /storage/emulated/0/ -name '*log*' -type f -print -exec rm -rf {} \+");
}
int file_qlog()/*e*/
{
	printf("QQ日志\n");
	system("export PATH=/data/data/com.ran/files:$PATH;busybox find /storage/emulated/0/tencent/ -name '*.qlog' -type f -print -exec rm -rf {} \+");
	system("export PATH=/data/data/com.ran/files:$PATH;busybox find /storage/emulated/0/Tencent/ -name '*.qlog' -type f -print -exec rm -rf {} \+");
}
int file_apk()/*f*/
{
	printf("安装包\n");
	system("export PATH=/data/data/com.ran/files:$PATH;busybox find /storage/emulated/0/ -name '*.apk' -print -exec rm -rf {} \+");
}
int file_empty()/*g*/
{
	printf("空文件\n");
	system("export PATH=/data/data/com.ran/files:$PATH;busybox find /storage/emulated/0/ -type f -size 0 -print -exec rm -rf {} \+");
}
int file_tmp()/*h*/
{
	printf("临时文件\n");
	system("export PATH=/data/data/com.ran/files:$PATH;busybox find /storage/emulated/0/ -name 'cache' -type d -print -exec rm -rf {} \+");
}
int folder_baidu_netdisk()/*i*/
{
	printf("百度云下载\n");
	system("rm -rf /storage/emulated/0/BaiduNetdisk");
}
int folder_xunlei_download()/*j*/
{
	printf("迅雷下载\n");
	system("rm -rf /storage/emulated/0/Android/obb/com.xunlei.downloadprovider");
}
int file_thumbnail()/*k*/
{
	printf("应用图片缓存\n");
	system("export PATH=/data/data/com.ran/files:$PATH;busybox find /storage/emulated/0/ -name '.thumbnails' -type d -print -exec rm -rf {} \+");
}
int file_qq_png()/*l*/
{
	printf("QQpng文件\n");
	system("export PATH=/data/data/com.ran/files:$PATH;busybox find /storage/emulated/0/tencent/ -name '*.png' -print -exec rm -rf {} \+");
	system("export PATH=/data/data/com.ran/files:$PATH;busybox find /storage/emulated/0/Tencent/ -name '*.png' -print -exec rm -rf {} \+");
}

int main(int argc, char argv[])
{
	char optionsf[14];
	printf("输入选项按回车\n\n");
	printf("清理选项(多选):\n");	printf("日志文件夹....(a)\n缓存文件夹....(b)\n标准日志文件..(c)\n另类日志文件..(d)\nqq日志........(e)\n安装包........(f)\n空文件........(g)\n临时文件......(h)\n百度云下载....(i)\n迅雷下载......(j)\n应用图片缓存..(k)\n以上全选......(s)\n除迅雷百度云全选(v)\n\n");
	scanf("%s",optionsf);
	if (strchr(optionsf,'a') || strchr(optionsf,'b') || strchr(optionsf,'c') || strchr(optionsf,'d') || strchr(optionsf,'e') || strchr(optionsf,'f') || strchr(optionsf,'g') || strchr(optionsf,'h') || strchr(optionsf,'i') || strchr(optionsf,'j') || strchr(optionsf,'k') || strchr(optionsf,'l') || strchr(optionsf,'s') || strchr(optionsf,'v'))
	    {if (strchr(optionsf,'a'))
	    folder_log();
	    if (strchr(optionsf,'b'))
	    folder_cache();
	    if (strchr(optionsf,'c'))
	    file_log();
	    if (strchr(optionsf,'d'))
	    file_olog();
	    if (strchr(optionsf,'f'))
	    file_apk();
	    if (strchr(optionsf,'g'))
	    file_empty();
	    if (strchr(optionsf,'h'))
	    file_tmp();
	    if (strchr(optionsf,'i'))
	    folder_baidu_netdisk();
	    if (strchr(optionsf,'j'))
	    folder_xunlei_download();
	    if (strchr(optionsf,'k'))
	    file_thumbnail();
	    if (strchr(optionsf,'l'))
	    file_qq_png();
	    if (strchr(optionsf,'s'))
	    {folder_log();
	    folder_cache();
	    file_log();
	    file_olog();
	    file_apk();
	    file_empty();
	    file_tmp();
	    folder_baidu_netdisk();
	    folder_xunlei_download();
	    file_thumbnail();
	    file_qq_png();}
	    if (strchr(optionsf,'v'))
	    {folder_log();
	    folder_cache();
	    file_log();
	    file_olog();
	    file_apk();
	    file_empty();
	    file_tmp();
	    file_thumbnail();
	    file_qq_png();}}
	    else
	    {printf("参数错误:不在范围内\n");}
	    printf("#####################\n");
	    printf("        完成          \n");
	    printf("#####################\n");
	    return 0;
}