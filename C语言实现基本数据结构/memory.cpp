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
//��̬�����ڴ棬����ѧ���ṹ�岢��ֵ�������׵�ֵַ
struct Student* CreateStudent(void){
	struct Student* p = (struct Student*)malloc(sizeof(struct Student));//�����ڴ淵���׵�ַ 
	p->sid = 1;
	p->age = 18;
	return p;
} 
//����ָ������ṹ�� 
void Show(struct Student* p){
	printf("%d %d",p->sid,p->age);
}
