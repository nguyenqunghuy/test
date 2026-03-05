#include<stdio.h>
#include<math.h>

int main(){
	int n,k;
	scanf("%d",&n);
	k=n%10;
//1
	if(n%2==0){
		printf("YES\n");
		
	}else{
		printf("NO\n");
	}
//2
	if(n%3==0 && n%5==0){
		printf("YES\n");
		
	}else{
		printf("NO\n");
	}
//3
	if(n%3==0&&n%7!=0){
		printf("YES\n");
		
	}else{
		printf("NO\n");
	}
//4
	if((n%3==0)||(n%7==0)){
		printf("YES\n");
		
	}else{
		printf("NO\n");
	}
//5	
	if(30<n&&n<50){
		printf("YES\n");
		
	}else{
		printf("NO\n");
	}
//6	
	if(n>=30&&((n%2==0)||(n%3==0)||(n%5==0))){
		printf("YES\n");
		
	}else{
		printf("NO\n");
	}
//7
	if((((10<=n)&&(n<=99)))&&((k==2)||(k==3)||(k==5)||(k==7))){
		printf("YES\n");
		
	}else{
		printf("NO\n");
	}
//8
	if((n<=100)&&(n%23==0)){
		printf("YES\n");
		
	}else{
		printf("NO\n");
	}
//9
	if((10<=n)&&(n<=20)){
		printf("NO\n");
		
	}else{
		printf("YES\n");
	}
//10	
	if(k%3==0){
		printf("YES\n");
	}else {
		printf("NO\n");
	}
	
	return 0;
}