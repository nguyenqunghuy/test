#include<stdio.h>
#include<math.h>

int main(){
	
	long long k2,k3,k5,k6;
	scanf("%lld %lld %lld %lld",&k2,&k3,&k5,&k6);
	
	long long n256=fmin(fmin(k2,k5),k6);
	long long n32=fmin(k2-n256,k3);
	printf("%lld",n256*256+n32*32);
	
	return 0;
}