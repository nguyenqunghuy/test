#include<stdio.h>

int main(){
	long long s=0,n;
	scanf("%lld",&n);
	for(int i=0;i<=n;i++){
		s+=i;
	}
	printf("%lld",s);
	return 0;
}