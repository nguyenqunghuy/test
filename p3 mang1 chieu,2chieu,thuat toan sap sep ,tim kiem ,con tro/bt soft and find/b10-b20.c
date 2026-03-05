#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Bài 11. Trộn 2 dãy
void b11(){
		int n1=0,n2=0;
	scanf("%d%d",&n1,&n2);
	int a1[n1],a2[n2];
	for(int i=0;i<n1;i++){
		scanf("%d",&a1[i]);
	}
	for(int i=0;i<n2;i++){
		scanf("%d",&a2[i]);
	}
	int i1=0,i2=0;
	while((i1<n1)&&((i2<n2))){
		if(a1[i1]<=a2[i2]){
			printf("b%d ",i1+1);i1++;
		}else{
			printf("c%d ",i2+1);i2++;
		}
	}
	while((i1<n1)){printf("b%d ",i1+1);i1++;}
	while((i2<n2)){printf("c%d ",i2+1);i2++;}
}
//Bài 12. Khiêu vũ
int compa(const void *a,const void *b){//comparator
	int *x=(int*)a;
	int *y=(int*)b;
	if(*x<=*y){
		return -1;
	}else{
		return 1;
	}
}
void b12(){
	int n1=0,n2=0;
	scanf("%d%d",&n1,&n2);
	int a1[n1],a2[n2];
	for(int i=0;i<n1;i++){
		scanf("%d",&a1[i]);
	}
	for(int i=0;i<n2;i++){
		scanf("%d",&a2[i]);
	}
	int count=0,i1=0,i2=0;
	while((i1<n1)&&(i2<n2)){
		if(a1[i1]>a2[i2]){
			count++;i1++;i2++;
		}else{
			i1++;
		}
	}
	printf("%d",count);
}
// b13 xep chong
int compa2(const void *a,const void *b){//comparator
	int *x=(int*)a;
	int *y=(int*)b;
	return *y-*x;
}
void b13(){
	int n=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),compa2);
	int do_cung=a[0],res=1,count=1;
	while((do_cung>0)&&(res<n)){
		if(do_cung==a[res]){
			do_cung--;
			res++;
		}else{
			do_cung=a[res];
			res++;
		}
		count++;
	}
	printf("%d",count);
}
//Bài 15. The 2014 ACM-ICPC Asia Jakarta Regional Contest
void b15 (){
	int n=0,k=0;
	scanf("%d%d",&n,&k);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),compa);
	int count=1;
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]>k)count++;
	}printf("%d",count);
}
//b16 chịu thua

//Bài 17. Cặp số có tổng bằng K
int find(int a[],int n,int l,int k){
	int mid1=0;
	int l1=l,r1=n-1;
	int frist=-1;
	while(l1<=r1){//find vin tri so k dau tien in mang 
		mid1=(r1+l1)/2;
		if(a[mid1]==k){
			frist=mid1;
			r1=mid1-1;
		}else if(a[mid1]<k){
			l1=mid1+1;
		}else{
			r1=mid1-1;
		}
	}
	int mid2=0;
	int l2=l,r2=n-1;
	int end=-1;
	while(l2<=r2){//find vin tri so k cuoi in mang 
		mid2=(r2+l2)/2;
		if(a[mid2]==k){
			end=mid2;
			l2=mid2+1;
		}else if(a[mid2]<k){
			l2=mid2+1;
		}else{
			r2=mid2-1;
		}
	}
	if(end==-1){
		return 0;
	}else{
		return end-frist+1;
	}
}
void b17(){
	int n=0,k=0;
	scanf("%d%d",&n,&k);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),compa);
	long long count=0;
	for(int i=0;i<n-1;i++){
		count+=find(a,n,i+1,k-a[i]);
	}
	printf("%lld",count);
}
//Bài 18. Cặp số có tổng nhỏ hơn K
int find2(int a[],int n,int l,int k){
	int frist=l;
	int mid2=0;
	int l2=l,r2=n-1;
	int end=-1;
	while(l2<=r2){//find vin tri so < k cuoi in mang 
		mid2=(r2+l2)/2;
		if(a[mid2]<k){
			end=mid2;
			l2=mid2+1;
		}else{
			r2=mid2-1;
		}
	}
	if(end==-1){
		return 0;
	}else{
		return end-frist+1;
	}
}
//Bài 19. Cặp số có tổng lớn hơn k
int find3(int a[],int n,int l,int k){
	int mid2=0;
	int l2=l,r2=n-1;
	int frist=-1,end=n-1;
	while(l2<=r2){//find vin tri dau tien > k dau tien in mang 
		mid2=(r2+l2)/2;
		if(a[mid2]>k){
			frist=mid2;
			r2=mid2-1;
		}else{
			l2=mid2+1;
		}
	}
	if(frist==-1){
		return 0;
	}else{
		return end-frist+1;
	}
}
void b17_b19main(){
	int n=0,k=0;
	scanf("%d%d",&n,&k);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),compa);
	long long count=0;
	for(int i=0;i<n-1;i++){
		count+=find3(a,n,i+1,k-a[i]);
	}
	printf("%lld",count);
	return;
}
long long bien[1000001];
int main(){
	int n=0;
	scanf("%d",&n);
	int a[n];
	int min=1e9,max=-1e9;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		max=fmax(max,a[i]);
		min=fmin(min,a[i]);
		bien[a[i]]=1;
	}
	int count=0;
	for(int i=min;i<=max;i++){
		if(bien[i]==0){
			count++;
		}
	}
	printf("%d",count);
	return 0; 
}





