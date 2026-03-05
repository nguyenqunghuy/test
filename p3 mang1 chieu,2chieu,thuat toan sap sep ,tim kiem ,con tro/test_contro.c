#include<stdio.h>

int main(){
    // dynamic allocation
    // data_type *a=(data_type *) malloc (so byte can cap phat)
    int n=10000000000000000000000000000000000000000000000;
    int *a=(int *)malloc(n*sizeof(int));
    free(a);// giai phong boj nho da dc cap phat;
    
	return 0;
}
//when you cap phat dong vung nho la "heap"
//heap :rong hon, cap phat dc nh hon,ko yeu cau cac vung nho cap phat phai nhat thiet vs nhau
//stack


