#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


//Bài 16. Chuẩn hóa tên 1
void chuan_hoa_name(char word[][20],int k){
	for(int i=0;i<k;i++){
		word[i][0]=toupper(word[i][0]);
		for(int j=1;j<strlen(word[i]);j++){
			word[i][j]=tolower(word[i][j]);
		}
	}
}
void chuan_hoa_years(char years[][5],int res){
	for(int i=0;i<res-1;i++){
		if(strlen(years[i])==1){
			years[i][1]=years[i][0];
			years[i][0]='0';
		}
	}
}
void b16(){
	//input
	char c[2005];
	char year[20];
	fgets(c,2005,stdin);
	if(c[strlen(c)-1]=='\n')c[(int)strlen(c)-1]=='\0';
	fgets(year,20,stdin);
	if(year[strlen(year)-1]=='\n')year[(int)strlen(year)-1]=='\0';
	// nhap ham
	char word[100][20];
	int k=0;
	char* token=strtok(c," \n");
	while(token!=NULL){
		strcpy(word[k],token);k++;
		token=strtok(NULL," \n");
	}
	char years[4][5];
	int res=0;
	token=strtok(year," /");
	while(token!=NULL){
		strcpy(years[res],token);res++;
		token=strtok(NULL," /");
	}
	chuan_hoa_name(word,k);
	chuan_hoa_years(years,res);
	
	
	//output
	for(int i=0;i<k;i++){
		printf("%s ",word[i]);
	}
	printf("\n");
	for(int i=0;i<res;i++){
		if(i==res-1){
			printf("%s",years[res-1]);
			break;
		}
		printf("%s/",years[i]);
	}
}
///Bài 17. Chuẩn hóa tên 2
void in_hoa_last_name(char word[][20],int k){
	for(int i=0;i<strlen(word[k-1]);i++){
		word[k-1][i]=toupper(word[k-1][i]);
	}
}
void b17(){
	//input
	char c[2005];
	fgets(c,2005,stdin);
	if(c[strlen(c)-1]=='\n')c[(int)strlen(c)-1]=='\0';
	// xu ly
	char word[100][20];
	int k=0;
	char* token=strtok(c," \n");
	while(token!=NULL){
		strcpy(word[k],token);
		k++;
		token=strtok(NULL," \n");
	}
	chuan_hoa_name(word,k);
	in_hoa_last_name(word,k);
	//output
	for(int i=0;i<k-1;i++){
		if(k-2==i){
			printf("%s",word[i]);
			break;
		}
		printf("%s ",word[i]);
	}
	printf(", %s",word[k-1]);
	printf("\n");
	printf("%s, ",word[k-1]);
	for(int i=0;i<k-1;i++){
		printf("%s ",word[i]);
	}
}
// Bài 18. Tạo email & mật khẩu
struct sinh_vien{
	char name[200][200];
	int sl_name;
	char ngay_sinh[15];
	char email[1000];
	int tx_gmail;// tang xuat xuat hien gmail
};
typedef struct sinh_vien sinhvien;
sinhvien sv[5005];
void b18(){
	int k=0;scanf("%d",&k);getchar();
	for(int i=0;i<k;i++){
		char c[1005]={0};
		fgets(c,1005,stdin);
		if(c[strlen(c)-1]=='\n'){
			c[(int)strlen(c)-1]='\0';
		}
		for(int i=0;i<strlen(c);i++){//chuyen tat ca ve lower
			c[i]=tolower(c[i]);
		}
		char* token=strtok(c," \n");
		int sl=0;
		while(token!=NULL){
			strcpy(sv[i].name[sl],token);//tach name
			sl++;
			strcpy(sv[i].ngay_sinh,token);//tach ngay sinh
			token=strtok(NULL," \n");
		}
		sv[i].sl_name=sl-1;// tru phan ngay sinh
	}

	//output
	for(int i=0;i<k;i++){
		//in email
		printf("%s",sv[i].name[sv[i].sl_name-1]);
		int m=0;
		while(m<sv[i].sl_name-1){
			printf("%c",sv[i].name[m][0]);
			m++;	
		}
		printf("@xyz.edu.vn");
		printf("\n");
		// in mat khau
		char *token=strtok(sv[i].ngay_sinh,"/");
		while(token!=NULL){
			int res=atoi(token);
			printf("%d",res);
			token=strtok(NULL,"/");
		}
		if(i==k-1)break;
		printf("\n");
	}
}
//Bài 19. Tạo email và mật khẩu 
/*
struct sinh_vien{
	char name[200][200];
	int sl_name;
	char ngay_sinh[15];
	char email[1000];
	int tx_gmail;// tang xuat xuat hien gmail
};
typedef struct sinh_vien sinhvien;
sinhvien sv[5005];
*/

void b19(){
	//input
	int k=0;scanf("%d",&k);getchar();
	for(int i=0;i<k;i++){
		char c[1005]={0};
		fgets(c,1005,stdin);
		if(c[strlen(c)-1]=='\n'){
			c[(int)strlen(c)-1]='\0';
		}
		for(int i=0;i<strlen(c);i++){//chuyen tat ca ve lower(ki tu thuong)
			c[i]=tolower(c[i]);
		}
		char* token=strtok(c," \n");
		int sl=0;
		while(token!=NULL){
			strcpy(sv[i].name[sl],token);//tach name
			sl++;
			strcpy(sv[i].ngay_sinh,token);//tach ngay sinh
			token=strtok(NULL," \n");
		}
		sv[i].sl_name=sl-1;// tru phan ngay sinh do nam cung vs name
	}
	
	//output
	for(int i=0;i<k;i++){
		//in email
		strcat(sv[i].email,sv[i].name[sv[i].sl_name-1]);//noi ten vao gmail
		int m=0;
		while(m<sv[i].sl_name-1){// noi cacten phu vao gmail
			strncat(sv[i].email,&sv[i].name[m][0],1);
			m++;
		}
		printf("%s",sv[i].email);//in ten gmail
		// timf cac ten giong nhau
		sv[i].tx_gmail=1;
		for(int tx=i-1;tx>=0;tx--){
			if(strstr(sv[tx].email,sv[i].email)!=NULL){
				sv[i].tx_gmail=sv[i].tx_gmail+sv[tx].tx_gmail;
				printf("%d",sv[i].tx_gmail);// in ra (so)tang xuat neu trung ten
				break;
			}
		}
		printf("@xyz.edu.vn");
		printf("\n");
		// in mat khau
		char *token=strtok(sv[i].ngay_sinh,"/");
		while(token!=NULL){
			int res=atoi(token);
			printf("%d",res);
			token=strtok(NULL,"/");
		}
		if(i==k-1)break;
		printf("\n");
	}
}
// Bài 20. Xâu Python
void b20(){
	char c[1005];
	fgets(c,1005,stdin);
	char py[]="python";
	int k=0;
	for(int i=0;i<(int)strlen(c);i++){//printf("YES");
		if(c[i]==py[k]){
			k++;
		}
	}
	if(k==6){
		printf("YES");
	}else{
		printf("NO");
	}
}



int main(){
	
	
	
	
	return 0;
}