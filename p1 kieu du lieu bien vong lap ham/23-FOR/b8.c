#include<stdio.h>
#include<math.h>

int main(){
	long long n;
	scanf("%lld",&n);
	for(long long i=1;i<=sqrt(n);i++){
		if((i*i)<=n);
		printf("%lld ",i*i);
	}
	return 0;
}