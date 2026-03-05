#include<stdio.h>

int main(){
	int n=0;
	scanf("%d",&n);
	int ao=0;
	for(int i=0;i<n;i++){
		scanf("%d",&ao);
		if(ao%2==0){
			printf("EVEN\n");
		}else{
			printf("ODD\n");
		}
	}
	return 0;
}