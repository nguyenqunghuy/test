#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int res(int i){
	i++;
}

int main(){
	int res[10]={0};
	res[0]=9;
	for(int i=0;i<10;i++){
		printf("%d",res[i]);
	}
	
}