#include<stdio.h>
//插入排序 
int main(void){
	int a[6] = {1,5,3,7,9,4};
	
	int i,j;
	for(i = 1;i < 6;i++){//从第二个元素开始比较 
		int tmp = a[i];//将要插入的元素保存起来
		//找到需要插入的位置 
		for(j = i;j>0 && a[j-1]>tmp;j--){
			a[j] = a[j-1];
		}
	a[j] = tmp;//将保存的值插入找到的位置 然后进行下一轮找位置 
	}
	//输出排序后的数组 
	for(int i=0;i<6;i++){
		printf("%d ",a[i]);
	}
} 
