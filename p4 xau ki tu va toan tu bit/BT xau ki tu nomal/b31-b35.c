#include<stdio.h>
#include<string.h>

//Bài 32. Số đẹp 1
int check(int n){
	if(n<2)return 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

void b32(){
	char c[10000];
	scanf("%s",c);
	long long sum=0;
	for(int i=0;i<(int)strlen(c);i++){
		sum+=c[i]-'0';
		if(!(check(c[i]-'0'))){
			printf("NO");return;
		}
	}
	if(check(sum)){
		printf("YES");
	}else{
		printf("NO");
	}
}
//Bài 33. Số đẹp 2
int tn(char c[]){
	int l=strlen(c)-1,r=0;
	while(r<=l){
		if(c[r]!=c[l]){
			return 0;
		}
		r++;l--;
	}
	return 1;
}
//Bài 34. Số đẹp 3
void b34(){
	char c[10000];
	scanf("%s",c);
	int flag1=1,flag2=1;
	for(int i=0;i<(int)strlen(c)-1;i++){
		if(c[i]>c[i+1]){
			flag1=0;break;
		}
	}
	for(int i=0;i<(int)strlen(c)-1;i++){
		if(c[i]<c[i+1]){
			flag2=0;break;
		}
	}
	if(flag1||flag2){
		printf("YES");
	}else{
		printf("NO");
	}
}
int main(){
	char c[10000];
	scanf("%s",c);
	int count=0;
	for(int i=0;i<(int)strlen(c);i++){
		count+=c[i]-'0';
	}
	if(((c[(int)strlen(c)-1]-'0')%2==0)&&(count%3==0)){
		printf("YES");
	}else{
		printf("NO");
	}
	return 0;
}