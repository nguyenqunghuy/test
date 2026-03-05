#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>



int cmp(const void *a,const void *b){
	char* x=(char*)a;
	char* y=(char*)b;
	return strcmp(x,y);
}


void chuyen_sang_in_thuong(char res[][20],int k){
	for(int i=0;i<(int)strlen(res[k]);i++){
		res[k][i]=tolower(res[k][i]);
	}
}

void tach(char a[][20],int *k,char c[]){
	char* token=strtok(c," \n");
	while(token!=NULL){
		strcpy(a[*k],token);
		chuyen_sang_in_thuong(a,*k);
		(*k)++;
		token=strtok(NULL," \n");
	}
}
void b21(){
	
	char s[10000],t[10000];
	fgets(s,10000,stdin);
	fgets(t,10000,stdin);
	char res1[10005][20];
	char res2[10005][20];
	int k1=0;
	int k2=0;
	tach(res1,&k1,s);
	tach(res2,&k2,t);
	qsort(res1,k1,sizeof(res1[0]),cmp);
	qsort(res2,k2,sizeof(res2[0]),cmp);
	//dung thuat toan sort same mager sort
	char same[10005][20];
	int count=0,i1=0,i2=0;
	while((i1<k1)&&(i2<k2)){
		if(strcmp(res1[i1],res2[i2])==0){//res2[i1]=res[i2]
			if((count==0)||(strcmp(res1[i1],same[count-1])!=0)){
				strcpy(same[count],res1[i1]);
				count++;//
			}
			i1++;i2++;
		}else if((strcmp(res1[i1],res2[i2])<0)){//res2[i1]<res[i2]
			i1++;
		}else{//res2[i1]>res[i2]
			i2++;
		}
	}
	for(int i=0;i<count;i++){
		printf("%s ",same[i]);
	}
}
//Bài 22. Tập từ riêng của 2 xâu 
void b22(){
	
	char s[10000],t[10000];
	fgets(s,10000,stdin);
	fgets(t,10000,stdin);
	char res1[10005][20];
	char res2[10005][20];
	int k1=0;
	int k2=0;
	tach(res1,&k1,s);
	tach(res2,&k2,t);
	qsort(res1,k1,sizeof(res1[0]),cmp);
	qsort(res2,k2,sizeof(res2[0]),cmp);
	//dung thuat toan sort same mager sort
	char same[10005][20];
	int count=0,i1=0,i2=0;
	while((i1<k1)&&(i2<k2)){
		if(strcmp(res1[i1],res2[i2])==0){//res1[i1]=res2[i2]
			i1++;
		}else if((strcmp(res1[i1],res2[i2])<0)){//res1[i1]<res2[i2]
			if((count==0)||(strcmp(res1[i1],same[count-1])!=0)){
				strcpy(same[count],res1[i1]);
				count++;//
			}
			i1++;
		}else{//res1[i1]>res2[i2]
			i2++;
		}
	}
	while(i1<k1){
		if((count==0)||(strcmp(res1[i1],same[count-1])!=0)){
			strcpy(same[count],res1[i1]);
			count++;//
		}
		i1++;
	}
	for(int i=0;i<count;i++){
		printf("%s ",same[i]);
	}
}
///Bài 23. Ghép xâu
int cmp_2(const void *a,const void *b){
	char* y=(char*)a;
	char* x=(char*)b;
	char noi_1[1000];strcpy(noi_1,x);
	char noi_2[1000];strcpy(noi_2,y);
	strcat(noi_1,y);//a+b
	strcat(noi_2,x);//b+a
	return strcmp(noi_1,noi_2);
}
void b23(){
	int k=0;scanf("%d",&k);getchar();
	char c[k][100];
	for(int i=0;i<k;i++){
		scanf("%s",c[i]);
	}
	qsort(c,k,sizeof(c[0]),cmp_2);
	for(int i=0;i<k;i++){
		printf("%s",c[i]);
	}
}
// b24 xau dau cuoi
void b24(){
	char c[100000];
	scanf("%s",c);
	int chuso[30]={0};
	for(int i=0;i<(int)strlen(c);i++){
		chuso[c[i]-'a']++;
	}
	long long count=strlen(c);
	for(int i=0;i<26;i++){
		if(chuso[i]==0)continue;
		count+=1ll*chuso[i]*(chuso[i]-1)/2;
	}
	printf("%lld",count);
}
//Bài 25. Số lớn nhất, nhỏ nhất


int main(){
	int m=0,s=0;scanf("%d%d",&m,&s);
	if((m*9<s)||((s==0)&&(m>=2))){
		printf("NOT FOUND");return 0;
	}
	if((m==1)&&(s==0)){
		printf("0 0");
		return 0;
	}
	int be[105]={0};
	int lon[105]={0};
	int res=s;
	for(int i=0;i<m;i++){
		if(res>=9){
			lon[i]=9;res-=9;
		}else{
			lon[i]=res;res=0;
		}
	}
	res=s-1;
	for(int i=m-1;i>=0;i--){
		if(res>=9){
			be[i]=9;res-=9;
		}else{
			be[i]=res;res=0;
		}
	}
	be[0]=res+1;// worng here
	for(int i=0;i<m;i++){
		printf("%d",be[i]);
	}
	printf("\n");
	for(int i=0;i<m;i++){
		printf("%d",lon[i]);
	}
	return 0 ;
}


