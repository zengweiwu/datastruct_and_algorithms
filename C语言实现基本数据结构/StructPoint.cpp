#include<stdio.h>
#include<string.h>  
struct Student{//����ѧ�����͵Ľṹ�� 
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
//��ָ����ṹ�������ֵ
void f(struct Student* pst){
	(*pst).sid = 1;//*pstȡ��ַ��������� 
	strcpy(pst->name,"zhangsan");
	pst->age = 18;//��ָ������ſ����ü�ͷ 
} 
//��ӡ�ṹ���еı���
void g(struct Student st){
	printf("%d %s %d",st.sid,st.name,st.age);
} 
