#include<stdio.h>
#include<stdlib.h>
int mem_clear()
{    
    int *a;
    while(1)
         a=(int *)malloc(500*sizeof(int));
}
int main(int argc, char *argv[])
{
	printf("2秒后释放运存行内存\n");
	system("sleep 2");
	printf("写入内存中.................\n");
	system("sleep 2");
	printf("清理内存中.................\n");
	printf("键盘消失或出现“killed”清理完成\n");
	mem_clear();
	return 1;
}