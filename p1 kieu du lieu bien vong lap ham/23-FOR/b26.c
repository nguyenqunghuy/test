#include<stdio.h>

 int main (){
 	int a,b,n;
 	scanf("%d %d %d",&a,&b,&n);
 	for (int i=0;i<=(n/a);i++){
 		if((n - a * i)%b==0){
 			printf("YES");
 			return 0;
		}	
	}
	printf("NO");
 	return 0;
 }