#include<stdio.h>

int main (){
	char kt;
	scanf("%c",&kt);
	if ((65<=kt)&&(kt<=90)){   //65A -> 90Z
		printf("UPPER");
	}else if ((97<=kt)&&(kt<=122)){   //97a -> 122z
		printf("LOWER");     
	}else if((48<=kt)&&(kt<=57)){    //48:1 -> 57:9
		printf("DIGIT");
	}else {
		printf("SPECIAL");
	}	
	return 0;
}
