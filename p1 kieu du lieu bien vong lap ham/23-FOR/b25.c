#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	double ao1=1;
	n=n-1;
	for(int i=1;i<=n;i++){
		double ao2=1;
		for(int k=1;k<=i;k++){
			ao2=ao2*k;
		}
		ao1+=1/ao2;
	}
	printf("%.4lf",ao1);
	
	
	
	
	return 0;
}