#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct word_vanban{
    char word[21];
    int tx;
    int stt;
};
typedef struct word_vanban tu;
tu v[10000];
int check_tontai(char c[],int count){
    for(int i=0;i<count;i++){
        if(strcmp(c,v[i].word)==0){
            return i;// co ton tai va tra ve vin tri ton tai
        }
    }
    return -1;// ko ton tai
}


int cmp(const void* x,const void* y){
    tu *a=(tu*)x;
    tu *b=(tu*)y;
    if(a->tx==b->tx){
        return strcmp(a->word,b->word);
    }
    return b->tx -a->tx;
}
//b12
int check_tn(char c[]){
    int len=strlen(c);
    for(int i=0;i<len;i++){
        if(c[i]!=c[len-1-i]){
             return 0;//not tn
        }
    }
    return 1;//tn
}
//b13
int check_dx_chan(char c[]){
    int l=0,r=strlen(c)-1;
    while(l<=r){
        if(c[l]!=c[r]){//kt dx
            return 0;
        }
        if((c[r]-'0')%2!=0){
            return 0;//not chan
        }
        l++;r--;
    }
    return 1;//chan dx
}
int cmp_13(const void* a,const void* b){
    tu *x=(tu*)a;
    tu *y=(tu*)b;
    if(x->tx==y->tx){
        return x->stt-y->stt;
    }
    return y->tx-x->tx;
}
//b14
int check_tontai_14(char c[],int count){
    for(int i=0;i<count;i++){
        if(strcmp(c,v[i].word)==0){
            return i;// co ton tai va tra ve vin tri ton tai
        }
    }
    return -1;// ko ton tai
}
int main(){
    strcpy(v[0].word,"good");v[0].tx=0;
    strcpy(v[1].word,"bad");v[1].tx=0;
    strcpy(v[2].word,"wonderful");v[2].tx=0;
    strcpy(v[3].word,"terrible");v[3].tx=0;
    char tam1[105];
    while(scanf("%s",tam1)!=-1){
        char *token1=strtok(tam1," ,.\n");
        while(token1!=NULL){
            if(check_tontai_14(token1,4)!=-1){
                v[check_tontai_14(token1,4)].tx++;
            }
            token1=strtok(NULL," ,.\n");
        }
    }
    qsort(v,4,sizeof(tu),cmp);
    for(int i=0;i<4;i++){
        if(v[i].tx!=0){
            printf("%s %d\n",v[i].word,v[i].tx);
        }
    }
    return 0;
}