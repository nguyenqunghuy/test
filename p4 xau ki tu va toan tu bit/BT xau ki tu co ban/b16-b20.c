#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
//quickup
int sort(char c[],int l,int r){
	int k=l-1;
	for(int i=l;i<r;i++){
		if(c[i]>c[r]){
			++k;
			int res=c[k];
			c[k]=c[i];
			c[i]=res;
		}
	}
	k++;
	int res=c[k];
	c[k]=c[r];
	c[r]=res;
	return k;
}
void quickup(char c[],int l,int r){
	if(l<r){
		int res=sort(c,l,r);
		quickup(c,l,res-1);
		quickup(c,res+1,r);
	}
}
//quick down
int sort1(char c[],int l,int r){
	int k=l-1;
	for(int i=l;i<r;i++){
		if(c[i]<c[r]){
			++k;
			int res=c[k];
			c[k]=c[i];
			c[i]=res;
		}
	}
	k++;
	int res=c[k];
	c[k]=c[r];
	c[r]=res;
	return k;
}
void quickdown(char c[],int l,int r){
	if(l<r){
		int res=sort1(c,l,r);
		quickdown(c,l,res-1);
		quickdown(c,res+1,r);
	}
}
void b16(){
	char c[1000];
	fgets(c,1000,stdin);
	quickdown(c,0,strlen(c)-2);
	for(int i=0;i<strlen(c)-1;i++){
		printf("%c",c[i]);
	}
	printf("\n");
	quickup(c,0,strlen(c)-2);
	for(int i=0;i<strlen(c)-1;i++){
		printf("%c",c[i]);
	}
}

//b17

int cmp1(const void*a,const void*b){
	char* x=(char*)a;
	char* y=(char*)b;
	return strcmp(x,y);
}
void b17(){
	char c[1000];
	fgets(c,1000,stdin);
	char a[100][100];
	char* word=strtok(c," \n");
	int k=0;
	while(word!=NULL){
		strcpy(a[k],word);k++;
		word=strtok(NULL," \n");
	}
	qsort(a,k,100*sizeof(char),cmp1);
	for(int i=0;i<k;i++){
		printf("%s ",a[i]);
	}
	printf("\n");
	for(int i=k-1;i>=0;i--){
		printf("%s ",a[i]);
	}
}
//b18
int cmp18(const void*a,const void*b){
	char* x=(char*)a;
	char* y=(char*)b;
	if (strlen(x) > strlen(y)) return 1;
    if (strlen(x) < strlen(y)) return -1;
    return strcmp(x,y);
}
void b18(){
	char c[1000];
	fgets(c,1000,stdin);
	char a[100][100];
	char* word=strtok(c," \n");
	int k=0;
	while(word!=NULL){
		strcpy(a[k],word);k++;
		word=strtok(NULL," \n");
	}
	qsort(a,k,100*sizeof(char),cmp18);
	for(int i=0;i<k;i++){
		printf("%s ",a[i]);
	}
}
// b19 Đếm số lượng tự khác nhau
void in_thuong(char n[]){
	for(int i=0;i<strlen(n);i++){
		n[i]=tolower(n[i]);
	}
}
void b19(){
	char c[1000];
	fgets(c,1000,stdin);
	char a[100][100];
	char* word=strtok(c," \n");
	int k=0;
	while(word!=NULL){
		in_thuong(word);
		strcpy(a[k],word);k++;
		word=strtok(NULL," \n");
	}
	qsort(a,k,sizeof(a[0]),cmp1);
	int count=1;
	for(int i=0;i<k-1;i++){
		if(strcmp(a[i],a[i+1])!=0)count++;
	}
	printf("%d",count);
}
//Bài 20. Các từ thuận nghịch
int tn(char c[]){
	int l=0;int r=strlen(c)-1;
	while(l<=r){
		if(c[l]!=c[r])return 0;
		l++;r--;
	}
	return 1;
}
int main(){
	char c[1000];
	fgets(c,1000,stdin);
	char a[100][100];
	char* word=strtok(c," \n");
	int k=0;
	while(word!=NULL){
		strcpy(a[k],word);k++;
		word=strtok(NULL," \n");
	}
	qsort(a,k,sizeof(a[0]),cmp1);
	int count=1;
	for(int i=0;i<k;i++){	
		if(tn(a[i]))printf("%s ",a[i]);
	}
	return 0;
}