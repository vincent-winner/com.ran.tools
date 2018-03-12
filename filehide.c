#include <stdio.h>
#include <stdlib.h>
char file_tgz[200];
char rename_mv_tgz[200];
char file_pathi[200];
char file_patho[200];
char file_name[30];
char file_tbz2_gz[200];
char rename_mv_tbz2_gz[200];
char file_tbz2[200];
char file_lzma[200];
char file_tar[100];
char rename_mv_tbz2[200];
char file_lz[200];
char file_xz[200];
char file_zip[200];
char file_7z[200];
char yos;
char passwd[100];
const char pathf[]="sh ./data/data/com.ran.tools/files/addpath.sh;";
int cls()
{
	system("/data/data/com.ran.tools/files/bin/clear");
}
int input_()
{
	printf("路径名末尾不要加\"/\"\n\n");
	printf("请输入要处理的文件夹(路径)\n");
	scanf("%s",file_pathi);
	printf("想要把输出文件放在哪里(路径)\n");
	scanf("%s",file_patho);
	printf("给输出文件起个名字\n");
	scanf("%s",file_name);
}
int information()
{
	printf("压缩率越高，压缩文件越小，但耗费的时间会增多\n\n");
	printf("在使用之前请做如下处理\n");
	printf("第一步:把要处理的文件放到一个文件夹中\n");
	printf("第二步:记住这个文件夹的路径\n\n");
	printf("注意:如果出现中文乱码或无法输入中文的情况按以下方法处理\n第一步:点击右上角三个点\n第二步:选择第一项\"preferences\"\n第三步:找到UTF-8并打钩\n\n");
}
/*
int tb2g()
{
	sprintf(file_tbz2,"%star -jcvf %s.tbz2 %s",pathf,file_name,file_pathi);
	system(file_tbz2);
	sprintf(file_tbz2_gz,"%sgzip %s.tbz2",pathf,file_name);
	system(file_tbz2_gz);
	sprintf(rename_mv_tbz2_gz,"%smv %s.tbz2.gz %s/%s.tb2g",pathf,file_name,file_patho,file_name);
	system(rename_mv_tbz2_gz);
	printf("文件已压缩到指定位置");
}
*/
int bz()
{
	sprintf(file_tbz2,"%s/data/data/com.ran.tools/files/bin/tar -jcvf %s.tbz2 %s",pathf,file_name,file_pathi);
	system(file_tbz2);
	sprintf(rename_mv_tbz2,"%smv %s.tbz2 %s",pathf,file_name,file_patho);
	system(rename_mv_tbz2);
	printf("文件已压缩到指定位置");
}
int gz()
{
	sprintf(file_tgz,"%s/data/data/com.ran.tools/files/bin/tar -zcvf %s.tgz %s",pathf,file_name,file_pathi);
	system(file_tgz);
	sprintf(rename_mv_tgz,"%smv %s.tgz %s",pathf,file_name,file_patho);
	system(rename_mv_tgz);
	printf("文件已压缩到指定位置");
}
int lz()
{
	sprintf(file_lz,"%s/data/data/com.ran.tools/files/bin/tar --lzop -cvf %s/%s.tar.lz %s",pathf,file_patho,file_name,file_pathi);
	system(file_lz);
}
int lzma()
{
	sprintf(file_lzma,"%s/data/data/com.ran.tools/files/bin/tar --lzma -cvf %s/%s.tar.lzma %s",pathf,file_patho,file_name,file_pathi);
	system(file_lzma);
	
}
int xz()
{
	sprintf(file_xz,"%s/data/data/com.ran.tools/files/bin/tar --xz -cvf %s/%s.tar.xz %s",pathf,file_patho,file_name,file_pathi);
	system(file_xz);
	printf("文件已压缩到指定位置\n");
}
int zip()
{
	printf("是否需要密码(y/n):\n");
	scanf("%s",&yos);
	switch(yos)
	{
		case 'y':
		scanf("%s",passwd);
		sprintf(file_zip,"%s/data/data/com.ran.tools/files/bin/7z -tzip a -p%s %s/%s.zip %s/",pathf,passwd,file_patho,file_name,file_pathi);
		break;
		case 'Y':
		scanf("%s",passwd);
		sprintf(file_zip,"%s/data/data/com.ran.tools/files/bin/7z -tzip a -p%s %s/%s.zip %s/",pathf,passwd,file_patho,file_name,file_pathi);
		break;
		case 'n':
		sprintf(file_zip,"%s/data/data/com.ran.tools/files/bin/7z -tzip a %s/%s.zip %s/",pathf,file_patho,file_name,file_pathi);
		break;
		case 'N':
		sprintf(file_zip,"%s/data/data/com.ran.tools/files/bin/7z -tzip a %s/%s.zip %s/",pathf,file_patho,file_name,file_pathi);
		break;
		default:
		cls();
		printf("错误的选项\n");
		return 1;
		break;
	}
	system(file_zip);
	printf("文件已压缩到指定位置\n");
}
int _7z()
{
	printf("是否需要密码(y/n):\n");
	scanf("%s",&yos);
	switch(yos)
	{
		case 'y':
		printf("输入密码:\n");
		scanf("%s",passwd);
		sprintf(file_7z,"%s/data/data/com.ran.tools/files/bin/7z a -p%s %s/%s.7z %s/",pathf,passwd,file_patho,file_name,file_pathi);
		break;
		case 'Y':
		scanf("%s",passwd);
		sprintf(file_7z,"%s/data/data/com.ran.tools/files/bin/7z a -p%s %s/%s.7z %s/",pathf,passwd,file_patho,file_name,file_pathi);
		break;
		case 'n':
		sprintf(file_7z,"%s/data/data/com.ran.tools/files/bin/7z a %s/%s.7z %s/",pathf,file_patho,file_name,file_pathi);
		break;
		case 'N':
		sprintf(file_7z,"%s/data/data/com.ran.tools/files/bin/7z a %s/%s.7z %s/",pathf,file_patho,file_name,file_pathi);
		break;
		default:
		cls();
		printf("错误的选项\n");
		return 1;
		break;
	}
	system(file_7z);
	printf("文件已压缩到指定位置\n");
}
int tar()
{
	sprintf(file_tar,"%s/data/data/com.ran.tools/files/bin/tar -cvf %s/%s.tar %s",pathf,file_patho,file_name,file_pathi);
	system(file_tar);
	printf("已将文件打包到指定位置\n");
}
int main()
{
	int option;
	information();
	printf("文件压缩过程可能较慢，请耐心等待\n");
	printf("###选项按压缩率从小到大排列###\n输入选项(数字):\n");
	printf("0.使用\"tar\"打包(无压缩)\n");
	printf("1.使用\"lzip\"压缩\n");
	printf("2.使用\"zip\"压缩\n");
	printf("3.使用\"gzip\"压缩\n");
	printf("4.使用\"bzip2\"压缩\n");
	printf("5.使用\"7zip\"压缩\n");
	printf("6.使用\"lzma\"压缩\n");
	printf("7.使用\"xz\"压缩\n\n");
	scanf("%d",&option);
	switch(option)
	{
		case 0:
			cls();
			input_();
			tar();
		break;
		case 1:
			cls();
			input_();
			lz();
		break;
		case 2:
			cls();
			input_();
			zip();
		break;
		case 3:
			cls();
			input_();
			gz();
		break;
		case 4:
			cls();
			input_();
			bz();
		break;
		case 5:
			cls();
			input_();
			_7z();
		break;
		case 6:
			cls();
			input_();
			lzma();
		break;
		case 7:
			cls();
			input_();
			xz();
		break;
		default:
			cls();
			printf("错误的选项");
		break;
	}
}