#include<stdio.h>

int main (){
	long long n,s,xu;
	scanf("%lld %lld",&n,&s);
	if(s%n==0){
		xu=s/n;
		printf("%lld",xu);
	}else if (s%n!=0){
		xu=s/n+1;
		printf("%lld",xu);
 	}else{
 		printf("ERORR");	
	 }
	
	
	return 0;
}