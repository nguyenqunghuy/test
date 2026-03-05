#include<stdio.h>
#include<math.h>
int main (){
	long long n;
	scanf("%lld",&n);
	int sum=0;
	for(int i=1;;){
		if(n/10!=0){
			sum+=1;
			n/=10;
		}else{
			sum+=1;
			break;
		}
	}
	printf("%d",sum);
	return 0;
}