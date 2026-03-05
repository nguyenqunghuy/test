#include<stdio.h>

int main(){
	long long n,a,b,money;
	
	scanf("%lld%lld%lld",&n,&a,&b);
	if((a*2)<=b){
		money=n*a;
		printf("%lld",money);
	}else if ((n%2)==0){
		money=(n/2)*b;
		printf("%lld",money);
	}else{
		money=(n/2)*b+a;
		printf("%lld",money);
	}
	
	return 0;
}