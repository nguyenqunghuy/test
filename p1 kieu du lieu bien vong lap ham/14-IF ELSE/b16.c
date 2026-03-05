#include<stdio.h>

int main (){
	char kt;
	scanf("%c",&kt);
	if ((65<=kt)&&(kt<90)){
		printf("%c",kt+33);
	}else if ((kt==90)||(kt==122)){
		printf("%c",97);
	}else if ((97<=kt)&&(kt<=121)){
		printf("%c",kt+1);
	}else{
		printf("invalid");
	}	
	return 0;
}
