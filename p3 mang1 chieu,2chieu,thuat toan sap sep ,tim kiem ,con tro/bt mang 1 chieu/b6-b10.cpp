#include<stdio.h>
#include<math.h>


//Bài 6. Đếm cặp số 1
int count(int a[],int t,int k){
	int count=0;
	for(int i=0;i<t;i++){
		for(int j=i+1;j<t;j++){
			if((a[i]+a[j])==k){
				count+=1;
			}
		}
	}
	return count;
}
///Bài 7. Đếm cặp số 2
int b7(int a[],int t){//check difference
	int count=1e6;
	for(int i=0;i<t;i++){
		for(int j=i+1;j<t;j++){
			if(fabs(a[i]-a[j])<count){
				count=fabs(a[i]-a[j]);
			}
		}
	}
	return count;
}
//Bài 8. Liệt kê các giá trị khác nhau
void b8(int a[],int t){//check difference number
	printf("%d ",a[0]);
	for(int i=1;i<t;i++){
		int count=0;
		for(int j=i-1;j>=0;j--){
			if(a[j]==a[i]){
				++count;
			}
		}
		if(count==0){
			printf("%d ",a[i]);
		}
	}
}
// Bài 9. Tần suất
void b9(int a[],int t){
	for(int i=0;i<t;i++){
		int count=0;
		for(int j=0;j<t;j++){	
			if(a[i]==a[j]){
				count++;	
			}
		}
		int check=0;
		int res=i;
		while(res!=0){
			if(a[i]==a[res-1]){
				check++;
			}
			res--;
		}	
		if(check==0){
			printf("%d ",a[i]);
			printf("%d\n",count);
		}
		
	}
}	
//Bài 10. Cân bằng nguyên tố
int snt(int n ){
	if(n<2)return 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return 0;
	}
	return 1;
}
void b10(int a[],int t){
	for(int i=1;i<t-1;i++){
		int sum1 =0,sum2=0;
		for(int j=0;j<=i-1;j++){//check betwen to left
			sum1+=a[j];
		}
		for(int k=i+1;k<t;k++){//check betwen to right
			sum2+=a[k];
		}
		if(snt(sum1)&&snt(sum2)){
			printf("%d ",i);
		}
	}
}
int main(){
	int t=0;
	scanf("%d",&t);
	int a[t];
	for(int i=0;i<t;i++){
		scanf("%d",&a[i]);
	}
	b10(a,t);
	return 0;
}



