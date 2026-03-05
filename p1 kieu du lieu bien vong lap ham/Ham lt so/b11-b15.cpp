#include<stdio.h>
#include<math.h>

int snt(int n){
	if(n<2){
		return 0;
	}
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      return 0;
      }
    }
    return 1;
}
int ccsntt(int n){//check chu so snt
  int sum=0;
  while(n!=0){
    int res=0;
    res=n%10;
    sum+=res;
    if(snt(res)==0){
    	return 0;
    }
    n/=10;
    }
  if(snt(sum)){
    return 1;
  }else{
    return 0;
    }
}
int psnt(int n,int m){//Bài 6. Số thuần nguyên tố
  int count=0;
  while(n<=m){
  	if(ccsntt(n)&&snt(n)){
    	count+=1;  
    }
	n++;
  }
	return count;
}
int pttstn(int n){//phân tích thừa số nguyên tố có 3 uoc là snt
	int count=0;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			count+=1;
			while(n%i==0){
				n/=i;
			}	
		}	
		if(count>=3){
			return 1;
		}
	}
	if(n>1){
		count+=1;
	}
	if(count>=3){
		return 1;
	}else{
		return 0;
	}
}
int lat(int n){//lat so :check so thuan nghich
	int res=0;
	while(n!=0){
		res=res*10+n%10;
		n/=10;
	}
	return res;
}
void checkstn3u(int n,int m){
	int res=0;
	for(int i=n;i<=m;i++){
		if((lat(i)==i)&&pttstn(i)){
			res+=1;
			printf("%d ",i);
		}
	}
	if(res==0){
		printf("-1");
	}
}
int lp1(long long n){//so loc phat
	while(n!=0){
		int res=n%10;
		if((res!=0)&&(res!=6)&&(res!=8)){
			return 0;
		}	
		n/=10;
	}
	return 1;
}
int lp2(int n){
	int count =0;
	int sum=0;
	while(n!=0){
		if(n%10==6){
			count+=1;
		}
		sum+=n%10;
		n/=10;
	}
	if((sum%10==8)&&(count>=1)){
		return 1;
	}else{
		return 0;
	}
	
}
void sntlp(int n,int m){//Bài 29. Số thuận nghịch, lộc phát
	for(int i=n;i<=m;i++){
		if((lat(i)==i)&&(lp2(i))){
			printf("%d ",i);
		}
	}

}
int check1(int n){//check chữ số cuối cùng lớn nhất
	int res=n%10;
	while(n!=0){
		if((res<(n%10))){
			return 0;
		}
		n/=10;
	}
	return 1;
}
void csccln(int n ){//Bài 30. Chữ số cuối cùng lớn nhất and snt
	int count=0;
	for(int i=2;i<=n;i++){
		if((check1(i))&&(snt(i))){
			count+=1;
			printf("%d ",i);
		}
	}
	printf("\n %d ",count);
}
int main(){
	int n=0;
	scanf("%d",&n);
	csccln(n);
	
	return 0;
}