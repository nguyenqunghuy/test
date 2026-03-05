#include<stdio.h>
//linner search: thuat toan tim kiem tuyen tinh
//binary search:tim kiem nhi phan(dk tim dc tren ham da sap xep)
int binary(int a[],int x,int t){//find vintri x tren mang DA DC SOFT
								//Olog(log(n)) --> log(n) 
	int l=0,r=t-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x)return mid;//finish find
		if(a[mid]>x){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return 0;//dont find
}
// bien the binary
int find(int a[],int t,int x){//find vintri dau tien co  trong mang
	int l=0;
	int r=t-1;
	int res=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x){	
			res=mid;
			r=mid-1;
		}else if(x<a[mid]){//x ben trai
			r=mid-1;
		}else{//if a[mid]<x // x ben phai
			l=mid+1;
		}
	}
	return res;
}
int findend(int a[],int t,int x){//find vintri cuoi co  trong mang
	int l=0;
	int r=t-1;
	int res=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x){	
			res=mid;
			l=mid+1;
		}else if(x<a[mid]){//x ben trai
			r=mid-1;
		}else{//if a[mid]<x // x ben phai
			l=mid+1;
		}
	}
	return res;
}
int find3(int a[],int t,int x){//tim so frist,>=x
	int l=0,r=t-1;
	int res=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(x<=a[mid]){
			res=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return res;
}
int find4(int a[],int t,int x){//find end,<=x
	int l=0,r=t-1;
	int res=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]<=x){
			res=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return res;
}
int main(){
	int a[]={0,1,2,3,4,5,6,9,88,943};
	int t=10;
	printf("%d",find4(a,t,102));
	return 0;
}