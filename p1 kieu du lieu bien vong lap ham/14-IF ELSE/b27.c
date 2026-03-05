#include<stdio.h>
#include<math.h>

int main(){
	double a;
	scanf("%lf",&a);
	long long b=floor(a);
	if	((a-b-0.5)<0){
		long long res=floor(a);
		printf("%lld",res);
	}else{
		long long res=ceil(a);
		printf("%lld",res);	
	}
	return 0;
}