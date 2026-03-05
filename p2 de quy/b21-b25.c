#include<stdio.h>


//Bài 21. Kiểm tra mảng đối xứng
void checkdx(int a[],int t){//check doi xung
	for(int i=0;i<t;i++){
		if( a[i] != a[t-i-1]){
			printf("NO");
			return;
		}
	}
	printf("YES");
}
int a[100000];
//Bài 22. In mảng
void ltr(int a[],int t){
	if(t==0){
		return ; 
	}
	ltr(a,t-1);
	printf("%d ",a[t-1]);
}
void rtl(int a[],int t){
	if(t==0){
		return ; 
	}
	printf("%d ",a[t-1]);
	rtl(a,t-1);
}
//Bài 23. Kiểm tra mảng toàn chẵn
int checkc(int a[],int t){
	if(t==0){
		return 1;
	}
	if(a[t-1]%2!=0)return 0;
	return checkc(a,t-1);
}
//Bài 24. Kiểm tra mảng tăng dần
int checkup(int a[],int t,int up){
	if(t==(up+1))return 1;
	if(a[up]>=a[up+1])return 0;
	return checkup(a,t,up+1);
}
/// Bài 25. Binary search
int find(int a[],int t,int f){
	if((f<a[t-1])||(t==0))return 0;
	if(a[t-1]==f)return 1;
	return find(a,t-1,f);
}
int main(){
	int t=0,f=0;;
	scanf("%d",&t);
	int a[t];
	for(int i=0;i<t;i++){
		scanf("%d",&a[i]);
	}	
	checkdx(a,t);
	return 0;
}

