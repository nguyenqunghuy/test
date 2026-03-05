#include<stdio.h>
#include<math.h>


//Bài 1.Tính tổng 1
int b1(int n){
	if(n<=1){
		return 1;
	}
	return n+b1(n-1);
}
//Bài 2. Tính tổng 2
long long b2(long long n){//S(n) = 1^2 + 2^2 + 3^2 + 4^2 + .. + n^2
	if(n<=1){
		return 1;
	}
	return pow(n,2)+b2(n-1);
}
//Bài 3. Tính tổng 3
long long b3(long long n){//S(n) = 1^3 + 2^3 + 3^3 + 4^3 + .. + n^3
	if(n<=1){
		return 1;
	}
	return pow(n,3)+b3(n-1);
}
//Bài 4. Tính tổng 4
long long b4(long long n){//S(n) = -1 + 2 -3 + 4 - 5 + 6 + ... + (-1)^n * n
	if(n<=0){
		return 0;
	}
	if(n%2==0){
		return n+(b4(n-1));
	}else{
		return -n+(b4(n-1));
	}
}

//Bài 5. Tính giai thừa
long long b5(long long n){
	if(n<=1){
		return 1;
	}
	return n*(b5(n-1));
}
int main(){
	long long n=0;
	scanf("%lld",&n);
	printf("%lld",b5(n));

	return 0;
}