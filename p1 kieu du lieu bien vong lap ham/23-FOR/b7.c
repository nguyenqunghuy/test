#include<stdio.h>
#include<math.h>

int main(){
	int n;
	scanf("%d",&n);
	int count=0;
	for(int i=1;i<=n;i++){
		if(n%i==0){
			count+=1;	
		}
	}
	printf("%d \n",count);
	for(int i=1;i<=n;i++){
		if(n%i==0){
			printf("%d ",i);	
		}
	}
	return 0;
}