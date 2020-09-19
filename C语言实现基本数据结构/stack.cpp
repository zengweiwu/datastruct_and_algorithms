#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//注意栈底是链表尾结点 栈顶是链表头结点 指针是从上向下指 所以压栈出栈和链表添加删除有所不同 
//定义节点 
typedef struct Node {
	int data;
	struct Node* pNext;
}NODE,*PNODE;
//定义栈 
typedef struct Stack{
	PNODE pTop;//指向栈顶 
	PNODE pBottom;//指向栈低 
}STACK,*PSTACK;

void init_stack(PSTACK pStack);//初始化栈 
void push(PSTACK pStack,int val);//压栈 不需要返回值一定可以压栈成功
bool pop(PSTACK pStack,int* pVal);//出栈 
void traverse_stack(PSTACK pStack);//遍历栈 
bool is_empty(PSTACK pStack);//判断是否为空栈
void clear(PSTACK pStack);//清空栈 

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
        printf("出栈成功!出栈的元素是：%d\n",val);	
	}
	else
	    printf("出栈失败！\n");
	
	traverse_stack(&stack);
	printf("\n");
	
	clear(&stack);
	traverse_stack(&stack);
	//printf("栈的第一个数是：%d\n",p->pTop->data);
	return 0;
}

//初始化栈 
void init_stack(PSTACK pStack){
    //创建链表的头结点
	pStack->pTop = (PNODE)malloc(sizeof(NODE));
	if(pStack->pTop == NULL){
		printf("分配内存失败，程序终止!");
		exit(-1);
	}
	pStack->pTop->pNext = NULL;
	//栈的顶指针指向栈顶，尾指针指向栈底 
	pStack->pBottom = pStack->pTop;
	return;
}

//压栈
void push(PSTACK pStack,int val){
	//创建需要压入的结点
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = NULL;
	//链接 
	pNew->pNext = pStack->pTop;//指针要向下指，新结点的指针域必须先指向上一个结点 
	pStack->pTop = pNew;//将栈顶指针向后移动一个
	return; 
}

//遍历栈 
void traverse_stack(PSTACK pStack){
    PNODE p = pStack->pTop;//保存栈顶指针 
    if(p->pNext == NULL){
    	printf("链表为空！\n");
	}
    while(p->pNext != NULL){
    	printf("%d ",p->data);//先输出里面的元素再移动指针 
    	p = p->pNext;
	}
	return;
}

//判断是否是空栈 
bool is_empty(PSTACK pStack){
    //栈顶指针等于栈底指针即栈为空 
	if(pStack->pTop == pStack->pBottom)
	    return true;
	else
	    return false;
}

//出栈
bool pop(PSTACK pStack,int* pVal){
	if(is_empty(pStack)){
		printf("出栈失败!\n");
		return false;
	}
    //保存要出栈元素的地址
	PNODE r = pStack->pTop;
	*pVal = r->data;
	//栈顶指针向下移动
	pStack->pTop = r->pNext;
	//释放内存
	free(r);
	r=NULL;
	return true; 
}
/*
//清空栈 
void clear(PSTACK pStack){
	//空则直接返回 
	if(is_empty)
	    return;
	else{
    PNODE p = NULL; 
    while(pStack->pTop != pStack->pBottom){
    	p = pStack->pTop;//先将pTop保存，便用释放内存
	    pStack->pTop = p->pNext;
	    free(p);
	    }
	pStack->pTop = pStack->pBottom;
    }
    return;
}
*/
//清空栈 
void clear(PSTACK pStack){
	//空则直接返回 
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

