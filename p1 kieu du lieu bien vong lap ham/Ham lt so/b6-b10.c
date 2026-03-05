#include <stdio.h>
#include <math.h>
long long sumuoc(long long n){//Bài 23. Tổng ước
	long long sum=0;
	for(long long i=1;i*i<=n;i++){
		if(n % i == 0){
			sum+=i;
			if(( n/i ) != ( i )){
				sum+=(n/i);
			}
		}
	}
	return sum;
}
long long cp(long long n){//chinh phuong
	long long res=sqrt(n);
	if(n==res*res){
		return 1;
	}else{
		return 0;
	}
}
int checkcp(long long a,long long b){//Bài 22. Số chính phương 3
	int  count=0;
	count=floor(sqrt(b))-ceil(sqrt(a))+1;	//congo thuc số số hạng = (sln+snn)/kc+1
	return count;
}
void sl(long long n){//Bài 25. Số có lượng ước là số lẻ note : là số chính phương
	if (cp(n)){
		printf("YES");
	}else{
		printf("NO");
	}




}
int main(){
  long long a=0;
  scanf("%lld",&a);
  sl(a);
  
  return 0;
}