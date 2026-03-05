#include<stdio.h>

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if((a*b*c<=0)||(!(((a+b)>c)&&((b+c)>a)&&((a+c)>b)))){
		printf("INVALID");
	}else if((a==b)&&(b==c)&&(a==c)){
		printf("1");
	}else if((a==b)||(b==c)||(a==c)){
		printf("2");
	}else if((a*a+b*b==c*c)||(a*a+c*c==b*b)||(a*a==b*b+c*c)){
		printf("3");
	}else {
	 	printf("4");	
	}
	
	return 0;
}