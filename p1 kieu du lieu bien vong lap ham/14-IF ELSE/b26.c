#include<stdio.h>
#include<math.h>
int main (){
	long long a,b,c,d;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	
//	long long min=fmin(fmin(a,b),fmin(c,d));  worng because:fmin and fmax là hàm cho s? th?c (double) in  <math.h> not (long long)
//	long long max=fmax(fmax(a,b),fmax(c,d));
	long long min=a,max=a;
	if(min>b) min=b;
	if(min>c) min=c;
	if(min>d) min=d;
	if(max<b) max=b;
	if(max<c) max=c;
	if(max<d) max=d;
	printf("%lld %lld",max,min);	
	return 0;
}