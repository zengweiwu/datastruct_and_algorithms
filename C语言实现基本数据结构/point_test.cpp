#include<stdio.h>
#include<malloc.h>
void f(int** q);
int main(void){
    int* p;
	f(&p);
	*p = 3;
	printf("%d",*p);	
}

void f(int** q){
	*q = (int*)malloc(4);
} 
