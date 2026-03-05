#include<stdio.h>
#include<math.h>

long long fibonacci(long long n){
	if(n==0) return 0; 
	if((n==1)||(n==2)) return 1;
	long long  res=0;
	long long f0=0;
	long long f1=1;
	for(int i=0;i<n-1;i++){
		res=f0+f1;
		f0=f1;
		f1=res;
	}
	return res;
}
void checkfibonacci(long long n){
	for(long long i=0;i<=92;i++){
		if(fibonacci(i)==n){
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}
void printfibo(long long n){
	for (long long  i=0;i<=n;i++){
		printf("%lld \n",fibonacci(i));
	}
	
}
int lt(int n,int k){//tinh nhi phan
	int res=1;
	while(k!=0){
		if (k%2!=0){
			res*=n;
		}
		n*=n;
		k/=2;
	}
	return res;
}

int main (){
	long long  a=2,k=10;
	printf("%lld",lt(a,k));
	return 0;
}