#include<stdio.h>

int main (){
	char kt;
	scanf("%c",&kt);
	if ((65<=kt)&&(kt<=90)){
		printf("%c",kt+32);
	}else if ((97<=kt)&&(kt<=122)){
		printf("%c",kt-32);
	}else {
		printf("%c",kt);
	}	
	return 0;
}
