#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
//
void flip(char c[]){
	int l=0,r=strlen(c)-1;
	while(l<=r){
		int res=c[l];
		c[l]=c[r];
		c[r]=res;
		l++;r--;
	}
}
void b7(){
	char c[100005];
	fgets(c,100005,stdin);
	c[strlen(c)-1]='\0';
	char res[100005];
	strcpy(res,c);
	flip(c);
	if(strcmp(c,res)==0){
		printf("YES");;
	}else{
		printf("NO");
	}
}
//Bài 8. Xâu pangram
void b8(){
	char c[100005];
	fgets(c,100005,stdin);
	c[strlen(c)-1]='\0';
	int dem[500]={0}; 
	for(int i=0;i<(int)strlen(c);i++){
		c[i]=toupper(c[i]);
		dem[(int)c[i]]=1;
	}
	for(int i='A';i<='Z';i++){
		if(dem[i]==0){
			printf("NO");
			return ;
		}
	}
	printf("YES");
}
//
int cmp(const void* a,const void* b){
	char* x=(char*)a;
	char* y=(char*)b;
	return strcmp(x,y);
}

int main(){
	char c[100005];
	fgets(c,100005,stdin);
	char* word=strtok(c," \n");
	char bien[10000][50];
	char bien2[10000][50];
	int k=0;
	while(word!=NULL){
		strcpy(bien[k],word);
		strcpy(bien2[k],word);
		k++;
		word=strtok(NULL," \n");
	}
	qsort(bien,k,sizeof(char)*50,cmp);
	for(int i=0;i<k;i++){
		if(strcmp(bien[i],bien[i+1])!=0){
			printf("%s ",bien[i]);
		}
	}
	printf("\n");
	for(int i=0;i<k;i++){
		if(strcmp(bien2[i],"-1")==0)continue;
		for(int j=i+1;j<k;j++){
			if(strcmp(bien2[i],bien2[j])==0){
				strcpy(bien2[j],"-1");
			}
		}
		printf("%s ",bien2[i]);
	}
	
	
	
	
	return 0;
}




	
	