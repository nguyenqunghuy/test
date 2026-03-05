#include<stdio.h>

int main(){
	long long n;
	scanf("%lld",&n);
	int sum=0;
	sum=n/28;//so vo chai chua doi
	int vo=sum;
	while(vo>=3){
		sum+=1;
		vo-=2;
	}
	printf("%d",sum);
	return 0;
}