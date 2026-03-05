//            scope rules :pham vi cua  bien
#include<stdio.h>

int n=100;             //globle scope :pham vi toan cuc

int main(){
	int n=200;         //local scope :pham vi dia phuong
	if(10==10){
		int n=300;
		printf("%d",n);//encslosing scope:pham vi dong mo hoac nhon
	}
	return 0;
}