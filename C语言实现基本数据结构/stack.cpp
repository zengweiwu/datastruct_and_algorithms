#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//ע��ջ��������β��� ջ��������ͷ��� ָ���Ǵ�������ָ ����ѹջ��ջ���������ɾ��������ͬ 
//����ڵ� 
typedef struct Node {
	int data;
	struct Node* pNext;
}NODE,*PNODE;
//����ջ 
typedef struct Stack{
	PNODE pTop;//ָ��ջ�� 
	PNODE pBottom;//ָ��ջ�� 
}STACK,*PSTACK;

void init_stack(PSTACK pStack);//��ʼ��ջ 
void push(PSTACK pStack,int val);//ѹջ ����Ҫ����ֵһ������ѹջ�ɹ�
bool pop(PSTACK pStack,int* pVal);//��ջ 
void traverse_stack(PSTACK pStack);//����ջ 
bool is_empty(PSTACK pStack);//�ж��Ƿ�Ϊ��ջ
void clear(PSTACK pStack);//���ջ 

int main(void){
	STACK stack;
	init_stack(&stack);
	PSTACK p = &stack;
	
	push(&stack,1);
    push(&stack,2);
    push(&stack,5);

    traverse_stack(&stack);
    printf("\n");
    int val;
    if(pop(&stack,&val)){
        printf("��ջ�ɹ�!��ջ��Ԫ���ǣ�%d\n",val);	
	}
	else
	    printf("��ջʧ�ܣ�\n");
	
	traverse_stack(&stack);
	printf("\n");
	
	clear(&stack);
	traverse_stack(&stack);
	//printf("ջ�ĵ�һ�����ǣ�%d\n",p->pTop->data);
	return 0;
}

//��ʼ��ջ 
void init_stack(PSTACK pStack){
    //���������ͷ���
	pStack->pTop = (PNODE)malloc(sizeof(NODE));
	if(pStack->pTop == NULL){
		printf("�����ڴ�ʧ�ܣ�������ֹ!");
		exit(-1);
	}
	pStack->pTop->pNext = NULL;
	//ջ�Ķ�ָ��ָ��ջ����βָ��ָ��ջ�� 
	pStack->pBottom = pStack->pTop;
	return;
}

//ѹջ
void push(PSTACK pStack,int val){
	//������Ҫѹ��Ľ��
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = NULL;
	//���� 
	pNew->pNext = pStack->pTop;//ָ��Ҫ����ָ���½���ָ���������ָ����һ����� 
	pStack->pTop = pNew;//��ջ��ָ������ƶ�һ��
	return; 
}

//����ջ 
void traverse_stack(PSTACK pStack){
    PNODE p = pStack->pTop;//����ջ��ָ�� 
    if(p->pNext == NULL){
    	printf("����Ϊ�գ�\n");
	}
    while(p->pNext != NULL){
    	printf("%d ",p->data);//����������Ԫ�����ƶ�ָ�� 
    	p = p->pNext;
	}
	return;
}

//�ж��Ƿ��ǿ�ջ 
bool is_empty(PSTACK pStack){
    //ջ��ָ�����ջ��ָ�뼴ջΪ�� 
	if(pStack->pTop == pStack->pBottom)
	    return true;
	else
	    return false;
}

//��ջ
bool pop(PSTACK pStack,int* pVal){
	if(is_empty(pStack)){
		printf("��ջʧ��!\n");
		return false;
	}
    //����Ҫ��ջԪ�صĵ�ַ
	PNODE r = pStack->pTop;
	*pVal = r->data;
	//ջ��ָ�������ƶ�
	pStack->pTop = r->pNext;
	//�ͷ��ڴ�
	free(r);
	r=NULL;
	return true; 
}
/*
//���ջ 
void clear(PSTACK pStack){
	//����ֱ�ӷ��� 
	if(is_empty)
	    return;
	else{
    PNODE p = NULL; 
    while(pStack->pTop != pStack->pBottom){
    	p = pStack->pTop;//�Ƚ�pTop���棬�����ͷ��ڴ�
	    pStack->pTop = p->pNext;
	    free(p);
	    }
	pStack->pTop = pStack->pBottom;
    }
    return;
}
*/
//���ջ 
void clear(PSTACK pStack){
	//����ֱ�ӷ��� 
	if(is_empty){
	    return;
	}else{
        PNODE p = pStack->pTop;
		PNODE q = NULL; 
        while(pStack->pTop != pStack->pBottom){
    	    q = p->pNext;
			free(p); 
	        pStack->pTop = q;  
	    }
	pStack->pTop = pStack->pBottom;
    }
}

