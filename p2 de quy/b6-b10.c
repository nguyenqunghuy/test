#include<stdio.h>
#include<math.h>


//Bài 6. Fibonacci
int f(int n){
	if(n==1)return 0;
	if(n==2)return 1;
	return f(n-1)+f(n-2);
}
//Bài 7. Tổ hợp
int c(int n ,int k){
	if((k==n)||(k==0)){
		return 1;
	}
	return c(n-1,k-1)+c(n-1,k);
}
//Bài 8. UCLN & BCNN
long long ucln(long long a,long long b){
	if(b==0){
		return a;
	}
	return ucln(b,a%b);	
}
long long bcnn(long long a,long long b){
	return a/(ucln(a,b))*b;
}
//Bài 9. Lũy thừa nhị phân
long long lt(long long a, long long b){//Binary Exponentiation= fast power
	if(b==0){
		return 1;
	}
	long long res=lt(a,b/2);
	if(b%2==0){
		return ((res%1000000007)*(res%1000000007))%1000000007;
	}else{
		return ((res%1000000007)*(res%1000000007)%1000000007*(a%1000000007))%1000000007;
	}   
}
//Bài 10. Tính tổng 5
double b10(double n){//S(n) = 1/1 + 1/2 + 1/3 + ... + 1/n 
	if(n==1){
		return 1;
	}
	return (double)1/n+b10(n-1);
}
int main(){
	double n=10;
	scanf("%lf",&n);
	printf("%.3lf",b10(n));
	return 0;
}