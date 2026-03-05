#include<stdio.h>
#include<math.h>

int main(){
	long long s=0;long long n;
	scanf("%lld",&n);
	for(int i=1;i<=sqrt(n);i++){	
		if(n%i==0){
			s+=i;
			if(i!=n/i){
				s+=n/i;
			}
		}
	}
	printf("%lld",s);
	return 0;
}