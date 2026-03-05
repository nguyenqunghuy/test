#include<stdio.h>


int main(){
	char s[]="2024";
	*(s+3)=*s+3;
	printf("%s",s);
	
	
	
	return 0;
}

