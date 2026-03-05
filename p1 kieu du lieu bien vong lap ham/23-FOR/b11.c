#include<stdio.h>
#include<math.h>

int main(){
	int n;
	long long sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		if(i%2==0){
			sum+=i;
		}else{
			sum-=i;
		}
	}
	printf("%lld",sum);
	
	
	
	return 0;
	
}