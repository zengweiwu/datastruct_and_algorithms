#include<stdio.h>

//快速排序
void quick_sort(int* a,int low,int high);
int find_post(int* a,int low,int high);
int main(void){
	int a[7] = {5,2,4,6,8,9,7};
	
	quick_sort(a,0,6);
	
	for(int i = 0;i < 7;i++){
		printf("%d ",a[i]);
	}
	return 0;
}

void quick_sort(int* a,int low,int high){
	int post;
	if(low < high){//这里其实是递归出口 
	    post = find_post(a,low,high);
		quick_sort(a,low,post-1);//对post左边的数排序 
		quick_sort(a,post+1,high);//对post右边的数排序 
	}
}

//找位置函数实现
int find_post(int* a,int low,int high){
	int val = a[low];//先把low位置的元素保存起来 
	
	while(low < high){
	    while(low < high && a[high] >= val){
		    --high;//如果high位置的值大于val则high向前移一位 
	    }
	    a[low] = a[high];//不满足则将high位置的值给low
	
	    while(low < high && a[low] <= val){
		    ++low;
	    } 
	    a[high] = a[low];
	}//终止循环时low和high的值一定是相等的
	a[low] = val;//找到位置把原先的元素放进去 
	return low; 
} 
 
