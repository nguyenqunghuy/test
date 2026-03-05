#include<stdio.h>
#include<math.h>

int main(){
	long long n,res=1;
	scanf("%lld",&n);
	for (long long i=1;i<=sqrt(n);i++){
		if(n%i==0){
			if(i==n/i){
				res*=i;
				continue;
			}
			res*=i;
			res*=n/i;
		}
	}
	printf("%lld",res);
	
	return 0;
}