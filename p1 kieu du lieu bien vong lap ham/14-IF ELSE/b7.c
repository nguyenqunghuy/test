#include<stdio.h>

int main(){
	int a,b,c,d;
	int e;
	scanf("%d %d",&a,&b);
	if(a==b){
		printf("%d %d",a,a);
	}else{
		e=a*1.00/b;
		c=e*b;
		d=(e+1)*b;
		printf("%d %d",c,d);
	}
	
	return 0;
}