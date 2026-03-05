#include<stdio.h>

int sum2(int a,int b){
	int sum1=a+b;
	printf("sum is:%d",sum1);
}

int main(){
	int sum1=0;
	sum2(10,20);
	return 0;
}