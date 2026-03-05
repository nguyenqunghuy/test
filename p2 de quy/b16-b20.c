#include<stdio.h>
#include<math.h>

// Bài 16. Chữ số lớn nhất, nhỏ nhất
void csln(long long n,int res){//cho res ban đầu =0
	if(n<10){
		if(n>res)res=n;
		printf("%d ",res);
		return;
	}
	if((n%10)>=res){
		csln(n/10,n%10);
	}else{
		csln(n/10,res);
	}	
}
void csnn(long long n,int res){//cho res ban đầu =9 
	if(n<10){
		if(n<res)res=n;
		printf("%d",res);
		return;
	}
	if((n%10)<=res){
		csnn(n/10,n%10);
	}else{
		csnn(n/10,res);
	}	
}
//Bài 17. In ra số nguyên
void ltr(long long n){//left to right
	if(n<10){
		printf("%lld ",n);
		return;
	}
	ltr(n/10);
	printf("%lld ",n%10);
}
void rtl(long long n){//right to left
	if(n<10){
		printf("%lld ",n);
		return;
	}
	printf("%lld ",n%10);
	rtl(n/10);
}
// Bài 18. Tính tổng chữ số chẵn lẻ
long long sumc(long long n){//sum chan
	if(n==0)return 0;
	if(n%2==0){
		return n%10+sumc(n/10);
	}else{
		return sumc(n/10);
	}
}
long long suml(long long n){//sum le
	if(n==0)return 0;
	if(n%2==1){
		return n%10+suml(n/10);
	}else{
		return suml(n/10);
	}
}
//Bài 19. Kiểm tra chữ số chẵn
long long check(long long n){
	if(n==0)return 1;
	if((n%2)==0){
		return check(n/10)*1;
	}else{
		return check(n/10)*0;
	}
}
//Bài 20. Đếm số thao tác
int count(int n){
	if(n==1)return 0;
	int res1 = 100000000,res2 = 100000000,res3 = 100000000;
	if(n % 2 ==0) res1 = count(n / 2) + 1;
	if(n % 3 ==0) res2 = count(n / 3) + 1;
	if(n > 1) res3 = count( n - 1) + 1;
	return fmin(res1,fmin(res2,res3));
	
}


int main(){
	int t=0,n=0;
	long long res=0;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		res=res*10+n;
	}
	checkdx(res,t);
}