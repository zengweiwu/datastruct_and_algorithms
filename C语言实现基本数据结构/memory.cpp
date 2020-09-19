#include<stdio.h>
#include<malloc.h>
struct Student* CreateStudent(void);
void Show(struct Student * p);
struct Student{
	int sid;
	int age;
};
int main(void){
	struct Student* pst = CreateStudent();
	Show(pst);
}
//动态分配内存，创建学生结构体并赋值，返回首地址值
struct Student* CreateStudent(void){
	struct Student* p = (struct Student*)malloc(sizeof(struct Student));//分配内存返回首地址 
	p->sid = 1;
	p->age = 18;
	return p;
} 
//利用指针输出结构体 
void Show(struct Student* p){
	printf("%d %d",p->sid,p->age);
}
