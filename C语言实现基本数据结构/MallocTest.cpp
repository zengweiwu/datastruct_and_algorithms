#include<stdio.h>
#include<malloc.h>
int main(void){
	int a[5]  = {1,2,3,4,5};//��̬�����ڴ� �������й������ڴ治���Ըı� 
	int len;
	printf("��������Ҫ�����鳤��len = ");
	scanf("%d",&len);
	int* pArr = (int*)malloc(sizeof(int)*len);
	*pArr = 6;
	pArr[1] = 7;//pArr[1]�ȼ���*(pArr+1) 
	printf("%d %d",*pArr,pArr[1]);
} 
