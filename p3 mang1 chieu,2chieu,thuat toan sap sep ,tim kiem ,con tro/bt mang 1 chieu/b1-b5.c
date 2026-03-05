#include<stdio.h>
//Bài 1. Chẵn lẻ
void checkcl(int a[],int t){
	int countc=0,countl=0,sumc=0,suml=0;
	for(int i=0;i<t;i++){
		if(a[i]%2==0){
			countc+=1;
			sumc+=a[i];
		}else{
			countl+=1;
			suml+=a[i];
		}
	}
	printf("%d\n%d\n%d\n%d\n",countc,countl,sumc,suml);
}
//Bài 2. Trung bình cộng nguyên tố
int snt(int n){
	if(n<2)return 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
double tbsnt(int a[],int t){
	int count=0;
	long long sum=0;
	for(int i=0;i<t;i++){
		if(snt(a[i])){
			count+=1;
			sum+=a[i];
		}
	}
	return (1.000*sum)/count;
}
//Bài 3. Số nhỏ nhất
int countlap(int a[],int t,int res){//chek so lan lap lai cua res
	int count=0;
	for(int i=0;i<t;i++){
		if(a[i]==res){
			count+=1;
		}
	}
	return count;
}
int min(int a[],int t){
	int res=a[0];
	for(int i=1;i<t;i++){
		if(res>a[i]){
			res=a[i];
		}
	}
	return countlap(a,t,res);//chek so lan lap lai cua res	
}
//Bài 4. Lớn hơn, nhỏ hơn
void ln(int a[],int t,int x){//biger smaller 
	int count1=0,count2=0;
	for(int i=0;i<t;i++){
		if(a[i]>x)count1+=1;
		if(a[i]<x)count2+=1;
	}
	printf("%d\n",count2);
	printf("%d",count1);
}
//Bài 5. In phần tử
void print(int a[],int t){// vừa chia hết cho 2 vừa phải có stt %2==0 :a[0],a[2],a[4]
	int count=0;
	for(int i=0;i<t;i+=2){
		if(a[i]%2==0){
			count++;
			printf("%d ",a[i]);
		}
	}
	if(count==0){
		printf("NONE");
	}	
}

int main(){
	int t=0,x=0;
	scanf("%d",&t);
	int a[t];
	for(int i=0;i<t;i++){
		scanf("%d",&a[i]);
	}
//	scanf("%d",&x);
	print(a,t);
	return 0;
}