#include<stdio.h>

int main(){
	long long n;
	scanf("%lld",&n);
	int sum1=0;
	while(n>=10){lap laij neu sum1 cos 2 so hang 
		sum1=0;
	while(n!=0){//tinh tong so hang
		sum1=n%10+sum1;n/=10;
	}
	n=sum1;
	}
	printf("%d",sum1);
	
	return 0;
}