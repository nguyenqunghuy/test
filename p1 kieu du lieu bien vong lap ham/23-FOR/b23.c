#include <stdio.h>
int main(){
    int n;
    //hình 1
    scanf("%d",&n);
    for(int i=1;i<=n*n;i++){
        printf(" %d",i);
        if(i%n==0){
            printf("\n");
        }
    }
    printf("\n");
    //hình 2
    for(int i=1;i<=n;i++){
        for(int k=i;k<i+n;k++){
            printf(" %d",k);
        }
        printf("\n");
    }
    printf("\n");
    //hình 3
    int res=n;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            if(k>=res){ 
                printf("%d",i);
            }else{
                printf("~");
            }
        }
        res-=1;
        printf("\n");
    }
    printf("\n");
    //hình 4

    for(int i=1;i<=n;i++){
    	int res1=i;
    	int res2=n-1;
    	for(int j=1;j<=n;j++){
    		if(i>=j){
    		printf(" %d",res1);
    		res1+=res2;
    		res2-=1;
			}
		}
		printf("\n");
	}
    return 0;
}
