#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    //hinh 1
    for(int i=1;i<=n;i++){
        for (int k=1;k<=n;k++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    //hinh 2
    for(int i=1;i<=n;i++){
        for (int k=1;k<=n;k++){
            if ((i==1)||(i==n)||(k==1)||(k==n)){
                printf("*");
            }else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
    //hinh 3
    for(int i=1;i<=n;i++){
        for (int k=1;k<=n;k++){
            if ((i==1)||(i==n)||(k==1)||(k==n)){
                printf("*");
            }else {
                printf("#");
            }
        }
        printf("\n");
    }
        //hinh 4
    for(int i=1;i<=n;i++){
        for (int k=1;k<=n;k++){
            if ((i==1)||(i==n)||(k==1)||(k==n)){
                printf("%d ",i);
            }else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    
    
    
    
    return 0;
}