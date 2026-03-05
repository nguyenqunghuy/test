#include<stdio.h>
#include<math.h>

int main(){
	double a,b,c,d;
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	double s1=a*c;
	double s2=b*d;
	if ((sqrt(s1)==b)&&(sqrt(s2)==c)){
		printf("YES");
	}else{
		printf("NO");
	}
	
	
	return 0;
}