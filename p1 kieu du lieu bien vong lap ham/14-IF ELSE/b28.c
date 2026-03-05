#include<stdio.h>
#include<math.h>
int main (){
	double n ,u1,d;
	scanf("%lf %lf %lf", &n, &u1, &d);
	double s1=n/2*(2*u1+(n-1)*d);
	long long s2=floor(s1);
	printf("%lld",s2);
	return 0;
}