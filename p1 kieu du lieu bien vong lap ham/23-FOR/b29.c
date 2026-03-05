#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	long long sum=0,ao=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&ao);
		if (ao%2==0){
			sum+=ao;
		}	
	}
	printf("%lld",sum);
	
	
	return 0;
}


