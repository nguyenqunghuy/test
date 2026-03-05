#include<stdio.h>

void chen(int a[],int t,int x,int k){// them 1 pt vao a[]:t++
	for(int i=t;i>=k-1;i--){
		a[i+1]=a[i];
	}
	a[k-1]=x;
	for(int i=0;i<t;i++){
		printf("%d ",a[i]);
	}
}
int find(int a[],int t,int x){//find address
	int count=0;
	for(int i=0;i<t;i++){
		if(a[i]==x){
			return count;
		}
		count++;
	}
	return -1;//if not found
}
void erase(int a[],int t,int x){
	if(find(a,t,x)==-1){
		printf("NOT FOUND");
		return;
	}
	int address=find(a,t,x);
	for(int i=address;i<t;i++){
		a[i]=a[i+1];
	}
	for(int i=0;i<t-1;i++){
		printf("%d ",a[i]);
	}
}
//Bài 23. Mảng cộng dồn
void mangdon(int a[],int t){
	int f[t];
	f[0]=a[0];
	for(int i=1;i<t;i++){
		f[i]=f[i-1]+a[i];
	}
	for(int i=0;i<t;i++){
		printf("%d ",f[i]);
	}
}
// Bài 24. Cửa sổ cỡ K
void b24(int a[],int t ,int k){
	for(int i=0;i<t;i++){
		if(( i + k ) <= t){
			int sum=0;
			for(int j=i;j<i+k;j++){
				sum+=a[j];
			}
			printf("%d ",sum);
		}
		
	}
}

int main(){
	int count=0;int a[10000];
	int res;
	while(scanf("%d",&res)!=-1){//code new:scanf se doc ra cac bit 
		a[count]=res;
		count+=1;
	}
	int chan=0,le=0;
	for(int i=0;i<count;i++){
		if(a[i]%2==0){
			chan++;
		}else{
			le++;
		}
	}
	if(chan>le){
		printf("CHAN");
	}else if(chan<le){
		printf("LE");
	}else{
		printf("CHANLE");
	}
	return 0;
}


