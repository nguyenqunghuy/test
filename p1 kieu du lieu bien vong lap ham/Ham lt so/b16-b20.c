#include<stdio.h>
#include<math.h>


int cdc(long long n){//check đầu cuối
	int dau=0,cuoi=0;
	cuoi=n%10;
	while(n>=10){
		n/=10;
	}
	dau=n;
	if((cuoi==2*dau)||(2*cuoi==dau)){
		return 1;
	}else{
		return 0;
	}
}
long long flip(long long n){//lật số:flip
	long long res=0;
	while(n!=0){
		res=res*10+n%10;
		n/=10;
	}
	return res;
}
void cgtn(long long n){//Bài 41. Số gần thuận nghịch
	if(cdc(n)){
		n/=10;
		n=flip(n);
		n/=10;
		if(flip(n)==n){
			printf("YES");
		}else{
			printf("NO");
		}
	}else{
			printf("NO");
	}
}
//Bài 35. UCLN & BCNN
long long ucln(long long a,long long b){
	for(long long i=b;i>=1;i--){
		if((a%i==0)&&(b%i==0)){
			return i;
		}
	}
	return 0;
}
long long bcnn(long long a,long long b){
	return a/ucln(a,b)*b;//ko cho a*b luôn because sẽ bị quá long long 
}
//Bài 45. Biểu diễn số
void bds(int n){//11x*111y=n
	int res=0;
	for(int i=0;i<=n/11+1;i++){
		res=n-11*i;
		if(res%111==0){
			printf("YES");
			return;
		}
	}
	printf("NO");
}
//Bài 26. Số hoàn hảo:use euclid :nếu p là snt và 2p - 1 cũng là snt thì 
							   //: 2^(p-1) * (2p - 1) sẽ là một số hoàn hảo.
int snt(long long n){
	if(n < 2){
        return 0;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0 ) return 0;
    }
    return 1;
}

void shh(long long n){
	for(int i = 1 ; i <= 31 ;i++ ){
		if(snt(i)){
			long long res1=pow(2,i)-1;
			if(snt(res1)){
				long long res2=pow(2,i-1);
				if(n==(res1*res2)){
					printf("YES");  
					return;
				}	
			}           
		}
	}
	printf("NO");  		
}
//Bài 32. Thừa số nguyên tố thứ K
int tsnt(int n,int k){
	int count=0;
	for(int i=2;i<=n;i++){
		if(n%i==0){
			while(n%i==0){
			//printf("%d \n",i);			
				n/=i;	
				count+=1;
				if(count==k){
					return i;
				}
			}
		}
	}
	return -1;	
}



int main(){
	int n=0,k=0;
	scanf("%d %d",&n,&k);
	printf("%d",tsnt(n,k));
	return 0;
}