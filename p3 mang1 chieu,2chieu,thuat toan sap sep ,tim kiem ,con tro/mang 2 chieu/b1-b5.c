#include<stdio.h>



int a[500][500];


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
//Bài 1. Liệt kê các số nguyên tố trong mảng 2 chiều
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
void b1(int a[][500],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(snt(a[i][j])){	
				printf("%d ",a[i][j]);
			}
		}
		printf("\n");
	}
}
//Bài 2. Tổng hàng, tổng cột
void b2(int a[][500],int n,int m){
	for(int i=0;i<n;i++){//tong hang
		long long sum =0;
		for(int j=0;j<m;j++){
			sum+=a[i][j];
		}
		printf("%lld ",sum);
	}
	printf("\n");
	for(int i=0;i<m;i++){//tong hang
		long long sum =0;
		for(int j=0;j<n;j++){
			sum+=a[j][i];
		}
		printf("%lld ",sum);
	}
}
//Bài 3. Số lớn nhất, nhỏ nhất
void b3(){
	int n,m ,max=0,min=1e9;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]>max)max=a[i][j];
			if(a[i][j]<min)min=a[i][j];
		}
	}
	printf("%d\n",min);
	for(int i=0;i<n;i++){//in vin tri cac so = min
		for(int j=0;j<m;j++){
			if(a[i][j]==min){
				printf("%d %d\n",i+1,j+1);
			}
		}
	}
	printf("%d\n",max);
	for(int i=0;i<n;i++){//in vin tri cac so = min
		for(int j=0;j<m;j++){
			if(a[i][j]==max){
				printf("%d %d\n",i+1,j+1);
			}
		}
	}
}
//Bài 4. Số thuận nghịch tam giác dưới
int check_flip(int a){
	int res=0,tmp=a;
	while(a!=0){
		res=a%10+res*10;
		a/=10;
	}
	if(tmp==res){
		return 1;
	}else{
		return 0;
	}
}
void b4(){
	int n;
	scanf("%d",&n);
	nhap(a,n,n);
	int count=0;
	for(int i=0;i<n;i++){// ra cac so thuoc tam giac duoi
		for(int j=0;j<n;j++){
			if(j<=i){
				if(check_flip(a[i][j])){
					count++;	
				}
			}
		}
	}
	printf("%d",count);
}
//Bài 5. In ma trận theo mẫu

int main(){
	int n;
	scanf("%d",&n);
	nhap(a,n,n);
	printf("Pattern 1:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[j][i]);
		}
		printf("\n");
	}
	printf("Pattern 2:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[n-i-1][n-j-1]);
		}
		printf("\n");
	}
	printf("Pattern 3:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[j][n-i-1]);
		}
		printf("\n");
	}
	printf("Pattern 4:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][n-1-j]);
		}
		printf("\n");
	}
	return 0;
}