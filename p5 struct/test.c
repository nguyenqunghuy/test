#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>





//#include<stdlib.h>
struct girl{
	char ten[100];
	int tit;
	int ass;
};
typedef struct girl girl;
void test_1(){
	girl s1;
	//dot operrator: toan tu cham
	printf("nhap ten:");
	fgets(s1.ten,100,stdin);
	printf("nhap so do vu:");
	scanf("%d",&s1.tit);
	printf("nhap so do dit:");
	scanf("%d",&s1.ass);
	printf("%s %d %d\n",s1.ten,s1.tit,s1.ass);
	girl s2=s1;
	printf("%s %d %d",s2.ten,s2.tit,s2.ass);
}
// nhap qua ham
void test_ham(){
	int n;
	printf("nhap so luong harem:");
	scanf("%d",&n);
	girl a[n];
	for(int i=0;i<n;i++){
		getchar();
		printf("nhap ten:");
		fgets(a[i].ten,100,stdin);
		printf("nhap so do vu:");
		scanf("%d",&a[i].tit);
		printf("nhap so do dit:");
		scanf("%d",&a[i].ass);
	}
	int max=0;
	for(int i=0;i<n;i++){
		if(a[i].tit>max){
			//printf("%d\n",a[i].tit);
			max=i;
		}
	}
	printf("%s %d %d\n",a[max].ten,a[max].tit,a[max].ass);
}



//con tro
void point1(){
	girl x;
	strcpy(x.ten,"Linh");
	x.tit=100;
	x.ass=120;
	girl *point=&x;
// có hai kiểu và cách dung con trỏ struct
	printf("%s %d %d\n",point->ten,point->tit,point->ass);// dung mui ten
	printf("%s %d %d\n",(*point).ten,(*point).tit,(*point).ass);// dung gai tham chieu
}





//-------------------------------------------------------------------------
// có 2 kiểu nhập thong tin:
//     -nhap ham qua struct:
girl nhap1(){
	girl x;
	printf("nhap ten:");fgets(x.ten,100,stdin);
	printf("nhap so do vu:");scanf("%d",&x.tit);
	printf("nhap so do dit:");scanf("%d",&x.ass);
	return x;
}// khai bao nhap1:  a[i]=nhap1();


//     -nhap ham qua con tro struct:
void nhap2(girl *x){
	printf("nhap ten:");fgets(x->ten,100,stdin);
	printf("nhap so do vu:");scanf("%d",&x->tit);
	printf("nhap so do dit:");scanf("%d",&x->ass);
}// khai bao nhap2:  nhap2(&a[i]);

//  trả về thong tin
void in(girl x){
	printf("%s %d %d\n",x.ten,x.tit,x.ass);
}
//--------------------------------------------------------





int main(){
	
	
	return 0;
}