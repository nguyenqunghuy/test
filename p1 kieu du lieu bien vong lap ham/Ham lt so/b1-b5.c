#include<stdio.h>
#include<math.h>
int snt(long long n){// SO NGUYEN TO
	if(n<2){
//		printf("NO\n");
		return 0 ;
	}
//	float k=n; CHUYEN BIEN SANG FLOAT 
	for(long long i=2;i*i<=n;i++){//"i*i<=n" thay vi "i<=sqrt(k)" se nhanh hon va ko bo lo bien
		if(n%i==0){
//			printf("NO\n");
			return 0 ;	
		}
	}
//	printf("YES\n");
	return 1 ;	
}
void gb(int n){// Bài 5. Goldbach
	for(int i=2;i<=n/2;i++){//mistake : wrong about i nham sang dieu kien cua n,i=2 vì snt >2
		if((snt(i)==1)&&(snt(n-i)==1)){ 
			printf("%d %d\n",i,n-i);	
			return;// sai ở đây vì hiểu nhầm ý đề bài :in tất cả những cặp thỏa mãn với từng tescase
		}
	}
}
int sphenic(long long n ) {//Bài 15. Số Sphenic: 3 snt "else"*=n
	int count1=0;
	for(int i=2;i*i<=n;i++){
		if(snt(i)&&(n%i==0)){
			int count2=0;
			while(n%i==0){
				count2+=1;
				n/=i;
			}
			if(count2>=2){
				return 0;
			}else{
				count1+=1;
			}
		}
	} 
	if(n>1)count1+=1;//cộng thêm thừa số lớn hơn căn n
	
	if(count1==3){
		return 1;	
	}else{
		return 0;
	}
}
void ptsnt(long long n){//Bài 12. Phân tích thừa số nguyên tố
	for(int i=2;i*i<=n;i++){
		if((n % i )== 0){
			int count=0;
			while(n % i == 0){
				count+=1;
				n/=i;
			}
			printf("%d^%d",i,count);
			if(n>1){
				printf(" * ");
			}
		}
	}
	if(n>1){
		printf("%lld^1",n);
	}
}
int usntln(long long n){// Bài 17. Ước số nguyên tố lớn nhất: làm giống bài trên  //note: ước của số nguyên tố là thừa số nguyên tố :2,3,5
	int res=0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			res=i;
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n>1){
		return n;
	}else{
		return res;
	}
}
int main(){
	long long t=0,n=0;
	scanf("%lld \n",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		printf("%d \n",usntln(n));	
	}
	return 0;
}
