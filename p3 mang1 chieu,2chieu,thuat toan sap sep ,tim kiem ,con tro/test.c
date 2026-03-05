#include<stdio.h>
#include<math.h>
	
	
	
void swap(int *a,int *b){
	int res=*a;
	*a=*b;
	*b=res;
	
}
int main(){
	int a[]={1,2,3,4,5,6,7};
	for(int i=0;i<7;i++){
		scanf("%d",(a+i));	
	}
	printf("\n");
	for(int i=0;i<7;i++){
		printf("%d ",*(a+i));	
	}
		
	return 0;      
}