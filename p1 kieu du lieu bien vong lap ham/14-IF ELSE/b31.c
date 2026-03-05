#include<stdio.h>
#include<math.h>

int main(){
	double a1,a2,a3,b1,b2,b3,n;
	scanf("%lf %lf %lf %lf %lf %lf %lf ",&a1,&a2,&a3,&b1,&b2,&b3,&n);
	long long s1=ceil((a1+a2+a3)/5);
	long long s2=ceil((b1+b2+b3)/10);
	if((s1+s2)<=n){
		printf("YES");
	}else{
		printf("NO");	
	}
	return 0;
}