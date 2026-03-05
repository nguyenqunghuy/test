#include<stdio.h>

int main(){
	int n=0;
	scanf("%d",&n);
	int a[n][n];
	int hang1=0,hang2=n-1,cot1=0,cot2=n-1;
	int dem=1;
	while(dem<=n*n){
		for(int i=cot1;i<=cot2;i++){
			a[hang1][i]=dem++;
		}
		hang1++;
		for(int i=hang1;i<=hang2;i++){
			a[i][cot2]=dem++;
		}
		cot2--;
		for(int i=cot2;i>=cot1;i--){
			a[hang2][i]=dem++;
		}
		hang2--;
		for(int i=hang2;i>=hang1;i--){
			a[i][cot1]=dem++;
		}
		cot1++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}