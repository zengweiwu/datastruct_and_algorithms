#include<stdio.h>
typedef struct Student{
		int sid;
		char name;
		char sex;
	}Stu,*PST;//typedefΪ���е���������ȡһ������ Stu�൱��struct Student��PST�൱��struct Student* 
int main(void){
	Stu st;
	st.sid = 1;
	printf("%d\n",st.sid);
	PST pst = &st;
	printf("%d\n",pst->sid);
	typedef int NI;
	NI n = 10;
	printf("%d",n); 
} 
