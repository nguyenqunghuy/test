#include<stdio.h>

int main(){
	int hours,minutes;
	scanf("%d %d",&hours,&minutes);
	int test=60*24-hours*60-minutes;
	printf("%d",test);
	return 0;
}