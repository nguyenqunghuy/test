#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


//Bài 26. Xâu con liên tiếp 1
struct xaucon{
	char c;
	int tx;
};
typedef struct xaucon xc;
int cmp(const void *a,const void *b){
	xc *y=(xc*)a;
	xc *x=(xc*)b;
	if(x->tx==y->tx){
		return x->c-y->c;
	}else {
		return x->tx-y->tx;
	}
}
void b26(){
	xc a[100000];
	char c[100000];
	fgets(c,100000,stdin);
	c[(int)strlen(c)-1]='\0';
	int slxau=0;
	for(int i=0;i<(int)strlen(c);i++){
		int count=1;
		a[slxau].c=c[i];
		while(c[i]==c[i+1]){
			count++;
			i++;
			//printf("%c\n",c[i]);
		}
		a[slxau].tx=count;
		slxau++;
	}
	//printf("erorr");
	//printf("%d\n",slxau);
	qsort(a,slxau,sizeof(xc),cmp);
	//for(int i=0;i<slxau;i++){
	//	printf("%c %d\n",a[i].c,a[i].tx);
	//}
	for(int i=0;i<a[0].tx;i++){
		printf("%c",a[0].c);
	}

}
//Bài 27. Xâu con liên tiếp 2
void b27(){
	char c[100005];
	fgets(c,100005,stdin);
	int dodai=strlen(c);
	if(c[dodai-1]=='\n')c[dodai-1]='\0';//loi exept'u' find'u'
	dodai=strlen(c);
	int max_len=0;
	int frist=0;
	int end=0;

	for(int i=0;i<dodai;i++){
		int len=1;
		int res=i;
		while((c[i]!=c[i+1])&&(i<dodai-1)){
			len++;
			i++;
		}
		if(max_len<len){
			max_len =len;
			frist=res;
			end=i;
		}else if(max_len==len){
			if(strncmp(&c[frist],&c[res],len)<0){
				frist=res;
				end=i;
			}
		}
	}
	for(int i=frist;i<=end;i++){
		printf("%c",c[i]);
	}
}
//Bài 28. Số lớn nhất trong xâu
int cmp_28(const void* a,const void*b){// so sánh sâu có số bé đến lớn 
	char* x=(char*)a;
	char* y=(char*)b;
	if(strlen(x)==strlen(y)){
		return strcmp(x,y);
	}else{
		return strlen(x)-strlen(y);
	}
}
char a[50005][1005];
void b28(){
	char c[100005];
	scanf("%s",c);
	// loại bỏ các kí tự chữ cái bằng đấu ' '
	for(int i=0;i<(int)strlen(c);i++){
		if(isalpha(c[i])){
			c[i]=' ';
		}
	}
	// dùng token to tách
	char *token=strtok(c," \n");
	int k=0;
	while(token!=NULL){
		//loai bo so 0
		int res=-1;
		for(int i=0;i<(int)strlen(token);i++){
			if(token[i]!='0'){// luu vin tri số khác 0 đâu tiên
				res=i;
				break;
			}	
		}
		if(res==-1){//xet th cả số là 00000000000 
			strcpy(a[k],"0");k++;
		}else{
			// copy sâu
			int pos=0;
			for(int i=res;i<(int)strlen(token);i++){
				a[k][pos]=token[i];pos++;
			}
			a[k][pos]='\0';
			k++;
		}
		token=strtok(NULL," \n");
	}
	qsort(a,k,sizeof(a[0]),cmp_28);
	printf("%s",a[k-1]);
}
// Bài 29. Tổng các số trong xâu
void b29(){
	char c[100005];
	scanf("%s",c);
	// loại bỏ các kí tự chữ cái bằng đấu ' '
	for(int i=0;i<(int)strlen(c);i++){
		if(isalpha(c[i])){
			c[i]=' ';
		}
	}
	// dùng token to tách
	char *token=strtok(c," \n");
	int k=0;
	while(token!=NULL){
		strcpy(a[k],token);
		token=strtok(NULL," \n");
		k++;
	}
	long long count=0;
	for(int i=0;i<k;i++){
		count+=atoll(a[i]);
	}
	printf("%lld",count);
}
// Bài 30. Ghép xâu
int cmp_30(const void* a,const void* b){
	char* x=(char*)a;
	char* y=(char*)b;
	char res1[10000];strcpy(res1,x);strcat(res1,y);
	char res2[10000];strcpy(res2,y);strcat(res2,x);
	return strcmp(res2,res1);
}




int main(){
	char c[100005];
	scanf("%s",c);
	// loại bỏ các kí tự chữ cái bằng đấu ' '
	for(int i=0;i<(int)strlen(c);i++){
		if(isalpha(c[i])){
			c[i]=' ';
		}
	}
	// dùng token to tách
	char *token=strtok(c," \n");
	int k=0;
	while(token!=NULL){
		// loai bo so 0
		int res=-1;
		for(int i=0;i<(int)strlen(token);i++){
			if(token[i]!='0'){// luu so dau tien khac 0;
				res=i;break;
			}
		}
		if(res==-1){
			strcpy(a[k],"0");k++;
		}else{
			int tam=0;
			for(int i=res;i<(int)strlen(token);i++){
				a[k][tam]=token[i];
				tam++;
			}
			a[k][tam]='\0';
			k++;
		}
		token=strtok(NULL," \n");
	}
	qsort(a,k,sizeof(a[0]),cmp_30);
	for(int i=0;i<k;i++){
		printf("%s",a[i]);
	}
	return 0;
}



