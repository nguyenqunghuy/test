#include<stdio.h>
#include<math.h>

//b12
int snt(int a){
	if(a<2){
		return 0;
	}
	for(int i=2;i*i<=a;i++){
		if(a%i==0){
			return 0;
		}
	}
	return 1;
}
/*
int main(){
	int bien[10000]={0};
	int tbien=0;
	int res=0;
	while(scanf("%d",&res)!=-1){
		bien[tbien++]=res;
	}
	for(int i=0;i<tbien;i++){
		if(snt(bien[i])){
			int count=1;
			for(int j=i+1;j<tbien;j++){
				if(bien[i]==bien[j]){
					count++;
					bien[j]=0;
				}
			}
			printf("%d %d\n",bien[i],count);
		}
	}
	
	return 0;
}
*/
//  Bài 14. Liệt kê và đếm
int checkdown(long long a){// check so co chu so ko giam
	int restrc=a%10;//     1     2     3     4
	a/=10;			//              res sau res trc    
	while(a!=0){
		int ressau=a%10;
		if(restrc<ressau){
			return 0;
		}
		restrc=ressau;
		a/=10;
	}
	return 1;	
}

/* bai nay chua hcoj ddend dcu mat 1h cua bo
long long a[100000];
int main(){
	long long bien[100000]={0};
	int tbien=0;
	long long res=0;
	while(scanf("%lld",&res)!=-1){
		bien[tbien++]=res;
	}
	for(int i=0;i<tbien;i++){
		scanf("%lld",&bien[i]);
	}
	int ibienao=0;
	for(int i=0;i<ibienao;i++){
		if(checkdown(bien[i])==1){
			a[ibienao++]=bien[i];
		}
	}
	quicksoft(a,0,ibienao-1);
	
	return 0;
}
*/
//quick soft
int quick(long long a[],int l,int r){
	int ichay=l-1;
	for(int i=l;i<r;i++){
		if(a[i]<=a[r]){
			int res=a[++ichay];a[ichay]=a[i];a[i]=res;// hoan vi a[i] vs a[ichay]
		}
	}
	int res=a[++ichay];a[ichay]=a[r];a[r]=res;// hoan vi a[r] ra vi tri gua biger and smaller a[ichay]	
	return ichay;
}
void quicksoft(long long a[],int l,int r){
	if(l<r){
		int mid=quick(a,l,r);
		quicksoft(a,l,mid-1);
		quicksoft(a,mid+1,r);
	}
}
//merger soft
int meger(long long a[],int l,int m,int r){
	int t1=m-l+1,t2=r-m;
	long long bienl[t1];// chia thanh 2 bien l va r
	long long bienr[t2];
	for(int i=0;i<t1;i++){//gan gia tri cho moi bien
		bienl[i]=a[l+i];
	}
	for(int i=0;i<t2;i++){
		bienr[i]=a[m+1+i];
	}     
	int i1=0,i2=0;
	int ia=l;
	while((i1<t1)&&(i2<t2)){//sap sep cac bien lon va nho
		if(bienl[i1]<=bienr[i2]){
			a[ia++]=bienl[i1++];
		}else{
			a[ia++]=bienr[i2++];
		}
	}
	while(i1<t1){// sap xep not cac bien con thua
		a[ia++]=bienl[i1++];
	}
	while(i2<t2){
		a[ia++]=bienr[i2++];
	}
}
void megersoft(long long  a[],int l,int r){
	if(l<r){
		int mid=(r+l)/2;
		megersoft(a,l,mid);
		megersoft(a,mid+1,r);
		meger(a,l,mid,r);
	}
}

//Bài 15. BRT SPOJ
void b15(){
	long long t=0;
	scanf("%lld",&t);
	long long bien[t];
	for(int i=0;i<t;i++){
		scanf("%lld",&bien[i]);
	}
	megersoft(bien,0,t-1);
	long long kc=bien[1]-bien[0];
	long long count=1;
	for(long long i=1;i<t-1;i++){
		if(fabs(bien[i+1]-bien[i])<kc){
			kc=fabs(bien[i+1]-bien[i]);
			count=1;
		}else if(fabs(bien[i+1]-bien[i])==kc){
			count++;
		}
	}
	printf("%lld %lld",kc,count);
}
//b16 pitago
int find(long long a[],int t,long long x){//tim so trong ham da dc sx
	int l=0,r=t;
	while(l<=r){
		int mid=(r+l)/2;
		if(a[mid]==x)return 1;
		if(a[mid]<x){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return 0;
}
void b16(){
		long long t=0;
	scanf("%lld",&t);
	long long bien[t];
	for(int i=0;i<t;i++){
		long long res=0; 
		scanf("%lld",&res);
		bien[i]=res*res;
	}
	megersoft(bien,0,t-1);
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			long long res=bien[i]+bien[j];
			if(find(bien,t,res)){
				printf("YES");
				return;
			}
		}
	}
	printf("NO");
	return;
}
//Bài 17. Truy vấn tổng trên đoạn
void b17(){
	long long t=0,q=0;
	scanf("%lld%lld",&t,&q);
	long long a[t];
	long long congdon[t];//tao mang cong don
	congdon[0]=0;
	for(long long i=0;i<t;i++){
		scanf("%lld",&a[i]);
		congdon[i+1]=a[i]+congdon[i];
	}
	long long bien[q];
	for(int i=0;i<q;i++){
		int l=0,r=0;
		scanf("%d%d",&l,&r);
		bien[i]=congdon[r]-congdon[l-1];
	}
	for(int i=0;i<q;i++){
		printf("%lld\n",bien[i]);
	}
	return;
}
//
void b18(){
	long long t=0;
	scanf("%lld",&t);
	long long a[t];
	long long max=0;
	for(long long i=0;i<t;i++){
		scanf("%lld",&a[i]);
		max=fmax(max,a[i]);
	}
	long long bien[max+1];
	for(long long i=0;i<max+1;i++){
		bien[i]=0;
	}
	for(long long i=0;i<t;i++){
		bien[a[i]]++;
	}
	long long count=0;
	for(long long i=0;i<max+1;i++){
		if(bien[i]>=2){
			count+=(bien[i]*(bien[i]-1))/2;
		}
	}
	printf("%lld",count);
}

int main(){
	int t=0;
	scanf("%d",&t);
	int a[t+1];
	for(int i=0;i<t;i++){
		scanf("%d",&a[i]);
	}
	a[t]=a[t-1];
	int count=1,countmax=0,sum=0,summax=0,pos=0;
	for(int i=0;i<t;i++){
		if(a[i]!=a[i+1]){
			count++;
			sum+=a[i+1];
		}else{
			sum=a[i];
			if(count>countmax){
				countmax=count;
				pos=i-count+1;
				summax=sum;
			}else if(count==countmax){
				if(summax<sum){
					pos=i-count+1;
					summax=sum;
				}
			}
			count=1;sum=0;
		}
	}
	printf("%d\n",countmax);
	for(int i=0;i<countmax;i++){
		printf("%d ",a[pos+i]);
	}

	return 0;
}















