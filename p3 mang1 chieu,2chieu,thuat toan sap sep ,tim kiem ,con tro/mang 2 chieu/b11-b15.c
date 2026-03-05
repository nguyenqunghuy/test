#include<stdio.h>
#include<stdlib.h>

long long a[500][500],b[500][500];
long long bien_tam[500][500];
long long bien[500];

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
void xuat1(long long a[][500],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%lld ",a[i][j]);
		}
		printf("\n");
	}
}
//sort
int comparator(const void(*a),const void(*b)){
	int *x=(int*)a;
	int *y=(int*)b;
	return *x-*y;
}
//Bài 11. Sắp xếp hàng của ma trận
void b11(){
	int n=0;scanf("%d",&n);
	nhap(a,n,n);
	qsort(a,n,sizeof(int),comparator);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			bien[j]=a[i][j];
		}
		qsort(bien,n,sizeof(int),comparator);
		for(int j=0;j<n;j++){
			a[i][j]=bien[j];
		}
	}
	xuat(a,n,n);
}
//Nhân 2 ma trận
void nhan(int a[][500],int b[][500],int n,int m,int p){
	for(int i=0;i<n;i++){
		for(int j=0;j<p;j++){
			long long sum=0;
			for(int k=0;k<m;k++){
				sum+=a[i][k]*b[k][j];
			}
			bien_tam[i][j]=sum;
		}
	}
	for(long long i=0;i<n;i++){
		for(int j=0;j<p;j++){
			printf("%lld ",bien_tam[i][j]);
		}
		printf("\n");
	}
}
// ma tran xoan oc
void spiral_matrix(int n){
	int hang1=0,hang2=n-1,cot1=0,cot2=n-1;
	int res=1;
	while(res<=n*n){
		for(int i=cot1;i<=cot2;i++){
			a[hang1][i]=res++;
		}
		hang1++;
		for(int i=hang1;i<=hang2;i++){
			a[i][cot2]=res++;
		}
		cot2--;
		for(int i=cot2;i>=cot1;i--){
			a[hang2][i]=res++;
		}
		hang2--;
		for(int i=hang2;i>=hang1;i--){
			a[i][cot1]=res++;
		}
		cot1++;
	}
}
// Bài 15. Xoắn ốc Fibonacci
void fibonacci(int n){//cho n số fibonacci vào biến
	bien[0]=0;
	bien[1]=0;bien[2]=1;
	for(long long i=3;i<=n;i++){
		bien[i]=bien[i-1]+bien[i-2];
	}
}
void spiral_matrix2(int n){
	fibonacci(n*n);
	int hang1=0,hang2=n-1,cot1=0,cot2=n-1;
	int res=1;
	while(res<=n*n){
		for(int i=cot1;i<=cot2;i++){
			a[hang1][i]=bien[res++];
		}
		hang1++;
		for(int i=hang1;i<=hang2;i++){
			a[i][cot2]=bien[res++];
		}
		cot2--;
		for(int i=cot2;i>=cot1;i--){
			a[hang2][i]=bien[res++];
		}
		hang2--;
		for(int i=hang2;i>=hang1;i--){
			a[i][cot1]=bien[res++];
		}
		cot1++;
	}
}
int main(){
	int n=0;
	scanf("%d",&n);
	spiral_matrix2(n);
	xuat1(a,n,n);
	return 0;
}