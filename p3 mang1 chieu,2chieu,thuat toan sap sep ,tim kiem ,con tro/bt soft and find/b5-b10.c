#include<stdio.h>
#include<stdlib.h>


//b6 Selection sort
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
//Bài 7. Sắp xếp chèn(0n^2)
void insertion_sort(int a[],int n){
	for(int i=1;i<n;i++){
		int value=a[i];
		int pos=i-1;
		while((pos>=0)&&(value<a[pos])){
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1]=value;
		printf("Buoc %d: ",i);
		for(int k=0;k<n;k++){
			printf("%d ",*(a+k));
		}
		printf("\n");
	}
}
// Bài 8. Sắp xếp nổi bọt
void bubble_sort(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				int res=a[j];a[j]=a[j+1];a[j+1]=res;
			}
		}
		printf("Buoc %d: ",i+1);
		for(int k=0;k<n;k++){
			printf("%d ",*(a+k));
		}
		printf("\n");
	}
}
//Bài 9. Tìm kiếm nhị phân
int binary_rearch(int a[],int n,int x){
	int l=0,r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x){
			return 1;
		}else if(a[mid]>x){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return 0;
}
//Bài 10. Tìm kiếm nhị phân biến đổi
int find1(int a[],int n,int x){// vị trí xuất hiện đầu tiên 
	int l=0,r=n-1,res=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x){
			res=mid;
			r=mid-1;
		}else if(a[mid]<x){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d\n",res);
	return res;
}
int find2(int a[],int n,int x){//vị trí xuất hiện cuối cùng
	int l=0,r=n-1,res=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x){
			res=mid;
			l=mid+1;
		}else if(a[mid]<x){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d\n",res);
	return res;
}
void find3(int a[],int n,int x){//vị trí xuất hiện đầu tiên của phần tử >= X
	int l=0,r=n-1,res=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]>=x){
			res=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	printf("%d\n",res);
	return res;
}
int find4(int a[],int n,int x){//vị trí xuất hiện đầu tiên của phần tử > X
	int l=0,r=n-1,res=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x){
			l=mid+1;
		}else if(a[mid]>x){
			res=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	printf("%d\n",res);
	return res;
}

int main(){
	int n=0,x=0;
	scanf("%d%d",&n,&x);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int tmp1=find1(a,n,x);
	int tmp2=find2(a,n,x);
	find3(a,n,x);
	find4(a,n,x);
	if(tmp1==-1){
		printf("0");
	}else{
		printf("%d",tmp2-tmp1+1);
		
	}
	
	return 0;
}