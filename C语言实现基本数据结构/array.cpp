#include<stdio.h>
#include<malloc.h>
#include<stdlib.h> 
//定义数组结构体
struct array{
	int *pBase;
	int cnt;
	int len; 
}; 
//函数声明
void init_arr(struct array* pArr,int length);//初始化函数 
void show_arr(struct array* pArr);// 输出数组函数
bool is_empty(struct array* pArr);//判断数组是否为空函数 
bool is_full(struct array* pArr);//判断数组是否满
bool apend_arr(struct array* pArr,int val);//向数组后追加元素函数 
bool insert_arr(struct array* pArr,int pos,int val);//指定位置插入值 
bool delete_arr(struct array* pArr,int pos,int* pVal);//删除指定位置的值
void invert_arr(struct array* pArr);//倒置数组函数 
void sort_arr(struct array* pArr);//数组排序函数 
int main (void){
	int val;
	struct array arr1;
	init_arr(&arr1,6);
	apend_arr(&arr1,9);
	apend_arr(&arr1,6);
	apend_arr(&arr1,7);
	show_arr(&arr1);
	invert_arr(&arr1);
	show_arr(&arr1);
	insert_arr(&arr1,3,100);
    show_arr(&arr1);
    sort_arr(&arr1);
    show_arr(&arr1);
	if(delete_arr(&arr1,1,&val)){
		printf("%d删除成功！\n",val);
	}
	else
	    printf("删除失败！");
	show_arr(&arr1); 
}
//初始化函数实现 
void init_arr(struct array* pArr,int length){
	pArr->pBase = (int*)malloc(sizeof(int)*length);
	if(NULL == pArr->pBase){//判断内存是否分配成功，如果分配成功则再执行下面初始化步骤 
		printf("动态分配内存失败！");
		exit(-1);//内存分配不成功则直接退出程序 
	}
	else{
		pArr->len = length;
	    pArr->cnt = 0;
	}
}
//判断数组是否为空函数实现
bool is_empty(struct array* pArr){
	if(pArr->cnt == 0)
	    return true;
	else
	    return false;
} 
//判断数组是否满实现
bool is_full(struct array* pArr){
	if(pArr->cnt == pArr->len)
	    return true;
	else
	    return false;
} 
//输出数组函数实现
void show_arr(struct array* pArr){
	if(is_empty(pArr)){
		printf("数组为空！");
	}
	else{
		for(int i = 0;i < pArr->cnt;i++){
			printf("%d ",pArr->pBase[i]);//pBase保存了数组的首地址 
		}
		printf("\n");
	}
	    
} 
//追加元素函数的实现 
bool apend_arr(struct array* pArr,int val){
	//满时返回false 
	if(is_full(pArr)){
		return false;
	}
	//不满时追加元素并返回true 
	else{
		pArr->pBase[pArr->cnt] = val;//为什么不是cnt-1？假如有5个元素要追加的第6个元素的下标就是5 
		(pArr->cnt)++; 
		return true;
	}
}
//指定位置插入值 
bool insert_arr(struct array* pArr,int pos,int val){//pos的最小值为1
    if(is_full(pArr))
	    return false;
	if(pos < 1 || pos > pArr->cnt+1)
	    return false; 
    int i;
    for(i = pArr->cnt-1;i >= pos-1;i--){
    	pArr->pBase[i+1] = pArr->pBase[i];
	}
		pArr->pBase[pos-1] = val;
	    pArr->cnt++;
	    return true;
} 
//删除指定位置的元素
bool delete_arr(struct array* pArr,int pos,int* pVal){
	if(is_empty(pArr))
	   return false;
	if(pos < 1 || pos > pArr->cnt)
	    return false; 
	*pVal = pArr->pBase[pos-1];
    int i;
    for(i = pos-1;i < pArr->cnt;i++){
    	pArr->pBase[i] = pArr->pBase[i+1]; 
	}
	pArr->cnt--;//对数组进行增删操作记得对cnt进行相对应加减 
	return true;
} 
//倒置数组函数实现 
void invert_arr(struct array* pArr){
	int j = pArr->cnt-1;
    for(int i = 0;i <= j;i++,j--){
    	int temp = pArr->pBase[i]; 
    	pArr->pBase[i] = pArr->pBase[j];
    	pArr->pBase[j] = temp;
	}
} 
//数组排序函数实现 
void sort_arr(struct array* pArr){
    for(int i = 0;i <= pArr->cnt-2;i++){//比较的轮数比现有元素的个数少1 
    	for(int j = i+1;j <= pArr->cnt-1;j++){//首先将j定位到后一个元素 
    		if(pArr->pBase[i] < pArr->pBase[j]){
    			int temp = pArr->pBase[i];
    			pArr->pBase[i] = pArr->pBase[j];
    			pArr->pBase[j] = temp; 
			}
					}
	}
}     
