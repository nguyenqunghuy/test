#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct gmail{
    char gmail[100];
    int tx;
};
typedef struct gmail gmail;

char c[100];
gmail gm[1000];
int check_ton_tai(char c[],int res){
    for(int i=0;i<res;i++){
        if(strcmp(gm[i].gmail,c)==0){
            return i;
        }
    }
    return -1;
}
int cmp(const void* x,const void* y){
    gmail *a=(gmail*)x;
    gmail *b=(gmail*)y;
    if(a->tx==b->tx){
        return strcmp(a->gmail,b->gmail);
    }else{
        return b->tx-a->tx;
    }
}
int main(){
    char day[15],time[12],tam[101];
    int res=0;
    while(scanf("%s %s %s",day,time,tam)!=-1){
        if(check_ton_tai(tam,res)==-1){//neu ham chua ton tai bao h
            strcpy(gm[res].gmail,tam);
            gm[res].tx=1;
            res++;
        }else{// da ton tai va +bien tx do the 1
            gm[check_ton_tai(tam,res)].tx++;
        }
    }
    qsort(gm,res,sizeof(gmail),cmp);
    for(int i=0;i<res;i++){
        printf("%s %d\n",gm[i].gmail,gm[i].tx);
    }

    return 0;
}