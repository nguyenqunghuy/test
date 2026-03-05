#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){
	char* x=(char*)a;
	char* y=(char*)b;
	return strcmp(x,y);
}

int cmp_1(const void* a,const void* b){
	char* x=(char*)a;
	char* y=(char*)b;
	int x1=strlen(x),y1=strlen(y);
	if(x1==y1){
		return strcmp(x,y);
	}else{
		return x1-y1;
	}
}
void b11(){
	char c[100005];
	fgets(c,100005,stdin);
	c[strlen(c)-1]='\0';
	char *token=strtok(c," ");
	char word[10000][50];
	int k=0;
	while(token!=NULL){
		strcpy(word[k],token);
		k++;
		token=strtok(NULL," ");
	}
	qsort(word,k,sizeof(word[0]),cmp);
	for(int i=0;i<k;i++){
		printf("%s ",word[i]);
	}
	printf("\n");
	qsort(word,k,sizeof(word[0]),cmp_1);
	for(int i=0;i<k;i++){
		printf("%s ",word[i]);
	}
}
//Bài 12. Sắp xếp từ 2
int tn(char c[]){
	int l=0,r=strlen(c)-1;
	while(l<=r){
		if(c[l]!=c[r]){
			return 0;
		}
		l++;r--;
	}
	return 1;
}
struct tu12{
	char word[50];
	int stt;
};
typedef struct tu12 tu12;
int cmp_2(const void* a,const void* b){
	tu12* x=(tu12*)a;
	tu12* y=(tu12*)b;
	int x1=strlen(x->word),y1=strlen(y->word);
	if(x1==y1){
		return (x->stt)-(y->stt);
	}else{
		return x1-y1;
	}
}
tu12 a[50005];
void b12(){//                50%
	char c[100005];
	fgets(c,100005,stdin);
	char *token=strtok(c," \n");
	int k=0;
	while(token!=NULL){
		if(tn(token)){
			strcpy(a[k].word,token);
			a[k].stt=k;
			k++;
		}
		token=strtok(NULL," \n");
	}
	qsort(a,k,sizeof(tu12),cmp_2);
	for(int i=0;i<k;i++){
		printf("%s ",a[i].word);
	}
}
//Bài 13. Tần suất từ
struct txtu{
	char word[50];
	int stt;
	int tx;
};
typedef struct txtu txtu;
int cmp_3(const void* a,const void* b){
	txtu* x=(txtu*)a;
	txtu* y=(txtu*)b;
	if(strcmp(x->word,y->word)==0){
		return y->stt-x->stt;
	}
	return strcmp(x->word,y->word);
}
int cmp_4(const void* a,const void* b){
	txtu* x=(txtu*)a;
	txtu* y=(txtu*)b;
	return x->stt-y->stt;
}
txtu b[50005]={0};
void b13(){
	char c[100005];
	fgets(c,100005,stdin);
	char* token=strtok(c," \n");
	int k=0;
	while(token!=NULL){
		strcpy(b[k].word,token);
		b[k].stt=k;
		k++;
		token=strtok(NULL," \n");
	}
	qsort(b,k,sizeof(txtu),cmp_3);
	int count=1;
	for(int i=0;i<k;i++){
		if(strcmp(b[i].word,b[i+1].word)==0){
			count++;
		}else{
			printf("%s %d\n",b[i].word,count);
			b[i].tx=count;
			count=1;
		}
	}
	printf("\n\n");
	qsort(b,k,sizeof(txtu),cmp_4);
	for(int i=0;i<k;i++){
		if(b[i].tx!=0){
			printf("%s %d\n",b[i].word,b[i].tx);
		}
	}
}
//Bài 14. Từ xuất hiện nhiều nhất, ít nhất
void b14(){
	char c[100005];
	fgets(c,100005,stdin);
	char *token=strtok(c," \n");
	char a1[50005][30];
	int k=0;
	while(token!=NULL){
		strcpy(a1[k],token);
		k++;
		token=strtok(NULL," \n");//printf("erorr");
	}
	qsort(a1,k,sizeof(a1[0]),cmp);
	int imax=0,imin=0,txmax=-1,txmin=1e9,count=1;
	for(int i=0;i<k;i++){
		if(strcmp(a1[i],a1[i+1])==0){
			count++;
		}else{
			if(txmax<=count){
				imax=i;
				txmax=count;
			}
			if(txmin>=count){
				imin=i;
				txmin=count;
			}
			count=1;
		}
	}
	printf("%s %d\n%s %d",a1[imax],txmax,a1[imin],txmin);
}
//Bài 15. Kiểm tra xâu con

int main(){
	char c1[100005];
	fgets(c1,100005,stdin);
	c1[strcspn(c1,"\n")]='\0';//cẩn thận nhầm với strspn nó sẽ đếm kí tự ko có trong "\n"và trả về stt 0 luôn
	char c2[100005];
	fgets(c2,100005,stdin);
	c2[strcspn(c2,"\n")]='\0';
	char *pos=strstr(c1,c2);
	if(pos==NULL){
		printf("NO");
	}else{
		printf("YES");
	}
	
	
	
	
	
	return 0;
}



