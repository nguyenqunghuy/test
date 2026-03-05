#include<stdio.h>

int main (){
	int a,b,c,n;
	scanf("%d%d%d%d",&a,&b,&c,&n);
	long long s=a+b+c+n;
	if(s%3==0){
		s/=3;
		if((s>=a)&&(s>=b)&&(s>=c)){
			printf("YES");
		}else{
			printf("NO");	
		}
	}else{
		printf("NO");
	}
	return 0;
}