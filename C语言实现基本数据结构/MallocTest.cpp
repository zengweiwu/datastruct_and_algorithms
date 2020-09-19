#include<stdio.h>
#include<malloc.h>
int main(void){
	int a[5]  = {1,2,3,4,5};//静态分配内存 程序运行过程中内存不可以改变 
	int len;
	printf("请输入想要的数组长度len = ");
	scanf("%d",&len);
	int* pArr = (int*)malloc(sizeof(int)*len);
	*pArr = 6;
	pArr[1] = 7;//pArr[1]等价于*(pArr+1) 
	printf("%d %d",*pArr,pArr[1]);
} 
