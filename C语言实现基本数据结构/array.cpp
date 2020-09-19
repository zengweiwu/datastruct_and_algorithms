#include<stdio.h>
#include<malloc.h>
#include<stdlib.h> 
//��������ṹ��
struct array{
	int *pBase;
	int cnt;
	int len; 
}; 
//��������
void init_arr(struct array* pArr,int length);//��ʼ������ 
void show_arr(struct array* pArr);// ������麯��
bool is_empty(struct array* pArr);//�ж������Ƿ�Ϊ�պ��� 
bool is_full(struct array* pArr);//�ж������Ƿ���
bool apend_arr(struct array* pArr,int val);//�������׷��Ԫ�غ��� 
bool insert_arr(struct array* pArr,int pos,int val);//ָ��λ�ò���ֵ 
bool delete_arr(struct array* pArr,int pos,int* pVal);//ɾ��ָ��λ�õ�ֵ
void invert_arr(struct array* pArr);//�������麯�� 
void sort_arr(struct array* pArr);//���������� 
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
		printf("%dɾ���ɹ���\n",val);
	}
	else
	    printf("ɾ��ʧ�ܣ�");
	show_arr(&arr1); 
}
//��ʼ������ʵ�� 
void init_arr(struct array* pArr,int length){
	pArr->pBase = (int*)malloc(sizeof(int)*length);
	if(NULL == pArr->pBase){//�ж��ڴ��Ƿ����ɹ����������ɹ�����ִ�������ʼ������ 
		printf("��̬�����ڴ�ʧ�ܣ�");
		exit(-1);//�ڴ���䲻�ɹ���ֱ���˳����� 
	}
	else{
		pArr->len = length;
	    pArr->cnt = 0;
	}
}
//�ж������Ƿ�Ϊ�պ���ʵ��
bool is_empty(struct array* pArr){
	if(pArr->cnt == 0)
	    return true;
	else
	    return false;
} 
//�ж������Ƿ���ʵ��
bool is_full(struct array* pArr){
	if(pArr->cnt == pArr->len)
	    return true;
	else
	    return false;
} 
//������麯��ʵ��
void show_arr(struct array* pArr){
	if(is_empty(pArr)){
		printf("����Ϊ�գ�");
	}
	else{
		for(int i = 0;i < pArr->cnt;i++){
			printf("%d ",pArr->pBase[i]);//pBase������������׵�ַ 
		}
		printf("\n");
	}
	    
} 
//׷��Ԫ�غ�����ʵ�� 
bool apend_arr(struct array* pArr,int val){
	//��ʱ����false 
	if(is_full(pArr)){
		return false;
	}
	//����ʱ׷��Ԫ�ز�����true 
	else{
		pArr->pBase[pArr->cnt] = val;//Ϊʲô����cnt-1��������5��Ԫ��Ҫ׷�ӵĵ�6��Ԫ�ص��±����5 
		(pArr->cnt)++; 
		return true;
	}
}
//ָ��λ�ò���ֵ 
bool insert_arr(struct array* pArr,int pos,int val){//pos����СֵΪ1
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
//ɾ��ָ��λ�õ�Ԫ��
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
	pArr->cnt--;//�����������ɾ�����ǵö�cnt�������Ӧ�Ӽ� 
	return true;
} 
//�������麯��ʵ�� 
void invert_arr(struct array* pArr){
	int j = pArr->cnt-1;
    for(int i = 0;i <= j;i++,j--){
    	int temp = pArr->pBase[i]; 
    	pArr->pBase[i] = pArr->pBase[j];
    	pArr->pBase[j] = temp;
	}
} 
//����������ʵ�� 
void sort_arr(struct array* pArr){
    for(int i = 0;i <= pArr->cnt-2;i++){//�Ƚϵ�����������Ԫ�صĸ�����1 
    	for(int j = i+1;j <= pArr->cnt-1;j++){//���Ƚ�j��λ����һ��Ԫ�� 
    		if(pArr->pBase[i] < pArr->pBase[j]){
    			int temp = pArr->pBase[i];
    			pArr->pBase[i] = pArr->pBase[j];
    			pArr->pBase[j] = temp; 
			}
					}
	}
}     
