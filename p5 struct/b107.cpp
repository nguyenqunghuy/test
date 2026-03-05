#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct sinh_vien{
	char ten[100];
	float gpa;
};
typedef struct sinh_vien sv;

void nhap(sv x[],int sl_frist,int sl_add){
	for(int i=sl_frist;i<sl_add+sl_frist;i++){
		printf("nhap ten sv:");fgets(x[i].ten,100,stdin);
		x[i].ten[strcspn(x[i].ten,"\n")]='\0';
		printf("nhap gpa sv:");scanf("%f",&x[i].gpa);
		getchar();
	}
}
void in(sv x[],int k){
	printf("name:%s\nGPA:%.2f\n--------\n",x[k].ten,x[k].gpa);
}

//tim kiem
int find(sv x[],int sl,char name[100]){
	for(int i=0;i<sl;i++){
		if(strcmp(x[i].ten,name)==0){
			return i;
		}
	}
	return -1;
	/*main
	int res=find(x,sl,name);
	if(res==-1){
		printf("dont find");
	}else{
		printf("find:");
		in(x,res);
	}
	*/
}
// inra sv co diem cao nhat
void max_gpa(sv x[],int sl){
	float gpa=0,res=0;
	for(int i=0;i<sl;i++){
		if(gpa<x[i].gpa){
			gpa=x[i].gpa;
			res=i;
		}
	}
	printf("cac sv co gpa cao nhat la:");
	for(int i=0;i<sl;i++){
		if(gpa==x[i].gpa){
			in(x,i);
		}
	}
}
// xoa sv theo ten
void xoafind(sv x[],int *sl,char name[100]){// dung con tro *sl de thay doi truc tiep sl trong ham
	for(int i=0;i<(*sl);i++){
		if(strcmp(x[i].ten,name)==0){
			for(int j=i;j<(*sl)-1;j++){
				x[j]=x[j+1];
			}
			(*sl)--;
			i--;
		}
	}
}
// sap xep theo gpa
int cmp1(const void* x,const void* y){
	sv *a=(sv*)x;
	sv *b=(sv*)y;
	return a->gpa-b->gpa;
}//qsort(x,sl,sizeof(sv),cmp1);

int main(){
	sv x[5000];
	int sl=0;
	while(1){
		printf("-------------qlsv---------------\n");
		printf("1.nhap danh sach sinh vien:\n");
		printf("2.tim kiem sv theo ten:\n");
		printf("3:liet ke sv co diem cao nhat:\n");
		printf("4.xoa sinh vien theo ten:\n");
		printf("5.sap xep sinh vien theo gpa:\n");
		printf("6.hien thi dan sach sinh vien:\n");
		printf("0. break");
		printf("--------------------------------\n\n");
		int res=0;
		printf("lua chon:");
		scanf("%d",&res);getchar();
		if(res==1){
			int so_luong=0;
			printf("nhap so luong sv can nhap:");
			scanf("%d",&so_luong);getchar();
			nhap(x,sl,so_luong);
			sl+=so_luong;
		}else if(res==2){
			printf("nhap ten sv can tim");
			char name[100];fgets(name,100,stdin);name[strcspn(name,"\n")]='\0';
			int tam=find(x,sl,name);
			if(tam==-1){
				printf("ko tim thay\n\n");
			}else{
				printf("tim thay:\n");
				in(x,tam);
			}	
		}else if(res==3){
			max_gpa(x,sl);
		}else if(res==4){
			printf("nhap ten sv can tim");
			char name[100];fgets(name,100,stdin);name[strcspn(name,"\n")]='\0';
			xoafind(x,&sl,name);
		}else if(res==5){
			qsort(x,sl,sizeof(sv),cmp1);
		}else if(res==6){
			for(int i=0;i<sl;i++){
				in(x,i);
			}
		}else{
			break;
		}
	}
	return 0;
}
