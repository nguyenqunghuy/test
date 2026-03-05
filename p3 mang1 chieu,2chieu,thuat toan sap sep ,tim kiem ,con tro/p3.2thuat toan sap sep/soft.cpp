 #include<stdio.h>
long long bien[1000001];
void sxn (int a[],int t){//tim luon to va nho
	int ltr=0;//trai sang phai
	int rtl=t;//phai sang trai
	while(ltr<=rtl){
		int max=a[ltr],admax=ltr;
		int min=a[ltr],admin=ltr;
		for(int i=ltr;i<rtl;i++){//find max and min
			if(max<a[i]){//find max
				max=a[i];
				admax=i;
			}
			if(min>a[i]){//find min
				min=a[i];
				admin=i;
			}
		}
		//đổi chỗ min vs vịn trí cần đổi
		a[admin]=a[ltr];
		a[ltr]=min;
		//đổi chỗ max vs vịn trí cần đổi
		a[admax]=a[rtl-1];//-1 vi rtf là số -1 mới ra vin trí
		a[rtl-1]=max;
		rtl--;
		ltr++;
	}
}
void sx(int a[],int t){
	int count=0;
	for(int i=0;i<t-1;i++){
		if(a[i]>a[i+1]){
			int res=0;
			res=a[i];
			a[i]=a[i+1];
			a[i+1]=res;
			count++;
		}
	}
	if(count==0){
		return;
	}else{
		sx(a,t);
	}	
} 
//sắp xếp chọn 
void sx2(int a[],int t){//selection sort
	for(int i=0;i<t;i++){
		int max=10e7+7;
		int adress=i;
		for(int j=i;j<t;j++){//find min and adress min
			if(a[j]<max){
				max=a[j];
				adress=j;
			}
		}
		a[adress]=a[i];
		a[i]=max;
	}
}
//sắp xếp nổi bọt
void sx3 (int a[],int t){////bubble sort
	for(int i=0;i<t;i++){
		t--;
		for(int j=0;j<t;j++){
			if(a[j+1]<a[j]){//find va doi vin tri
				int res=a[j];
				a[j]=a[j+1];
				a[j+1]=res;
			}
		}
	}
}
//sắp xếp chèn
void chen(int a[],int t,int k,int x){//chuyen a[k] ra vin tri x
	int res=a[k];
	for(int i=k-1;i>=x;i--){
		a[i+1]=a[i];
	}
	a[x]=res;
}
void sx4 (int a[],int t){//insertion sort
	for(int i=1;i<t;i++){
		int j;
		for(j=i-1;j>=0;j--){
			if(a[i]<a[j])continue;
			else break;
		}
		chen(a,t,i,j+1);
	}
}
void sx4easy (int a[],int t){//more understand
	for(int i=1;i<t;i++){
		int pos=i-1;
		int value=a[i];
		while((pos>=0)&&(value<a[pos])){
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1]=value;
	}	
}
void counting(int a[],int t){//counting soft sắp xếp đếm phân phối
	for(int i=0;i<1000001;i++){
		bien[i]=0;
		if(bien[i]>0){
			while(bien[i]!=0){
				printf("%d ",i);
				bien[i]--;
			}
		}
	}
}
//sắp xếp trộn merge soft độ phức tạp(Onlog(n)-->n^2)
int min(int a[],int m,int t){//tìm min trong khoảng i đến t 
	int min=a[m];
	for(int i=m;i<t;i++){
		if(min<a[i]){
			min=a[i];
		}
	}
	return min;
}
void sx5(int a[],int b[],int t1,int t2){//sx trộn 
	int sum=t1+t2;
	int bien2[sum]={0};
	int i1=0,i2=0;
	long long value=0;
	while((i1<t1)||(i2<t2)){
		if(i1==t1){
			bien2[value]=b[i2];
			i2++;
		}else if(i2==t2){
			bien2[value]=a[i1];
			i1++;
		}else if(a[i1]<=b[i2]){
			bien2[value]=a[i1];
			i1++;
		}else{
			bien2[value]=b[i2];
			i2++;
		}
		value++;
	}
	for(int i=0;i<sum;i++){
		printf("%d ",bien2[i]);
	}
}
//*******************dung de quy***********************
void meger(int a[],int l,int mid,int r){//trộn hàm
	int n1=mid-l+1;
	int n2=r-mid;
	int x[n1]={0};
	int y[n2]={0};
	for(int i=0;i<n1;i++){
		x[i]=a[l+i];
	}
	for(int i=0;i<n2;i++){
		y[i]=a[mid+i+1];
	}
	int bien[r-l];
	int i1=0;int i2=0;int value=l;
	while(n1>i1&&n2>i2){
		if(x[i1]>=y[i2]){
			a[value++]=y[i2++];
		}else{
			a[value++]=x[i1++];
		}
	}
	while(n1>i1){
		a[value++]=x[i1++];
	}
	while(n2>i2){
		a[value++]=y[i2++];
	}
}
void megersoft(int a[],int l,int r){//sx tron O(nlog(n))
	if(l<r){
		int mid=l+(r-l)/2;
		megersoft(a,l,mid);
		megersoft(a,mid+1,r);
		meger(a,l,mid,r);
	}	
}
int hoanvi(int a[],int i,int j){//hoan vi gia tri o vin tri i sang j
	int res=a[i];
	a[i]=a[j];
	a[j]=res;
}
int lomuto(int a[],int l,int r){//lomuto parition 
		int pivot=a[r];
		int res=l-1;// tao bien chay
		for(int i=l;i<r;i++){//chay tu l den r-1 bo thg pivot
			if(pivot>=a[i]){
				res++;
				hoanvi(a,res,i);
			}
		}
	// hoan vi pivot ra giua to vs nho
		res++;
		hoanvi(a,r,res);
	return res;
}
void quicksoft(int a[],int l,int r){// tao ham de chia
	if(l<r){
		int i=lomuto(a,l,r);// sap xep va chia tiep o vong duoi den khi moi ham co 1 pt thi dung
		quicksoft(a,l,i-1);
		quicksoft(a,i+1,r);
	}
}
int main(){
	int a[]={0,3,8,5,7,9,8,6,4,2};
	int t=10;
	quicksoft(a,0,t-1);
	for(int i=0;i<t;i++){
		printf("%d ",a[i]);
	}
	return 0;
}