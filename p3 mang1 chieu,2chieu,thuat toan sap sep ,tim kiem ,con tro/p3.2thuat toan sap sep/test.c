#include<stdio.h>
#include<math.h>


long long ham[1000000];
void snt(int n){//eartothenes
	if(n<=2)return 0;
	for(int i=2;i*i<=n;i++){
		for(int j=2;i*j<=n;j++){
			ham[i*j]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(ham[i]==0){
			printf("%d\n",i);
		}
	}
}

int main(){
	int a=100;
	snt(a);
	
	
	return 0;
}