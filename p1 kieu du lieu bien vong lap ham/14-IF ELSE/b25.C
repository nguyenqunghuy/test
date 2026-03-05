#include<stdio.h>

int main(){
	int a;
	scanf("%d",&a);
	int sum=0;
	int to100 = a/100;a%=100;
	int to20 = a/20;a%=20;
	int to10 = a/10;a%=10;
	int to5 = a/5; a%=5;
	int to1 = a;
	sum=to100+to20+to10+to5+to1;
	printf("%d",sum);
	
	return 0;
}