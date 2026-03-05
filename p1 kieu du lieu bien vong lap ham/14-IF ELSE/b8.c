#include<stdio.h>

int main(){
	long long a,b;
	double thuong;
	scanf("%lld %lld",&a,&b);
	long long tong=a+b;
	long long hieu=a-b;
	long long tich=a*b;
	printf("%lld\n%lld\n%lld\n",tong,hieu,tich);
	if (b==0){
		printf("IVALID");
	}else{
		thuong =(float)a/b;
		printf("%.4lf",thuong);
	}
	return 0;
}