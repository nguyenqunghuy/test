#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//use mergesort
void meger(long long a[],long long l,long long mid,long long r){
	long long bien_trai=mid-l+1,bien_phai=r-mid;
	long long bien1[bien_trai],bien2[bien_phai];
	for(long long i=0;i<bien_trai;i++){
		bien1[i]=a[l+i];
	}
	for(long long i=0;i<bien_phai;i++){
		bien2[i]=a[mid+i+1];
	}
	long long i1=0,i2=0,k=l;
	while((i1<bien_trai)&&(i2<bien_phai)){
		if(bien1[i1]<=bien2[i2]){
			a[k++]=bien1[i1++];
		}else{
			a[k++]=bien2[i2++];
		}
	}
	while(i1<bien_trai)a[k++]=bien1[i1++];
	while(i2<bien_phai)a[k++]=bien2[i2++];
}
void megersort(long long a[],long long l,long long r){
	if(l<r){
		long long mid=(l+r)/2;
		megersort(a,l,mid);
		megersort(a,mid+1,r);
		meger(a,l,mid,r);
	}
}

int sum_chu_so(int a){
	int sum=0;
	while(a!=0){
		sum+=a%10;
		a/=10;
	}
	return sum;
}
int comparator(const void *a,const void *b){
	int *x=(int*)a;
	int *y=(int*)b;
	return *x-*y;
}


//Bài 5. Số lần xuất hiện
void b5(){
	int n=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	qsort(a,n,sizeof(int),comparator);
	int count_max=1,kq=a[0],res=1;
	for(int i=0;i<n-1;i++){
		if(a[i]==a[i+1]){
			res++;
		}else{
			if(count_max==res){
				if(kq>a[i]){
					kq=a[i];
				}
			}else if(count_max<res){
				kq=a[i];
				count_max=res;
			}
			res=1;
		}
		
	}if(count_max<res){
			kq=a[n-1];
			count_max=res;
		}
	printf("%d %d",kq,count_max);
	return ;
}





//Selection sort
void selection_sort(long long a[],int n){
	for(long long i=0;i<n-1;i++){
		int min=i;
		for(int j=i;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		//hoanvi
		long long res=a[min];
		a[min]=a[i];
		a[i]=res;
		printf("Buoc %lld: ",i+1);
		for(int k=0;k<n;k++){
			printf("%lld ",*(a+k));
		}
		printf("\n");
	}
}

int main(){
	int n=0;
	scanf("%d",&n);
	long long a[n];
	for(int i=0;i<n;i++){
		scanf("%lld",a+i);
	}
	selection_sort(a,n);
	return 0;
}







