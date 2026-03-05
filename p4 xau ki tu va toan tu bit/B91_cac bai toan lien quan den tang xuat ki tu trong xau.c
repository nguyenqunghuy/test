#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void test(){
	char c[1000];
	gets(c);
	int count[256]={0};
	int max=0, min=1e9;
	int gtmax=0,gtmin=0;
	for(int i=0;i<strlen(c);i++){
		count[c[i]]++;
	}
	for(int i=0;i<256;i++){
		if(count[i]>=1){
			printf("%d %c %d\n",i,i,count[i]);
			if(count[i]>max){
			max=count[i];
			gtmax=i;
		}
		if((count[i]<min)){
			min=count[i];
			gtmin=i;
		}
		}
	}
	printf("\nkt lap lai nh lan nhat: %c\nkt lap lai it lan nhat: %c",gtmax,gtmin);
}

int main(){
	char c1[1000];
	char c2[1000];
	gets(c1);
	gets(c2);
	int count1[256]={0};
	int count2[256]={0};
	for(int i=0;i<strlen(c1);i++){
		count1[c1[i]]++;
	}
	for(int i=0;i<strlen(c2);i++){
		count2[c2[i]]++;
	}
	for(int i=0;i<256;i++){
		if((count1[i]>=1)&&(count2[i]>=1)){//kt chung
			printf("%c\n",i);
		}
	}
	for(int i=0;i<256;i++){
		if((count1[i]>=1)&&(count2[i]==0)){//kt xau 1 co nhung xau 2 ko co
			printf("%c\n",i);
		}
	}
	return 0;
}