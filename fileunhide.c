#include <stdio.h>
#include <stdlib.h>
char file_pathi[100];
char file_patho[100];
char file_path[100];
char file_name[30];
char un_gz[200];
char un_bz2[200];
char rm_ungz[200];
char extract[200];
const char pathf[]="sh /data/data/com.ran.tools/files/addpath.sh;";
int cls()
{
	system("/data/data/com.ran.tools/files/bin/clear");
}
int information()
{
	printf("注意:如果出现中文乱码或无法输入中文的情况按以下方法处理\n第一步:点击右上角三个点\n第二步:选择第一项\"preferences\"\n第三步:找到UTF-8并打钩\n\n");
}
int input()
{
	printf("路径名末尾不要加\"/\"\n\n");
	printf("想要解包的文件名\n");
	scanf("%s",file_name);
	printf("请输入要解包的文件所在的文件夹(路径)\n");
	scanf("%s",file_pathi);
	printf("想要把文件解包哪里(路径)\n");
	scanf("%s",file_patho);
}
/*
int un_superzip_lv3()
{
	sprintf(un_gz,"%sgunzip -c %s/%s > %s/%s.ungz",pathf,file_pathi,file_name,file_patho,file_name);
	system(un_gz);
	sprintf(un_bz2,"%star -jxvf %s/%s.ungz -C %s/",pathf,file_patho,file_name,file_patho);
	system(un_bz2);
	sprintf(rm_ungz,"%srm -rf %s/%s.ungz",pathf,file_patho,file_name);
	system(rm_ungz);
	printf("文件已解包到指定位置");
}
*/
int unbz()
{
	sprintf(un_bz2,"%s/data/data/com.ran.tools/files/bin/tar -jxvf %s/%s -C %s",pathf,file_pathi,file_name,file_patho);
	system(un_bz2);
	printf("文件已解包到指定位置\n");
}
int ungz()
{
	sprintf(un_gz,"%s/data/data/com.ran.tools/files/bin/tar -zxvf %s/%s -C %s",pathf,file_pathi,file_name,file_patho);
	system(un_gz);
	printf("文件已解包到指定位置\n");
}
int unlz()
{
	sprintf(extract,"%s/data/data/com.ran.tools/files/bin/tar -C %s --lzop -xvf %s/%s",pathf,file_patho,file_pathi,file_name);
	system(extract);
	printf("文件已解压到指定位置\n");
}
int unlzma()
{
	sprintf(extract,"%s/data/data/com.ran.tools/files/bin/tar -C %s --lzma -xvf %s/%s",pathf,file_patho,file_pathi,file_name);
	system(extract);
	printf("文件已解压到指定位置\n");
}
int unxz()
{
	sprintf(extract,"%s/data/data/com.ran.tools/files/bin/tar -C %s --xz -xvf %s/%s",pathf,file_patho,file_pathi,file_name);
	system(extract);
	printf("文件已解压到指定位置\n");
}
int unzip()
{
	sprintf(extract,"%s/data/data/com.ran.tools/files/bin/7z x -tzip %s/%s -o%s",pathf,file_pathi,file_name,file_patho);
	system(extract);
	printf("文件已解压到指定位置\n");
}
int un7z()
{
	sprintf(extract,"%s/data/data/com.ran.tools/files/bin/7z x %s/%s -o%s",pathf,file_pathi,file_name,file_patho);
	system(extract);
	printf("文件已解压到指定位置\n");
}
int unrar()
{
	sprintf(extract,"%s/data/data/com.ran.tools/files/bin/unrar x %s/%s %s/",pathf,file_pathi,file_name,file_patho);
	system(extract);
	printf("文件已解压到指定位置\n");
}
int untar()
{
	sprintf(extract,"%s/data/data/com.ran.tools/files/bin/tar -C %s -xvf %s/%s",pathf,file_patho,file_pathi,file_name);
	system(extract);
	printf("文件已解包到指定位置\n");
}
int main()
{
	int option;
	information();
	printf("要解包的文件类型:\n");
	printf("0.\"tar\"\n");
	printf("1.\"tar.lz\"(tlz)\n");
	printf("2.\"zip\"\n");
	printf("3.\"tar.gz\"(tgz)n");
	printf("4.\"tar.bz2\"(tbz)\n");
	printf("5.\"7z\"\n");
	printf("6.\"tar.lzma\"(tlzma)\n");
	printf("7.\"tar.xz\"(txz)\n");
	printf("8.\"rar\"\n\n");
	printf("输入选项(数字):");
	scanf("%d",&option);
	switch(option)
	{
		case 0:
			cls();
			input();
			untar();
		break;
		case 1:
			cls();
			input();
			unlz();
		break;
		case 2:
			cls();
			input();
			unzip();
		break;
		case 3:
			cls();
			input();
			ungz();
		break;
		case 4:
			cls();
			input();
			unbz();
		break;
		case 5:
			cls();
			input();
			un7z();
		break;
		case 6:
			cls();
			input();
			unlzma();
		break;
		case 7:
			cls();
			input();
			unxz();
		break;
		case 8:
			cls();
			input();
			unrar();
		break;
		default:
			cls();
			printf("错误的选项");
		break;
	}
}