#include<stdio.h>

int main(){
	int t,n;
	scanf("%d %d",&t,&n);
	if(n < 0 || t <= 0 || t >= 13){
		printf("INVALID");
	}
	else if(t == 2 && n % 4 ==0 && n % 100 != 0){
		printf("29");
	}
	else if ((t==1)||(t==3)||(t==5)||(t==7)||(t==8)||(t==10)||(t==12)){
		printf("31");
	}else if ((t==4)||(t==6)||(t==9)||(t==11)){
		printf("30");
	}else if(t==2){
		printf("28");
	}else{
		printf("INVALID");
	}
	return 0;
}