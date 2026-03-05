#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
//	char* word=strtok(c," \n");
//	char a[100][100];
//	int k=0;
//	while(word!=NULL){
//		strcpy(a[k],word);
//		k++;
//		word=strtok(NULL," \n");
void b1(){
	char c[1001];
	fgets(c,1001,stdin);
	int chu_cai=0,chu_so=0,ki_tu=0;
	for(int i=0;i<(int)strlen(c);i++){
		if(c[i]=='\n')continue;
		if(isdigit(c[i])){
			chu_so++;
		}else if(isalpha(c[i])){
			chu_cai++;
		}else {
			ki_tu++;
		}
	}
	printf("%d %d %d",chu_cai,chu_so,ki_tu);
}
//
void b2(){
	char c[1005];
	fgets(c,1005,stdin);
	for(int i=0;i<(int)strlen(c)-1;i++){
		c[i]=toupper(c[i]);
		printf("%c",c[i]);
	}
	printf("\n");
	for(int i=0;i<(int)strlen(c)-1;i++){
		c[i]=tolower(c[i]);
		printf("%c",c[i]);
	}
}
//
void b3(){
	char c[100005];
	fgets(c,100005,stdin);
	c[strlen(c)-1]='\0';
	int n=strlen(c);
	int bien[500]={0};int max=0;
	for(int i=0;i<n;i++){
		bien[(int)c[i]]++;
		if(max<c[i]){
			max=c[i];
		}
	}
	for(int i=0;i<=max;i++){
		if(bien[i]>0){
			printf("%c %d\n",i,bien[i]);
		}
	}
	printf("\n");
	for(int i=0;i<n;i++){
		int count=1;
		if(c[i]==-1)continue;
		for(int j=i+1;j<n;j++){
			if(c[i]==c[j]){
				count++;
				c[j]=-1;
			}
		
		}
		printf("%c %d\n",c[i],count);
	}
}
void b4(){
	char c[100005];
	fgets(c,100005,stdin);
	c[strlen(c)-1]='\0';
	int n=strlen(c);
	int bien[500]={0};
	for(int i=0;i<n;i++){
		bien[(int)c[i]]++;
	}
	int max=0,min=10000;
	for(int i=0;i<500;i++){
		if(bien[i]>=max){
			max=i;
		}
		if((bien[i]>0)&&(bien[i]<=min)){
			min=i;
		}
	}
	printf("%c %d\n%c %d",max,bien[max],min,bien[min]);
}
//Bài 5. Ký tự xuất hiện ở cả 2 xâu
int cmp(const void* a,const void* b){
	char *x=(char*)a;
	char *y=(char*)b;
	return *x-*y;
}
void b5(){
	char c1[100005];
	char c2[100005];
	fgets(c1,100005,stdin);
	fgets(c2,100005,stdin);
	c1[strlen(c1)-1]='\0';
	c2[strlen(c2)-1]='\0';
	int bien1[257]={0};
	int bien2[257]={0};
	for(int i=0;i<strlen(c1);i++){
		bien1[(int)c1[i]]=1;
	}
	for(int i=0;i<strlen(c2);i++){
		bien2[(int)c2[i]]=1;
	}
	for(int i=0;i<257;i++){
		if((bien1[i]==1)&&(bien2[i]==1)){
			printf("%c",i);
		}
	}
	printf("\n");
	for(int i=0;i<257;i++){
		if((bien1[i]==1)||(bien2[i]==1)){
			printf("%c",i);
		}
	}
}


int main(){
	b4();
	
	
	
	return 0;
}




