#include<stdio.h>
#include<stdlib.h>
int a[500][500];
int bien[400];

void nhap(int a[][500],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void xuat(int a[][500],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
//b6 hoan vi
void b6(int a[][500],int n){
	int j=n;
	for(int i=0;i<n;i++){
		int res=a[i][i];
		a[i][i]=a[i][j-1-i];
		a[i][j-1-i]=res;
	}
}
//Bài 7. Hoán vị 2 hàng
void b7(int a[][500],int n,int u,int v){
	for(int i=0;i<n;i++){
		int res=a[u][i];
		a[u][i]=a[v][i];
		a[v][i]=res;
	}
}
//Bài 8. Hoán vị 2 cột
void b8(int a[][500],int n,int u,int v){
	for(int i=0;i<n;i++){
		int res=a[i][u];
		a[i][u]=a[i][v];
		a[i][v]=res;
	}
}
//Bài 9. Đếm nguyên tố 1
int snt(int a){
	if(a<2){
		return 0;
	}
	for(int i=2;i*i<=a;i++){
		if(a%i==0){
			return 0;
		}
	}
	return 1;
}
int comparator(const void *a,const void *b){
	int *x=(int*)a;
	int *y=(int*)b;
	return *x-*y;
}
int main(){
	int n;
	scanf("%d",&n);
	nhap(a,n,n);
	int count=1,res=0;
	for(int i=0;i<n;i++){
		if(snt(a[i][n-1-i]))bien[res++]=a[i][n-1-i];//check tren dg cheo phu
		if(snt(a[i][i]))bien[res++]=a[i][i];//check tren dg cheo chinh
	}
	if(res==0){
		printf("0");return 0;
	}
	qsort(bien,res,sizeof(int),comparator);
	for(int i=0;i<res-1;i++){
		if(bien[i]!=bien[i+1]){
			count++;	
		}
	}
	printf("%d",count);
	return 0;
}