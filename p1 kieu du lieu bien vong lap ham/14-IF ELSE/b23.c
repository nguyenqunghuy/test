#include<stdio.h>

int main (){
	int n,m,step;
	scanf("%d %d",&n,&m);
	int min ,max;
	max=n;
	if(n%2==0){
		min=n/2;
	}else{
		min=n/2+1;
	}
	step=(min+m-1)/m*m;
	if(step<=max){
		printf("%d",step);
	}else{
		printf("-1");
	}
	
	
	
	return 0;
}