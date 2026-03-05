#include<stdio.h>


//b20
void b20(){
	long long t=0,k=0;
	scanf("%lld%lld",&t,&k);
	long long a[t];
	long long mangcongdon[t+1];
	mangcongdon[0]=0;
	for(int i=0;i<t;i++){
		scanf("%lld",&a[i]);
		mangcongdon[i+1]=mangcongdon[i]+a[i];
	}
	
	long long sum=0,summax=0,pos=0;
	for(int i=1;i<=t-k+1;i++){//find summax tren mangcongdon
		sum=mangcongdon[i+k-1]-mangcongdon[i-1];
		if(summax<sum){
			summax=sum;
			pos=i-1;//vintri frist cua mang lon nhat
		}
	}
	printf("%lld\n",summax);
	for(int i=0;i<k;i++){
		printf("%lld ",a[pos+i]);
	}
}
//Bài 22. Số bị lặp lại đầu tiên



int main(){
	long long t=0;
	scanf("%lld",&t);
	long long a[t];
	for(int i=0;i<t;i++){
		scanf("%lld",&a[i]);
	}
	long long bien[1000001];
	for(int i=0;i<1000001;i++){
		bien[i]=0;
	}
	for(int i=0;i<t;i++){
		bien[a[i]]++;
		if(bien[a[i]]==2){
			printf("%lld",a[i]);
//			return 0;
		}
	}
	printf("-1");
}
