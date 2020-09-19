#include<stdio.h>
//冒泡排序
int main(void){
	//创建数组 
	int a[10] = {1,4,7,3,6,49,5,67,89,10};
	for(int i = 0;i < 9;i++){//10个元素需要进行10-1=9轮比较 
		for(int j = 0;j < 9-i;j++){//每进行1轮比较就少一个需要比较的元素 先比较后加1 
			//如果前面的元素大就交换，保证右边的元素是最大的 
			if(a[j] > a[j+1]){
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for(int i = 0;i < 10;i++){
		printf("%d ",a[i]);
	}
	return 0;
} 
