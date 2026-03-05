#include<stdio.h>
#include<math.h>
int main (){
	long long a=0,b=0;
	scanf("%lld %lld",&a,&b);
	long long c=0;
	if (a<b){
		c=a;
	}else {
		c=b;
	}
	long long e=0;
	if (a>b){
		e=a;
	}else {
		e=b;
	}
	int long long ucln=1;
	for(int i=1;i<=c;i++){
		if ((i==2)&&(e%2==0)){
			ucln*=2;
			continue;
		}else(c%i==0);{
			ucln*=i;
		}
	}
	printf("%lld",ucln);
	
	
	return 0;
}





