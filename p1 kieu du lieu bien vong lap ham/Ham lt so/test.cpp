#include <stdio.h>
#include <math.h>

int snt(long long n){
	if(n<2){
		return 0;
	}
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

void shh(long long n){
	for(int i=2;i<=33;i++){
		if(snt(i)){
			long long res1=pow(2,i)-1;
			if(snt(res1)){
				long long res2=pow(2,i-1);
				printf("%lld \n",res1*res2);
				if((res1*res2)==n){
				printf("YES");  
				return;
				}	
			}           
		}
	}
	printf("NO");  		
}
int main(){
	long long n=0;
	scanf("%lld",&n);
	shh(n);
	return 0;
}