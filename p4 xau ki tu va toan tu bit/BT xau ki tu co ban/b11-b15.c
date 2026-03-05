#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int check_hoa(char c[]){
	for(int i=0;i<strlen(c);i++){
		if(islower(c[i]))return 0;
	}
	return 1;
}
void b11(){
	char c[1000];
	fgets(c,1000,stdin);
	char a[100][100];
	char* word=strtok(c," \n");
	int j=0;
	while(word!=NULL){
		strcpy(a[j++],word);
		word=strtok(NULL," \n");
	}
	int count=0;
	for(int i=0;i<j;i++){
		if(check_hoa(a[i])){
			count++;
		}
	}
	printf("%d",count);		
}
void b13(){
	char c[1000];
	fgets(c,1000,stdin);
	char a[100][100];
	char* word=strtok(c," ,.!?\n");
	int j=0;
	while(word!=NULL){
		strcpy(a[j++],word);
		word=strtok(NULL," ,.!?\n");
	}
	for(int i=0;i<j;i++){
			printf("%s ",a[i]);
	}
}
void b14(){
	char c[1000];
	fgets(c,1000,stdin);
	char a[100][100];
	char* word=strtok(c," ");
	int j=0;
	while(word!=NULL){
		strcpy(a[j++],word);
		word=strtok(NULL," ");
	}
	int count=0;
	for(int i=0;i<j;i++){
		int k=0;
		while(k<strlen(a[i])){
			a[i][k]=tolower(a[i][k]);k++;
		}
		if(strcmp("28tech",a[i])==0){
			count++;
		}
	}
	printf("%d",count);
}
//b15 chan le

void flip(char bien[]){
	int l = 0, r = strlen(bien) - 1;
	while(l <= r){
		char res = bien[l];
		bien[l] = bien[r];
		bien[r] = res;
		l++; r--;
	}
}


int main(){
	char c[1000];
	fgets(c,1000,stdin);
	char* word=strtok(c," \n");
	char bien[100][100];
	int j=0;
	while(word!=NULL){
		strcpy(bien[j],word);j++;
		word=strtok(NULL," \n");
	}
	for(int i=0;i<j;i++){
		if(i%2==0){
			printf("%s ",bien[i]);
		}else{
			flip(bien[i]);
			printf("%s ",bien[i]);
		}
	}
	
	
	
	return 0;
}