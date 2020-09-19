#include<stdio.h>
#include<string.h>  
struct Student{//定义学生类型的结构体 
    int sid;
    char name[200];
    int age;
};
void f(struct Student* pst);
void g(struct Student st); 
int main(void){
	struct Student st;
    f(&st);
	g(st);
	return 0;	
}
//用指针给结构体变量赋值
void f(struct Student* pst){
	(*pst).sid = 1;//*pst取地址里面的内容 
	strcpy(pst->name,"zhangsan");
	pst->age = 18;//是指针变量才可以用箭头 
} 
//打印结构体中的变量
void g(struct Student st){
	printf("%d %s %d",st.sid,st.name,st.age);
} 
