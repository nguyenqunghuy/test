#include<stdio.h>

int main(){
	int n=0;
	scanf("%d",&n);int sum1=0;
	for(int i=1;i<=n;i++){
		int sum2=1;
		for(int k=1;k<=i;k++){
			sum2*=k;
		}
		sum1+=sum2;
	}
	printf("%d",sum1);
	
	
	
	
	return 0;
}