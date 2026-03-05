#include<stdio.h>

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if (a*b*c<=0)|{
		printf("NO");
	}if (((a+b)>c)&&((b+c)>a)&&((a+c)>b)){
		printf("YES");
	}else if (((a+b)>c)&&((b+c)>a)&&((a+c)>b)){
		printf("YES");
	}else{
		printf("NO");
	}
	
	return 0;
}