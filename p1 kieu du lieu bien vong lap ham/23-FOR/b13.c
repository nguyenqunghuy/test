#include<stdio.h>
#include<math.h>

int main(){
	int n;
	long long res=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		if(i%2!=0){
			res+=i;
		}
	}
	printf("%lld",res);
	return 0;
}