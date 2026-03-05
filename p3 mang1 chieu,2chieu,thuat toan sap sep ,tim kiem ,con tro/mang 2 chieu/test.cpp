#include<stdio.h>
#include<math.h>
int a[505][505];
int n,m;
void nhap(int a[][505],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
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