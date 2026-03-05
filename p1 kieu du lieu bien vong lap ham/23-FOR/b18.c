#include<stdio.h>

int main(){
	long long n;
	scanf("%lld",&n);
	int sum=0;
	while(n>0){
		if((n%10==2)||(n%10==3)||(n%10==5)||(n%10==7)){
		sum+=1;
		}
		n/=10;
	}
	printf("%d",sum);
	return 0;
}