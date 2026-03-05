  #include <stdio.h>
int main(){
    int n;
    // hinh 1
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for (int k=1;k<=n;k++){
            if(k<=i){
                printf("*");
            }else {
                printf("  ");
            }
        } 
        printf("\n");
    }
    printf("\n");
    //hinh 2
    for(int i=n;i>=0;i--){
        for (int k=1;k<=n;k++){
            if(k<=i){
                printf("*");
            }else {
                printf("  ");
            }
        } 
        printf("\n");
    }
    //hình 3
    for(int i=n;i>=1;i--){
        for (int k=1;k<=n;k++){
            if(k>=i){
                printf("*");
            }else {
                printf("  ");
            }
        } 
        printf("\n");
    }
    printf("\n");
    //hình 4
    for(int i=1;i<=n;i++){
        for (int k=1;k<=n;k++){
            if(k>=i){
                printf("*");
            }else {
                printf("  ");
            }
        } 
        printf("\n");
    }
    printf("\n");
    //hình 5
      for(int i=1;i<=n;i++){
        for (int k=1;k<=n;k++){
            if(k==1|| k==i||i==n ){
                printf("*");
            }else {
                printf("  ");
            }
        } 
        printf("\n");
    }
    return 0;
}
