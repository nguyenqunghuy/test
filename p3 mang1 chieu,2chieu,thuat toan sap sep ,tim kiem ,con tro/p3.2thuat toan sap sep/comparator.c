#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//void qsoft( void *base, size_t nitems, size_t size,int (*compar)(const void *,const void*))
//         array	   so luong phan tu, kich thoc


int comparator(const void *a, const void *b){
	int *x=(int *)a;
	int *y=(int *)b;
	//nếu sx đúng thứ tự mong muốn in ra số âm
	//nếu sx đúng thứ tự mong muốn in ra số âm
	return abs(*x)-abs(*y);
}

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",(a+i));
	}
	qsort(a,n,sizeof(int),comparator);
	for(int i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
	return 0;
}


