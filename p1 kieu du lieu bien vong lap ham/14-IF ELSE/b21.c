#include<stdio.h>
int main(){
	long long m,n,a,l,r ;
	scanf("%lld %lld %lld",&m,&n,&a);
	if(a%2==0){
		r=a/2*m;
		l=a/2*n;
		printf("%lld",r-l);
	}else if(a%2!=0){
		r=a/2*m+m;
		l=a/2*n;
		printf("%lld",r-l);
	}else if (a==1){
		r=m;
		printf("%lld",r);
	}else {
		printf("ERORR");
	}	
	return 0;
}