#include<stdio.h>

int a[500][500],b[500][500];
int nhan[500][500],bien[500][500];

void nhap(int a[][500],int n,int m ){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void xuat(int a[][500],int n,int m ){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void nhan_2mang(int a[][500],int b[][500],int n1,int m1,int n2,int m2){
	if(m1!=n2){//chi nhan dc khi m1==n2
		printf("ko the nhan");
		return;	
	}
	for(int i=0;i<n1;i++){
		for(int j=0;j<m2;j++){
			long long res=0;
			for(int k=0;k<m1;k++){
				res+=a[i][k]*b[k][j];//printf("ko the nhan");
			}
			nhan[i][j]=res;
		}
	}
	xuat(nhan,n1,m2);
}
void ma_tran_chuyen_vi(int a[][500],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			bien[j][i]=a[i][j];
		}
	}
	xuat(bien,m,n);
}
void ma_tran_vuong(int a[][500],int n,int m){// co so hang bang so cot
	//in ra tam giac duoi
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i<=j){
				printf("%d ",a[i][j]);
			}else{
				printf("  ");
			}
		}
		printf("\n");
	}
	
	
	
}
int main(){
	int n,m,n2,m2;
	scanf("%d%d",&n,&m);
	nhap(a,n,m);
//	scanf("%d%d",&n2,&m2);
//	nhap(b,n2,m2);
	ma_tran_vuong(a,n,m);
	
	
	return 0;
}




