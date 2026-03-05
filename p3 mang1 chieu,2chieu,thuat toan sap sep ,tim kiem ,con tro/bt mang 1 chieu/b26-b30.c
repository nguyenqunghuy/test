#include<stdio.h>

int mark[1000001];
int dem(int a[],int t ){
	for(int i=0;i<t;i++){
		mark[a[i]]=1;
	}
	int count=0;
	for(int i=0;i<1000001;i++){
		if(mark[i]==1){
			count++;
		}
	}
	printf("%d",count);
}
//Bài 27. Mảng đánh dấu 2
void mark2(int a[],int t){
	for(int i=0;i<t;i++){
		mark[a[i]]++;
	}
}
//b28
int mark3(int a[],int t){
	mark2(a,t);
	for(int i=0;i<t;i++){
		if(mark[a[i]]==-1){//tranh lap lai
			continue;
		}
		printf("%d %d\n",a[i],mark[a[i]]);
		mark[a[i]]=-1;//doi bien tranh lap
	}
}
//b29
void mark4(int a[],int t){
	mark2(a,t);
	int max=0;
	for(int i=0;i<1000001;i++){//tim max lap
		if(mark[i]>max){
			max=mark[i];
		}
	}
	for(int i=0;i<1000001;i++){//tim so max lap nho nhat theo gia tri
		if(mark[i]==max){
			printf("%d %d",i,max);
			return;
		}
	}
}
//b30
void mark5(int a[],int t){
	mark2(a,t);//danh dau so lan xuat hien
	int max=0;
	for(int i=0;i<1000001;i++){//tim max lap
		if(mark[i]>max){
			max=mark[i];
		}
	}
	for(int i=0;i<t;i++){//tim so lap max theo thu tu xuat hien
		if(mark[a[i]]==max){
			printf("%d %d",a[i],max);
			return;
		}
	}
}
int main(){
	int t=0;
	scanf("%d",&t);
	int a[t];
	for(int i=0;i<t;i++){
		scanf("%d",&a[i]);
	}
	mark5(a,t);
	return 0;
}