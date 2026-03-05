#include<stdio.h>
#include<math.h>



// Bài 25. Mảng 012
void b25(){
	long long t=0;
	scanf("%lld",&t);
	long long a[t];int bien[3];
	for(int i=0;i<t;i++){
		scanf("%lld",&a[i]);
		bien[a[i]]++;
	}
	for(int i=0;i<=2;i++){
		while(bien[i]>0){
			printf("%d ",i);
			bien[i]--;
		}
	}
	return ;
}
//b27 mang tang dan 2
void b27(){
	long long t=0,d=0;;
	scanf("%lld%lld",&t,&d);
	long long a[t];
	for(int i=0;i<t;i++){
		scanf("%lld",&a[i]);
	}
	int count=0;
	for(int i=1;i<t;i++){
		while(a[i]<=a[i-1]){
			int res=a[i-1]-a[i];
			res/=d;res++;
			count+=res;
			a[i]+=res*d;
		}
	}
	printf("%d",count);
}
//Bài 28. Product sum

void merge(long long a[],int l,int mid,int r){
	int n1=mid-l+1,n2=r-mid;
	long long a1[n1],a2[n2];
	for(int i=0;i<n1;i++){
		a1[i]=a[l+i];
	}
	for(int i=0;i<n2;i++){
		a2[i]=a[mid+i+1];
	}
	int i1=0,i2=0,ia=l;
	while((i1<n1)&&(i2<n2)){
		if(a1[i1]<=a2[i2]){
			a[ia++]=a1[i1++];
		}else{
			a[ia++]=a2[i2++];
		}
	}
	while(i1<n1)a[ia++]=a1[i1++];
	while(i2<n2)a[ia++]=a2[i2++];
}
void mergesoft(long long a[],int l,int r){
	if(l<r){
		int mid=(r+l)/2;
		mergesoft(a,l,mid);
		mergesoft(a,mid+1,r);
		merge(a,l,mid,r);
	}
}
void b28(){
	int n=0;
	scanf("%d",&n);
	long long a[n];
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	mergesoft(a,0,n-1);
	long long sum=0;
	for(int i=n-1;i>=0;i--){
		long long res=(a[i]%1000000007*i%1000000007)%1000000007;
		sum=(res+sum)%1000000007;//phép cộng modulo là: (A + B) % M = ((A % M) + (B % M)) % M
	}
	printf("%lld",sum);
}
void b29(){
	int n=0;
	scanf("%d",&n);
	long long a[n];
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	mergesoft(a,0,n-1);
	long long x1=0,x2=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			x1=x1*10+a[i];
		}else{
			x2=x2*10+a[i];
		}
	}
	printf("%lld",x1+x2);
}
int main(){
	int n=0,k=0;
	scanf("%d%d",&n,&k);
	long long a[n];
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	mergesoft(a,0,n-1);
	long long x1=0,x2=0;
	k=fmin(k,n-k);
	for(int i=0;i<n;i++){
		if(i<k){
				x1+=a[i];
			}else{
				x2+=a[i];
			}
	}		
	printf("%lld",(long long)fabs(x1-x2));//fabs tra ve double
	return 0;
}



