#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
void b1(){
	char n[10000];
	scanf("%s",n);
	if(strlen(n)&1){
		printf("%c",n[strlen(n)/2+1-1]);
	}else{
		printf("NOT FOUND");
	}
}
void flip(char n[]){
	int l=0,r=strlen(n)-1;
	while(l<=r){
		int res=n[l];
		n[l]=n[r];
		n[r]=res;
		l++,r--;
	}
}
void to_thuong(char n[]){
	for(int i=0;i<strlen(n);i++){
		n[i]=tolower(n[i]);
	}
}
void to_hoa(char n[]){
	for(int i=0;i<strlen(n);i++){
		n[i]=toupper(n[i]);
	}
}
void b2(){
	char n[10001];
	scanf("%s",n);
	flip(n);
	printf("%s\n",n);
	flip(n);
	to_thuong(n);
	printf("%s\n",n);
	to_hoa(n);
	printf("%s\n",n);
}
//bai 3 chu so
void b3(){
	char n[10001];
	scanf("%s",&n);
	long long sum=0;
	for(int i=0;i<strlen(n);i++){
		if(isdigit(n[i])){
			sum+=n[i]-'0';
		}
	}
	printf("%lld",sum);
}
//b4 so dep
void b4(){
	char n[10001];
	scanf("%s",&n);
	for(int i=0;i<(int)strlen(n)-1;i++){
		if(fabs(n[i+1]-n[i])!=1){
			printf("NO");
			return;
		}
	}
	printf("YES");
}
//b5 chèn dấu phẩy
void b5(){
	char n[100];
	scanf("%s",&n);
	char c[100];
	// tạo ic 2 th để tránh ",123"
	int ic=(int)strlen(n)/3+(int)strlen(n)-1;
	if((int)strlen(n)%3==0){
		ic-=1;
	}
	//biến đếm mỗi 3 lần
	int count=0;
	for(int i= (int)strlen(n)-1;i>=0;i--){
		c[ic--]=n[i];
		count++;
		if(count==3){//lặp lại mỗi 3 lần
			c[ic--]=',';
			count=0;
			
		}
	}
	printf("%s",c);
}

//ham so sanhs
int comparator(void const *a,void const *b){
	char *x=(char*)a;
	char *y=(char*)b;
	return *x-*y;
}
void b6(){//Bài 6. Sắp xếp chữ số
	char n[100];
	scanf("%s",n);
	qsort(n,(int)strlen(n),sizeof(char),comparator);
	long long kq=atoll(n);
	printf("%lld",kq);
}

//Bài 7. In ra chữ số
void b7(){
	char n[10000];
	scanf("%s",n);
	for(int i=0;i<(int)strlen(n);i++){
		if(isdigit(n[i])){
			printf("%c",n[i]);
		}
	}
	printf("\n");
	for(int i=0;i<(int)strlen(n);i++){
		if(isalpha(n[i])){
			printf("%c",n[i]);
		}
	}
}
//Bài 8. 28tech vào Tèo
void b8(){
	char n[10001];
	scanf("%s",n);
	char tam[10001];int itam=0;
	char res[]="28tech";
	for(int i=0;i<(int)strlen(n);i++){
		int find=0;
		for(int j=0;j<6;j++){//neu tin tahy tra tri = '28tech' => find=1;
			if(n[i]==res[j]){
				find=1;
				break;
			}
		}
		if(find==0){
			tam[itam++]=n[i];
		}
	}
	if(tam[0]!=NULL){
		printf("%s",tam);
	}else{
		printf("EMPTY");
	}
}
//bai 9
void b9(){
	char n[10001];
	scanf("%s",n);
	int k=0;
	scanf("%d",&k);
	char res[]="28tech";
	for(int i=0;i<(int)strlen(n);i++){
		if(i==k){
			printf("%s",res);
		}
		printf("%c",n[i]);
	}
}
int main(){
	char n[10001];
	scanf("%s",n);
	int lwu=-1;
	for(int i=strlen(n)-1;i>0;i--){
		for(int j=i-1;j>=0;j--){
			if(n[i]==n[j]){
				lwu=j;
			}
		}
	}
	if(lwu==-1){
		printf("NONE");
	}else{
		printf("%c",n[lwu]);
	}
	return 0;
}





