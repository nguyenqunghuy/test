#include<stdio.h>
#include<math.h>

/* soft da
int lomuto(int a[],int l ,int r){
	int pivot=a[r];
	int res=l-1;
	for(int i=l;i<r;i++){
		if(pivot>=a[i]){
			res++;
			int tmp=a[i];// hoan vi a[i] vs a[res]
			a[i]=a[res];
			a[res]=tmp;
		}
	}
	// hoan vi privot ra giua lon va nho;
	res++;
	a[r]=a[res];
	a[res]=pivot;
	return res;
}
void quicksoft(int a[],int l,int r){
	if(l<=r){
		int i=lomuto(a,l,r);
		quicksoft(a,l,i-1);
		quicksoft(a,i+1,r);
	}
}
*/
//*********b1****************
int max(int a[],int t){//find max
	int max=a[0];
	int vintri=0;
	for(int i=1;i<t;i++){
		if(max<a[i]){
			max=a[i];
			vintri=i;
		}
	}
	printf("%d ",max);
	printf("%d\n",vintri);
	return max;
}
void min(int a[],int t){//find min
	int min=a[0];
	int vintri=0;
	for(int i=1;i<t;i++){
		if(min>=a[i]){
			min=a[i];
			vintri=i;
		}
	}
	printf("%d ",min);
	printf("%d\n",vintri);
}
// use new thuat toan moi(eratothenes)
int bien[10000007];
int countsnt(int a[],int t,int max ){//max la so lon nhat trong mang a 
	if(max<2){
		printf("0");
		return 0;
	}
	for(int i=0;i<10000007;i++){
		bien[i]=1;
	}
	bien[0]=0;
	bien[1]=0;
	for(int i=2;i*i<=max;i++){
		for(int j=i*i;j<=max;j+=i){
			bien[j]=0;
		}
	}
	int count=0;
	for(int i=0;i<t;i++){
		if((a[i]>=0)&&(bien[a[i]])==1){
			count++;
		}
	}
	return count;
}
int tichmax(int a[],int t){
	int max=0;
	for(int i=0;i<=t;i++){
		for(int j=i;j<t;j++){
			if(max<(a[i]*a[j])){
				max=a[i]*a[j];
			}
		}
	}
	return max;
}
void checkdx(int a[],int t){//check doi xung
	int l=0;int r=t-1;
	while(l<r){
		if(a[l]!=a[r]){
			printf("NO");
			return;
		}
	}
	printf("YES");
	return;
}
void b1(int a[],int t){
	int somax=max(a,t);
	min(a,t);
	printf("%d\n",countsnt(a,t,somax));
	printf("%d\n",tichmax(a,t));
	checkdx(a,t);
	int tichsum=a[0];
	for(int i=1;i<t;i++){
		tichsum*=a[i];
	}
	printf("\n%d",tichsum%(1000000007));
}
void b3(long long a[],int t){
	printf("%lld ",a[0]);
	for(int i=1;i<t;i++){
		int check=0;
			for(int j=i-1;j>=0;j--){
			if(a[i] <= a[j]){
				check=1;
				break;
			}
		}
		if(check==0){
			printf("%lld ",a[i]);
		}
	}
}
int lomuto(int a[],int l,int r){
	int value=a[r];
	int ichay=l-1;
	for(int i=l;i<r;i++){
		if(a[i]<=value){//hoan vi cac bien nho hon a[r] len trc
			ichay++;
			int res=a[i];
			a[i]=a[ichay];
			a[ichay]=res;
		}
	}
	//hoan vin r voi ichay
	ichay++;
	a[r]=a[ichay];
	a[ichay]=value;
	return ichay;
}
void sx(int a[],int l,int r){
	if(l<r){
		int mid=lomuto(a,l,r);
		sx(a,l,mid-1);
		sx(a,mid+1,r);
	}
}
int diehard(int a[],int t){
	// tao bien so tien mat dang co
	int money[3]={0};//tuong ung vs25,50,100
	for(int i=0;i<t;i++){
		if(a[i]==25){//25tien
			money[0]++;
		}else if(a[i]==50){//50 tien
			if(money[0]>0){
				money[0]--;
				money[1]++;
			}else{
				return 0;//don`t enough
			}
		}else{//100 tien
			if((money[0]>0)&&(money[1]>0)){
				money[0]--;
				money[1]--;
			}else if((money[0]>=3)){
				money[0]-=3;
			}else{
				return 0;
			}
		}
	}
	return 1;
}
long long khoangcach(long long a[],long long i,long long x,long long t){//tinh khoang cach tu vin tri i den x
	return fabs(a[i]-a[x]);
}
void dearletter(long long a[],long long t){
	if(t==1){
		printf("0 0");return;
	}
	for(int i=0;i<t;i++){
		//xu ly rieng if i=0 va i=t-1
		if(i==0){
			printf("%lld ",khoangcach(a,i,i+1,t));//mini
			printf("%lld\n",khoangcach(a,i,t-1,t));//maxi
			continue;
		}
		if(i==(t-1)){
			printf("%lld ",khoangcach(a,i,i-1,t));//mini
			printf("%lld\n",khoangcach(a,i,0,t));//maxi
			continue;
		}
		//cac th con lai
		if(khoangcach(a,i,i-1,t)>=khoangcach(a,i,i+1,t)){//find mini la kc cac thanh pho gan nhat
			printf("%lld ",khoangcach(a,i,i+1,t));
		}else{
			printf("%lld ",khoangcach(a,i,i-1,t));
		}
		if(khoangcach(a,i,0,t)>=khoangcach(a,i,t-1,t)){//find maxi la kc cac thanh pho dau va cuoi
			printf("%lld\n",khoangcach(a,i,0,t));
		}else{
			printf("%lld\n",khoangcach(a,i,t-1,t));
		}
	}	
}
//b6
int ucln(long long a,long long b){
	while(b!=0){
		int res=a%b;
		a=b;
		b=res;
	}
	return a;
}
int main(){
	int t=0;
	scanf("%d",&t);
	long long a[t];
	for(int i=0;i<t;i++){
		scanf("%lld",&a[i]);
	}
	int count=0;
	for(int i=0;i<t;i++){
		for(int j=i;j<t;j++){
			if(ucln(a[i],a[j])==1){
				count++;
			}
		}
	}
	printf("%d",count);
	return 0;
}
