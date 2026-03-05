#include<stdio.h>
#include<math.h>

int checksnt(int n){
	if(n<2)return 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return 0;
	}
	return 1;
}
int checktn(int n){//check thuan nghich
	int res2=n;
	int res=0;
	while(n!=0){
		res=res*10+n%10;
		n/=10;
	}
	if(res2==res){
		return 1;
	}else{
		return 0;
	}
}
int checkcp(int n){//check chinh phuong
	int res=sqrt(n);
	if(res*res==n){
		return 1;
	}else{
		return 0;
	}
}
int checksum(int n){
	int sum=0;
	while(n!=0){
		sum+=n%10;
		n/=10;
	}
	return checksnt(sum);
}
void b16(int a[],int t){
	int snt=0,cp=0,tn=0,sum=0;
	for(int i=0;i<t;i++){
		if(checksnt(a[i]))snt++;
		if(checktn(a[i]))tn++;
		if(checkcp(a[i]))cp++;
		if(checksum(a[i]))sum++;
	}
	printf("%d\n%d\n%d\n%d\n",snt,tn,cp,sum);
}
//Bài 18. Liền kề trái dấu
void b18(long long a[],int t){
	for(int i=0;i<t;i++){
		if(i==0){
			if((a[0]*a[1]) < 0){
				printf("%lld ",a[0]);
			}
		}else if(i==t-1){
			if((a[t-1] * a[t-2]) < 0){
				printf("%lld",a[t-1]); 
			}
		}else
			if((a[i]*a[i-1]<0)||(a[i]*a[i+1]<0)){
				printf("%lld ",a[i]);
			}
	}
}


int main(){
	int t=0;
	scanf("%d",&t);
	int a[t];
	for(int i=0;i<t;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<t-1;i++){
		if((a[i]>a[i-1])&&(a[i]>a[i+1])){
			printf("%d ",a[i]);
		}
	}
	return 0;
}