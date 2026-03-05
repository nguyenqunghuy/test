#include<stdio.h>
#include<math.h>


int quickup(int a[],int l,int r){//sx tang dan
	int value=a[r];
	int ichay=l-1;
	for(int i=l;i<r;i++){
		if(value>=a[i]){
			ichay++;
			int res=a[ichay];
			a[ichay]=a[i];
			a[i]=res;
		}
	}
	ichay++;
	a[r]=a[ichay];
	a[ichay]=value;
	return ichay;
}
void quicksoftup(int a[],int l,int r){
	if(l<r){
		int mid=quickup(a,l,r);
		quicksoftup(a,l,mid-1);
		quicksoftup(a,mid+1,r);
	}
}
int quickdown(int a[],int l,int r){//sx giam dan
	int value=a[r];
	int ichay=l-1;
	for(int i=l;i<r;i++){
		if(value<=a[i]){
			ichay++;
			int res=a[ichay];
			a[ichay]=a[i];
			a[i]=res;
		}
	}
	ichay++;
	a[r]=a[ichay];
	a[ichay]=value;
	return ichay;
}
void quicksoftdown(int a[],int l,int r){
	if(l<r){
		int mid=quickdown(a,l,r);
		quicksoftdown(a,l,mid-1);
		quicksoftdown(a,mid+1,r);
	}
}


//Bài 7. Sắp xếp chẵn lẻ

void sxcl(int a[],int t){
	int ichay=-1;
	for(int i=0;i<=t;i++){
		if(a[i]%2!=0){
			ichay++;
			int res=a[ichay];
			a[ichay]=a[i];
			a[i]=res;
		}
	}
	if(ichay==-1){
		quicksoftup(a,0,t);
	}else{
		quicksoftdown(a,0,ichay);	
		quicksoftup(a,ichay+1,t);
			
	}
}
//Bài 8. Trộn 2 dãy đã sắp xếp
void b8(int a[],int b[],int t1,int t2){
	int tsum=t1+t2;
	int sum[tsum];
	int isum=0;
	int ia=0,ib=0;
	while((ia<t1)&&(ib<t2)){
		if(a[ia]>=b[ib]){
			sum[isum++]=b[ib++];
		}else{
			sum[isum++]=a[ia++];
		}
	}
	while(ia<t1){
		sum[isum++]=a[ia++];
	}
	while(ib<t2){
		sum[isum++]=b[ib++];
	}
	for(int i=0;i<tsum;i++){
		printf("%d ",sum[i]);
	}
}
//Bài 9. Đếm tần suất
long long findmax(long long a[],long long t){
	int max=a[0];
	for(long long i=1;i<t;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	return max;
}
void tx(long long a[],long long t){
	long long max=findmax(a,t);
	long long ham[max+1]={0};
	for(int i=0;i<t;i++){
		ham[a[i]]++;
		if(ham[a[i]]>=2){
			a[i]=-1;//huy luon cac bien gionh nhau
		}
	}
	for(int i=0;i<max+1;i++){
		if(ham[i]>0){
			printf("%d %lld\n",i,ham[i]);
		}
	}
	printf("\n");
	for(int i=0;i<t;i++){
		if(a[i]>=0){
			printf("%lld %lld\n",a[i],ham[a[i]]);
		}
	}
}
//Bài 10. Tìm hợp, giao của 2 mảng
void giaoandhop(long long a[],long long b[],long long n,long long m){
	long long maxa=findmax(a,n);
	long long maxb=findmax(b,m);
	long long c[maxa+1]={0};//tao cac ham c and d
	long long d[maxb+1]={0};
	for(int i=0;i<n;i++){//gan and soft tranh cac bien lap
		c[a[i]]=1;
	}
	for(int i=0;i<m;i++){
		d[b[i]]=1;
	}
	//tao bien tong cua c va d
	if(maxa>=maxb){
		for(long long i=0;i<maxb+1;i++){
			if(d[i]==1){
				c[i]++;
			}
		}
		//find giao
		for(long long i=0;i<maxa+1;i++){
			if(c[i]==2){
				printf("%lld ",i);
			}
		}
		printf("\n");
		//find hop
		for(long long i=0;i<maxa+1;i++){
			if(c[i]>=1){
				printf("%lld ",i);
			}
		}
	}else{
		for(long long i=0;i<maxa+1;i++){
			if(c[i]==1){
				d[i]++;
			}
		}
		//find giao
		for(long long i=0;i<maxb+1;i++){
			if(d[i]==2){
				printf("%lld ",i);
			}
		}
		printf("\n");
		//find hop
		for(long long i=0;i<maxb+1;i++){
			if(d[i]>=1){
				printf("%lld ",i);
			}
		}
	}
}
int giao[10000001];
int hop[10000001];
int main(){
	int n=0;
	int m=0;
	scanf("%d",&n);
	scanf("%d",&m);
	int a[n];
	int b[m];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	int in=0;//ichay cua n
	int im=0;
	int igiao=0;
	int ihop=0;
	while(in<n&&im<m){
		if(a[in]==b[im]){
			giao[igiao++]=a[in++];
			hop[ihop++]=b[im++];
		}else if(a[in]<b[im]){
			hop[ihop++]=a[in++];
		}else{
			hop[ihop++]=b[im++];
		}
	}
	while(in<n){
		hop[ihop++]=a[in++];	
	}
	while(im<m){
		hop[ihop++]=b[im++];
	}
	for(int i=0;i<ihop;i++){//print hop
		printf("%d ",hop[i]);
	}
	printf("\n");
	for(int i=0;i<igiao;i++){//print giao
		printf("%d ",giao[i]);
	}
	return 0;
}
