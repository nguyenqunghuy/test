#include<stdio.h>
#include<math.h>
int a[505][505];
int n,m,s,t,u,v;
int res1[100001];
int res2[100001];
void nhap(int a[][505],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
//Bài 21. Đường đi của quân Mã
int d_hang_ma[8]={-2,-2,-1,-1,1,1,2,2};
int d_cot_ma[8]={-1,1,-2,2,-2,2,-1,1};
void ma(int i,int j){//i,j laf vin tri cua ma
	a[i][j]=0;
	for(int k=0;k<8;k++){
		int hang_moi=i+d_hang_ma[k];
		int cot_moi=j+d_cot_ma[k];
		if((0<=hang_moi)&&(hang_moi<n)&&(0<=cot_moi)&&(cot_moi<n)&&(a[hang_moi][cot_moi])){
			ma(hang_moi,cot_moi);
		}
	}
}
//Bài 22. Snake
void snake(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i%2==0){
				printf("%d ",a[i][j]);
			}else{
				printf("%d ",a[i][n-j-1]);
			}
		}
		printf("\n");
	}
}
//b23 biên của ma trận
void bien(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((i==0)||(j==0)||(i==(n-1))||(j==(n-1))){
				printf("%d ",a[i][j]);
			}
		}
	}
}
//b24
void b24(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			res1[a[i][j]]=1;
		}
		for(int k=0;k<=100000;k++){
			if((res1[k]==1)&&(res2[k]==i)){
				res2[k]++;
			}
			res1[k]=0;
		}
	}
	/* main
	for(int k=0;k<=100000;k++){
		res1[k]=0;
		res2[k]=0;
	}
	b24();
	int ress=0;
	for(int k=0;k<=100000;k++){
		if(res2[k]==n){
			printf("%d ",k);
			ress=1;
		}
	}
	if(ress==0){
		printf("NOT FOUND");
	}
	*/
}
// Bài 25. Diện tích
int hang[4]={-1,0,0,1};
int cot[4]={0,-1,1,0};
int count=0;
void electric_charge(int i1,int j1){
	count++;
	a[i1][j1]=0;
	for(int i=0;i<4;i++){
		int imoi=i1+hang[i];
		int jmoi=j1+cot[i];
		if((imoi>=0)&&(imoi<n)&&(jmoi>=0)&&(jmoi<m)&&a[imoi][jmoi]){
			electric_charge(imoi,jmoi);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	nhap(a,n,m);
	int max=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if((a[i][j])==1){
				count=0;
				electric_charge(i,j);
				max=fmax(count,max);
			}
		}
	}
	printf("%d",max);
	return 0;
}


