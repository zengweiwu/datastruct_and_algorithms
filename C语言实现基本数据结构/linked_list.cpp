#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//����ڵ����� 
typedef struct Node{
	int date;
	struct Node* pNext;
}NODE,*PNODE;
 
PNODE create_list(void);//����������
void traverse_list(PNODE pHead);//�������� 
bool is_empty(PNODE pHead);//�ж������Ƿ�Ϊ�� 
int length_list(PNODE pHead);//��������ĳ��� 
void sort_list(PNODE pHead);//������������ 
bool insert_list(PNODE pHead);//ָ��λ��ǰ����Ԫ��
bool apend_list(PNODE pHead);//������ĩβ׷��Ԫ�� 
bool delete_list(PNODE pHead,int*pv);//ɾ��ָ�����
 
 
int main(void){
	PNODE pHead = NULL;
	pHead = create_list();
	traverse_list(pHead);
	
	int j = length_list(pHead);
	printf("����ĳ���Ϊ��%d\n",j);
	
	sort_list(pHead);
	printf("������������Ϊ��");
	traverse_list(pHead);
	
	//insert_list(pHead);
	//traverse_list(pHead);
	
	int val; 
	delete_list(pHead,&val);
    traverse_list(pHead);
    printf("ɾ����Ԫ���ǣ�%d\n",val);
    
    //apend_list(pHead);
	//traverse_list(pHead);
	
	int l = length_list(pHead);
	printf("����ĳ���Ϊ��%d\n",l); 
	return 0;
}
//��������ʵ�� 
PNODE create_list(void){
	int len;
	int val;
	PNODE pHead = NULL;//����ͷ���ָ�� 
	pHead = (PNODE)malloc(sizeof(NODE));//Ϊͷ�������ڴ�
	if(pHead == NULL){
		printf("�ڴ����ʧ�ܣ�"); 
	}
	PNODE pTail = pHead;//ֻ��һ��Ԫ��ʱͷ���β������Լ����� 
	pTail->pNext = NULL;//β����ָ����Ϊ�� 
	printf("������Ҫ����������Ľ�������");
	scanf("%d",&len);
	for(int i = 0;i < len;i++){
		printf("�������%d������ֵ��",i+1);
		scanf("%d",&val);//�����ֵ��ʱ�洢�ڱ���val��
		PNODE pNew = (PNODE)malloc(sizeof(NODE));//����һ���½����ڴ�ռ�
		if(pNew == NULL){
			printf("����ʧ�ܣ�������ֹ��\n");
			exit(-1);
		} 
		pNew->date = val;//����ʱ������val�е�ֵ������������������
		pTail->pNext = pNew;//���½��ĵ�ַ������һ������ָ����ע�ⲻ�ܸ���ͷ��㣬ͷ��㲻�ܱ� 
		pNew->pNext = NULL;
		pTail = pNew;//ÿ�������½��ͷ��㲻�ܶ���������β��� 	
	}
	 return pHead;
}

//��������ʵ�� 
void traverse_list(PNODE pHead){
    PNODE p = pHead->pNext;//��һ��ָ��������洢��һ����Ч��㣨���׽ڵ㣩�ĵ�ַ
    while(p != NULL){
    	printf("%d ",p->date);
    	p = p->pNext;
	}
	/*for(int i = 1;p != NULL;i++){
		printf("%d ",p->date);//������������� 
		p = p->pNext;//�������һ�����ĵ�ַ��ֵ��p 
	}*/
	printf("\n");
}

//�ж������Ƿ�Ϊ�պ���ʵ��
bool is_empty(PNODE pHead){
	if(pHead->pNext == NULL)
	    return true;
	else
	    return false;
}

//���������Ⱥ���ʵ��
int length_list(PNODE pHead){
	PNODE p = pHead->pNext;
	int i = 0;
	while(p != NULL){
	    i++;
		p = p->pNext;
	}
	return i;
}

//������������ʵ�֣��������ѡ������ʵ�֣� 
void sort_list(PNODE pHead){
	int i,j,t;//�������潻���ı��� 
	int len = length_list(pHead);//��ȡ����ĳ��� 
	PNODE p,q;
	//��Ҫ��forѭ����������������Ϊ����趺�ź����ָ�뱻����Ϊ�������������� 
	for(i = 0,p = pHead->pNext;i < len-1;i++,p = p->pNext){//�Ƚϵ�������Ԫ�صĸ�����1 
		for(j = i+1,q = p->pNext;j < len;j++,q = q->pNext){//q = q->pNext�ȼ���j++����ַ������ƶ���һλ 
			if(p->date > q->date){
			t = p->date;//t = a[i]
			p->date = q->date;//a[i] = a[j];
			q->date = t;//a[j] = t;
			}	
		}
	}
	return; 
}

//ָ��λ�ò���Ԫ��ʵ��
bool insert_list(PNODE pHead){
	int pos,val;//����Ҫ�����λ�ú�ֵ 
	//�жϲ���λ���Ƿ񳬳������� 
	printf("��������Ҫ�������λ��:");
	scanf("%d",&pos);
	if(pos > length_list(pHead)){
		printf("���������ȣ�\n");
		return false;
	}
	//��ȡҪ�����ֵ
	printf("������Ҫ�����ֵ��");
	scanf("%d",&val);
	//����Ҫ����Ľ��
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL){
		printf("��̬�����ڴ�ʧ�ܣ�");
		exit(-1);
	}
	pNew->date = val;
	//�ҵ�Ҫ�����λ�õ���һ�����ĵ�ַ 
	PNODE p = pHead->pNext;
	//���׽ڵ�ǰ���� 
	if(pos == 1){
		pNew->pNext = pHead->pNext;
		pHead->pNext = pNew;
		return true;//������ڵ�һ�����룬����ִ�е�����͸�return��������ִ���������� 
	}
	for(int i = 1;i < pos-1;i++){
		p = p->pNext;
	}
	//������ 
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}

//ɾ��ָ�����ʵ�� 
bool delete_list(PNODE pHead,int*pv){
	//��ȡҪɾ���Ľ����� 
    int pos;
    printf("������Ҫɾ��������ţ�");
	scanf("%d",&pos); 
	//�ҵ�Ҫɾ������ǰһ�����
	PNODE p = pHead; 
	for(int i = 1;i < pos;i++){
		p = p->pNext;
	}
	//ɾ����㲢�ͷ��ڴ� 
	PNODE r = p->pNext;
	*pv = r->date;
	p->pNext = p->pNext->pNext;
	free(r);
	r = NULL;
}

//����ĩβ׷��Ԫ�� 
bool apend_list(PNODE pHead){
	//��ȡҪ׷�ӵ�Ԫ�� 
    int val;
    printf("������Ҫ׷�ӵ�ֵ��");
	scanf("%d",&val);
	//����Ҫ׷�ӵĽ��
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL){
		printf("��̬�����ڴ�ʧ�ܣ�");
		exit(-1);
	}
	pNew->date = val;
	//�ҵ�β��� 
	int i = 0;
	PNODE p = pHead;
	while(p->pNext != NULL){
		p = p->pNext;
	}
	//��׷�ӽ��ָ����ֵNULLȻ��׷��Ԫ�� 
	pNew->pNext = NULL;
	p->pNext = pNew;
} 
