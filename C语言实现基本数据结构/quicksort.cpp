#include<stdio.h>

//��������
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
	if(low < high){//������ʵ�ǵݹ���� 
	    post = find_post(a,low,high);
		quick_sort(a,low,post-1);//��post��ߵ������� 
		quick_sort(a,post+1,high);//��post�ұߵ������� 
	}
}

//��λ�ú���ʵ��
int find_post(int* a,int low,int high){
	int val = a[low];//�Ȱ�lowλ�õ�Ԫ�ر������� 
	
	while(low < high){
	    while(low < high && a[high] >= val){
		    --high;//���highλ�õ�ֵ����val��high��ǰ��һλ 
	    }
	    a[low] = a[high];//��������highλ�õ�ֵ��low
	
	    while(low < high && a[low] <= val){
		    ++low;
	    } 
	    a[high] = a[low];
	}//��ֹѭ��ʱlow��high��ֵһ������ȵ�
	a[low] = val;//�ҵ�λ�ð�ԭ�ȵ�Ԫ�طŽ�ȥ 
	return low; 
} 
 
