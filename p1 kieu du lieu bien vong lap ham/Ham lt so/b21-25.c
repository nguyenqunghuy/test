#include<stdio.h>
#include<math.h>

//Bài 18. Bình phương nguyên tố
void bpsntc1(int a,int b){//Bình phương nguyên tố
	for(int i=a;i<=b;i++){
		for(int k=2;k<=7;k++){
			if((i%k==0)&&(i%(k*k)==0)){//don't need: snt(k)
				printf("%d ",i);
				break;
			}
		}
	}
}
int check2(int n){
	for(int i=2;i*i<=n;i++){
		int count=0;
		if(n%i==0){
			while(n%i==0){
			count++;
			n/=i;
			if(count>=2)return 1;
			}
		}
	}
	return 0;
}
void bpsntc2(int a,int b){//Bình phương nguyên tố just need i=2*3^n*...: chỉ cần n >=2 
	for(int i=a;i<=b;i++){
		if(check2(i)){
			printf("%d ",i);
		}
	}	
}

//Bài 19. Bình phương nguyên tố 2
int check3(int n){//check n=tích của mũ 2 đổ lên 
	for(int i=2;i*i<=n;i++){
		int count=0;
		if(n%i==0){
			while(n%i==0){
				count++;
				n/=i;
			}
			if(count==1)return 0;
		}
	}
	if(n>1){//neu n la snt
		return 0;
	}else{//N==1 no loai bo het sai =>con moi dung
		return 1;		
	}
}
void bpsnt2(int a,int b){
	for(int i=a;i<=b;i++){
		if(check3(i)){
			printf("%d",i);
			
		}
	}		
}
//Bài 34. Số nguyên dương chia hết cho x, y, z có n chữ số
long long ucln(long long a,long long b){//euclid
	while(b!=0){
		long long res=a%b;
		a=b;
		b=res;
	}
	return a;
}
long long bcnn(long long a ,long long b){
	return (a/ucln(a,b))*b;
}
long long bcnn3(long long a,long long b,long long c){
	long long res=bcnn(a,b);
	return (c/ucln(c,res))*res;
}
int ssh(long long n){
	int count=0;
	while(n!=0){
		count++;
		n/=10;
	}
	return count;
}
long long b34(long long a,long long b,long long c,long long d){
	long long res1=bcnn3(a,b,c);
	long long res2=1;//floor and celi
	while(ssh(res2)!=d){
		res2*=10;
	}
	long long res3=res2*10-1;
	long long res4=res2/res1;
	for(long long i=res4*res1;i<=res3;i+=res1){
		if(i>=res2){
			return i;
		}
//		printf("%lld",i);
	}
	return -1;
}
long long b34c2(long long a,long long b,long long c,long long d){
	long long res1=bcnn3(a,b,c);
	long long res2=(long long)pow(10,d-1);
//	long long kq=(res2/res1+1)*res1; bị sai nếu res2 %res 1==0
	long long kq=(res2+res1-1)/res1*res1;
	if(kq<(long long)pow(10,d)){
		return kq;
	}else{
		return -1;
	}
}
//Bài 7. Cặp số nguyên tố cùng nhau
void pairsnt(int a, int b ){
	for(int i=a;i<=b;i++){
		for(int k=i+1;k<=b;k++){
			if (ucln(i,k)==1){
				printf("(%d,%d)\n",i,k);
			}
		}
	}		
}

int main(){
	long long n=0;
	scanf("%lld",&n);
	printf("%lld",f(n));
	return 0;
}

