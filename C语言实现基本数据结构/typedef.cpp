#include<stdio.h>
typedef struct Student{
		int sid;
		char name;
		char sex;
	}Stu,*PST;//typedef为已有的数据类型取一个别名 Stu相当于struct Student，PST相当于struct Student* 
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
