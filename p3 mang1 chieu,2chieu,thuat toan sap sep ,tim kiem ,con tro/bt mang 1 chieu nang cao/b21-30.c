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
long long bien[1000001];
void b22(){
	long long t=0;
	scanf("%lld",&t);
	long long a[t];
	for(int i=0;i<t;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<1000001;i++){
		bien[i]=0;
	}
	for(int i=0;i<t;i++){
		bien[a[i]]++;
		if(bien[a[i]]==2){
			printf("%lld",a[i]);
			return ;
		}
	}
	printf("-1");
	return ;
}
//Bài 23. Trộn 2 dãy đã sắp xếp
//quicksoft
int quick(long long a[],int l,int r){
	int ia=l-1;
	for(int i=l;i<r;i++){
		if(a[i]<=a[r]){
			int res=a[i];
			a[i]=a[++ia];
			a[ia]=res;
		}
	}
	int res=a[r];
	a[r]=a[++ia];
	a[ia]=res;
	return ia;
}
void quicksoft(long long a[],int l,int r){
	if(l<r){
		int mid=quick(a,l,r);
		quicksoft(a,l,mid-1);
		quicksoft(a,mid+1,r);
	}
}



int main(){
	long long t=0;
	scanf("%lld",&t);
	long long a[t],b[t];
	for(int i=0;i<t;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<t;i++){
		scanf("%lld",&b[i]);
	}
	quicksoft(a,0,t-1);
	quicksoft(b,0,t-1);
	int ia=0,ib=t-1;
	for(int i=1;i<=t*2;i++){
		if(i%2!=0){
			printf("%lld ",a[ia++]);
		}else{
				printf("%lld ",b[ib--]);
			}
		}
		
		
	
	
	return 0;
}



