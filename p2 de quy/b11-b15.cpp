#include<stdio.h>
//Bài 11. Thập phân sang nhị phân
void np(long long n){
	if(n>1)np(n/2);
	printf("%lld",n%2);	
}
//B12. Thập phân sang hệ thập lục phân
void tlp(long long n){
	if(n>=16){
		tlp(n/16);
	}
	if((n%16)<10){
		printf("%lld",n%16);
	}
	if(n%16==10)printf("A");
	if(n%16==11)printf("B");
	if(n%16==12)printf("C");
	if(n%16==13)printf("D");
	if(n%16==14)printf("E");
	if(n%16==15)printf("F");
}
//Bài 13. Tìm tổng chữ số của N
long long tongsh(long long n){
	if(n<10)return n;
	return tongsh(n/10)+n%10;	
}
//Bài 14. Đếm số chữ số của N
long long demsh(long long n){
	if(n<10)return 1;
	return demsh(n/10)+1;	
}
//Bài 15. Tìm chữ số đầu tiên của số nguyên
void find(long long n){
	if(n<10) {
		printf("%lld",n);
		return;	
	}
	find(n/10);
}
int main(){
	long long n=0;
	scanf("%lld",&n);
	find(n);	
	return 0;
}