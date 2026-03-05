#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sinhvien{
    char name[100];
	int stt;
    char ngaysinh[15];
    char diachi[200];
    double gpa;
    int thang;
};

typedef struct sinhvien sv;
void nhap(int i,sv a[]){
	a[i].stt=i;
    fgets(a[i].name,100,stdin);
    a[i].name[strcspn(a[i].name,"\n")]='\0';
    fgets(a[i].ngaysinh,15,stdin);
    a[i].ngaysinh[strcspn(a[i].ngaysinh,"\n")]='\0';
    fgets(a[i].diachi,200,stdin);
    a[i].diachi[strcspn(a[i].diachi,"\n")]='\0';
    scanf("%lf",&a[i].gpa);
    getchar();
}
void in(int i,sv a[]){
    printf("%s %s %s %.2lf\n",a[i].name,a[i].ngaysinh,a[i].diachi,a[i].gpa);
}
// sắp xếp theo điểm gpa
int cmp(const void* x,const void* y){
    sv *a =(sv*)x;
    sv *b =(sv*)y;
    if(strcmp(a->name,b->name)==0){
		if(a->stt>b->stt){
			return 1;
		}else{
			return 0;
		}
	}else{
		return strcmp(a->name,b->name);
	}
}
//b6 nam dinh gpa>=2,5
//b7 xoa sinh vien theo gpa<1
void xoa(int *n,sv a[]){
    int i = 0;      
    while(i < (*n)){
        if(a[i].gpa < 1){
            for(int j = i; j < (*n) - 1; j++){
                a[j] = a[j+1];
            }
            (*n)--;
        } else {
            i++;
        }
    }
}
//sắp xếp theo diachi
int cmp_8(const void* x,const void* y){
    sv* a=(sv*)x;
    sv* b=(sv*)y;
    if(strcmp(a->diachi,b->diachi)==0){
        if(a->gpa>b->gpa){
            return -1;
        }else{
            return 1;
        }
    }else{
        return strcmp(a->diachi,b->diachi);
    }
}
//b9
struct diachi{
    char diachi[100];
    int tx;
};
typedef struct diachi dc;
dc v[1000];
int m=0;
void find_dc(char s[]){
    for(int i=0;i<m;i++){
        if(strcmp(v[i].diachi,s)==0){
            v[i].tx++;
            return;// tim thay va tang tang xuat
        }
    }
    strcpy(v[m].diachi,s);
    m++;
    v[m-1].tx=1;
    return;//ko tim thay
}
int cmp_9(const void* x,const void* y){
    dc* a=(dc*)x;
    dc* b=(dc*)y;
    if(a->tx==b->tx){
        return strcmp(a->diachi,b->diachi);
    }
    return b->tx-a->tx;
}
/* main
int n=0;
    int n=0;
    scanf("%d",&n);
    getchar();
    sv a[1000];
    for(int i=0;i<n;i++){
        nhap(i,a);
        find_dc(a[i].diachi);
    }
    qsort(v,m,sizeof(dc),cmp_9);
    for(inchar* token=t i=0;i<m;i++){
        if(v[i].tx==v[0].tx){
            printf("%s\n",v[i].diachi);
        }else{
            break;
        }
    }
*/
//b10;
int main(){
    int n=0;
    scanf("%d",&n);
    getchar();
    sv a[1000];
    for(int i=0;i<n;i++){
        nhap(i,a);
    }
    for(int i=0;i<n;i++){
        char tam[15];
        strcpy(tam,a[i].ngaysinh);
        char *token=strtok(tam,"/");
        token=strtok(NULL,"/\n");
        char res[10];
        strcpy(res,token);
        a[i].thang=atoi(res);
        if(a[i].thang==4){
            in(i,a);
        }
    }
    return 0;
}