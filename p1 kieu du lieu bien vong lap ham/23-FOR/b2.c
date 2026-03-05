#include<stdio.h>
#include<math.h>

int main(){
	long long s=0,n;
	scanf("%lld",&n);
	for(int i=0;i<=n;i+=3){
		s+=i;
	}
	printf("%lld",s);
	return 0;
}