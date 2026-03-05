#include<stdio.h>


//Bài 63. Fibonacci 1
long long f1c1(long long n ){
	if((n==0)||(n==1)){
		return 0;
	}else if(n==2){
		return 1;
	}else{
		return f1c1(n-1)+f1c1(n-2);
	}
}
long long f1c2(long long n){
	if(n==1)return 0;
	if(n==2)return 1;
	long long kq=0,res1=0,res2=1;	
	for(int i=3;i<=n;i++){
		kq=(res1+res2)%1000000007;
		res1=res2;
		res2=kq;
	}
	return kq;
}
//Bài 64. Số Fibonacci 2
int checkf(long long n){//check
	if((n==0)||(n==1)){
		return 1;
	}
	long long kq=0,res1=0,res2=1;	
	for(int i=3;i<=93;i++){// max fibo trong long long la 92, 93 se bi tran
		kq=(res1+res2);
		res1=res2;
		res2=kq;
		if(kq==n){
			return 1;
		}
	}
	return 0;
}
///Fibonacci 3
long long f3(long long n){
	if(n==1)return 1;
	long long kq=0,res1=1,res2=1;
	for(int i=1;i<=92;i++){
		kq=res1+res2;
		res1=res2;
		res2=kq;
		if(kq>=n){
			return kq;
		}
	}
	return -1;
}
//f4
int snt(int n){//check so nguyen to
	if(n<2)return 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int countssh(int n){//tinh tong sh
	int res=0;
	while(n!=0){
		res+=n%10;
		n/=10;
	}
	return res;
}
void f4(long long n){
	for(int i=2;i<=n;i++){
		if((checkf(countssh(i)))&&(snt(i))){
			printf("%d ",i);
		}
	}
}
int main(){
	long long n=0,t=0;
	scanf("%lld",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		if(checkf(n)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}	
	}
	return 0;
}

