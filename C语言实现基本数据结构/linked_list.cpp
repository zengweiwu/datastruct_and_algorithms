#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//定义节点类型 
typedef struct Node{
	int date;
	struct Node* pNext;
}NODE,*PNODE;
 
PNODE create_list(void);//创建链表函数
void traverse_list(PNODE pHead);//遍历链表 
bool is_empty(PNODE pHead);//判断链表是否为空 
int length_list(PNODE pHead);//计算链表的长度 
void sort_list(PNODE pHead);//链表排序升序 
bool insert_list(PNODE pHead);//指定位置前插入元素
bool apend_list(PNODE pHead);//在链表末尾追加元素 
bool delete_list(PNODE pHead,int*pv);//删除指定结点
 
 
int main(void){
	PNODE pHead = NULL;
	pHead = create_list();
	traverse_list(pHead);
	
	int j = length_list(pHead);
	printf("链表的长度为：%d\n",j);
	
	sort_list(pHead);
	printf("链表升序排序为：");
	traverse_list(pHead);
	
	//insert_list(pHead);
	//traverse_list(pHead);
	
	int val; 
	delete_list(pHead,&val);
    traverse_list(pHead);
    printf("删除的元素是：%d\n",val);
    
    //apend_list(pHead);
	//traverse_list(pHead);
	
	int l = length_list(pHead);
	printf("链表的长度为：%d\n",l); 
	return 0;
}
//创建链表实现 
PNODE create_list(void){
	int len;
	int val;
	PNODE pHead = NULL;//定义头结点指针 
	pHead = (PNODE)malloc(sizeof(NODE));//为头结点分配内存
	if(pHead == NULL){
		printf("内存分配失败！"); 
	}
	PNODE pTail = pHead;//只有一个元素时头结点尾结点是自己本身 
	pTail->pNext = NULL;//尾结点的指针域为空 
	printf("请输入要创建的链表的结点个数：");
	scanf("%d",&len);
	for(int i = 0;i < len;i++){
		printf("请输入第%d个结点的值：",i+1);
		scanf("%d",&val);//输入的值暂时存储在变量val中
		PNODE pNew = (PNODE)malloc(sizeof(NODE));//分配一个新结点的内存空间
		if(pNew == NULL){
			printf("分配失败！程序终止！\n");
			exit(-1);
		} 
		pNew->date = val;//将临时保存在val中的值赋给创建结点的数据域
		pTail->pNext = pNew;//将新结点的地址赋给上一个结点的指针域，注意不能赋给头结点，头结点不能变 
		pNew->pNext = NULL;
		pTail = pNew;//每次增加新结点头结点不能动，动的是尾结点 	
	}
	 return pHead;
}

//遍历链表实现 
void traverse_list(PNODE pHead){
    PNODE p = pHead->pNext;//用一个指针变量来存储第一个有效结点（即首节点）的地址
    while(p != NULL){
    	printf("%d ",p->date);
    	p = p->pNext;
	}
	/*for(int i = 1;p != NULL;i++){
		printf("%d ",p->date);//将结点的数据输出 
		p = p->pNext;//将结点下一个结点的地址赋值给p 
	}*/
	printf("\n");
}

//判断链表是否为空函数实现
bool is_empty(PNODE pHead){
	if(pHead->pNext == NULL)
	    return true;
	else
	    return false;
}

//计算链表长度函数实现
int length_list(PNODE pHead){
	PNODE p = pHead->pNext;
	int i = 0;
	while(p != NULL){
	    i++;
		p = p->pNext;
	}
	return i;
}

//链表升序排序实现（类比数组选择排序实现） 
void sort_list(PNODE pHead){
	int i,j,t;//用来保存交换的变量 
	int len = length_list(pHead);//获取链表的长度 
	PNODE p,q;
	//不要在for循坏里声明变量，因为会出翔逗号后面的指针被误认为是所声明的类型 
	for(i = 0,p = pHead->pNext;i < len-1;i++,p = p->pNext){//比较的轮数比元素的个数少1 
		for(j = i+1,q = p->pNext;j < len;j++,q = q->pNext){//q = q->pNext等价于j++，地址向后面移动了一位 
			if(p->date > q->date){
			t = p->date;//t = a[i]
			p->date = q->date;//a[i] = a[j];
			q->date = t;//a[j] = t;
			}	
		}
	}
	return; 
}

//指定位置插入元素实现
bool insert_list(PNODE pHead){
	int pos,val;//保存要插入的位置和值 
	//判断插入位置是否超出链表长度 
	printf("请输入想要插入结点的位置:");
	scanf("%d",&pos);
	if(pos > length_list(pHead)){
		printf("超出链表长度！\n");
		return false;
	}
	//获取要插入的值
	printf("请输入要插入的值：");
	scanf("%d",&val);
	//创建要插入的结点
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL){
		printf("动态分配内存失败！");
		exit(-1);
	}
	pNew->date = val;
	//找到要插入的位置的上一个结点的地址 
	PNODE p = pHead->pNext;
	//在首节点前插入 
	if(pos == 1){
		pNew->pNext = pHead->pNext;
		pHead->pNext = pNew;
		return true;//如果是在第一个插入，函数执行到这里就该return否则会继续执行下面的语句 
	}
	for(int i = 1;i < pos-1;i++){
		p = p->pNext;
	}
	//插入结点 
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}

//删除指定结点实现 
bool delete_list(PNODE pHead,int*pv){
	//获取要删除的结点序号 
    int pos;
    printf("请输入要删除结点的序号：");
	scanf("%d",&pos); 
	//找到要删除结点的前一个结点
	PNODE p = pHead; 
	for(int i = 1;i < pos;i++){
		p = p->pNext;
	}
	//删除结点并释放内存 
	PNODE r = p->pNext;
	*pv = r->date;
	p->pNext = p->pNext->pNext;
	free(r);
	r = NULL;
}

//链表末尾追加元素 
bool apend_list(PNODE pHead){
	//获取要追加的元素 
    int val;
    printf("请输入要追加的值：");
	scanf("%d",&val);
	//创建要追加的结点
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL){
		printf("动态分配内存失败！");
		exit(-1);
	}
	pNew->date = val;
	//找到尾结点 
	int i = 0;
	PNODE p = pHead;
	while(p->pNext != NULL){
		p = p->pNext;
	}
	//将追加结点指针域赋值NULL然后追加元素 
	pNew->pNext = NULL;
	p->pNext = pNew;
} 
