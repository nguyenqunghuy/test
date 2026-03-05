#include<stdio.h>

//Bài 11. Liệt kê và đếm số Fibonacci
long long f[100];
void ganfibo(long long f[]){//gan gia tri fibonaci vao mang
	f[0]=0;
	f[1]=1;
	for(int j=2;j<93;j++){
		f[j]=f[j-1]+f[j-2];
	}
}
int check(long long n){
	for(int i=0;i<=92;i++){
		if(f[i]==n){
			return 1;
		}
	}
	return 0;
}
///Bài 12. Vị trí số lớn nhất, nhỏ nhất
void maxmin(int a[],int t){
	int max=0,min=10e6;
	int countmax=0;
	int countmin=0;
	for(int i=0;i<t;i++){//find max
		if(a[i]>max){
			max=a[i];
			countmax=i;
		}
		if(a[i]<=min){
			min=a[i];
			countmin=i;
		}
	}
	printf("%d ",countmin);	
	printf("%d",countmax);
}
//Bài 13. Tính tổng và tích các phần tử
/*
	int t=0;
	scanf("%d",&t);
	int a[t];
	for(int i=0;i<t;i++){
		scanf("%d",&a[i]);
	}
	long long sum1=0;
	for(int j=0;j<t;j++){
		sum1+=a[j];
		sum1%=1000000007;
	}
	long long tich1=1;
	for(int k=0;k<t;k++){
		tich1*=a[k];
		tich1%=1000000007;
	}
	printf("%lld\n",sum1);
	printf("%lld", tich1);

*/
//Bài 14. gcd của mảng
int ucln(int a,int b){
	while(b!=0){
		int res3=a%b;
		a=b;
		b=res3;
	}
	return a;
}
int b14(int a[],int t){
	int res=a[0];
	for(int i=1;i<t;i++){
		res=ucln(res,a[i]);
	}
	return res;
}
//Bài 15. Số lớn nhất, lớn thứ 2

void erase(int a[],int t,int n){
	int max=0;
	for(int i=0;i<t;i++){
		if(n==a[i]){
			a[i]=-1;
			return;
		}
	}
}
int b15(int a[],int t){
	int max=0;
	for(int i=0;i<t;i++){
		if(a[i]>max){
			max=a[i];
		}	
	}
	printf("%d ",max);
	erase(a,t,max);
	max=0;
	for(int i=0;i<t;i++){
		if(a[i]>max){
			max=a[i];
		}	
	}
	printf("%d",max);
}
int main(){
	int t=0;
	scanf("%d",&t);
	int a[t];
	for(int i=0;i<t;i++){
		scanf("%d",&a[i]);
	}
	b15(a,t);
	return 0;	
}