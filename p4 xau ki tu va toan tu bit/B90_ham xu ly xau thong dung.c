#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int ham_xau(){//các hàm sử lý sâu thông dụng
	char c[]="NguyenQuangHuy04122006@gmail.com";
	printf("char ban dau :%s\n",c);
	int chu_so=0,in_thg=0,in_hoa=0,chu_cai=0;
	for(int i=0;i<strlen(c);i++){                          // số kí tự của c : strlen(char(c));
		if(isdigit(c[i])){//check chữ số
			chu_so++;
		}else if(islower(c[i])){//check kt thg
			in_thg++;
		}else if(isupper(c[i])){//check kt tự in hoa
			in_hoa++;
		}
		if(isalpha(c[i])){//check kí tự chữ cái
			chu_cai++;
		}
	}
	printf("sum ki tu %d \nisdigit= %d, islower= %d, supper= %d, isalpha= %d\n\n",strlen(c),chu_so,in_thg,in_hoa,chu_cai);
	
//chuyển kí tự  về kt in hoa và thg
	char c1='H';
	char res1=tolower(c1);// chuyển kí tự về dạng in thường
	printf("'%c' tolower=> '%c'\n",c1,res1);
	
	char c2='H';
	char res2=toupper(c2);// chuyển kí tự về dạng in hoa
	printf("'%c' upper=> '%c'\n\n",c2,res2);
	
//	ko nhan trên trình chấm onine							chuyển xâu về xâu in hoa và thg
								strlwr(c);//chuyển xâu về in thg 
								char *res3=	strlwr(c);// trả về con trỏ char
								printf("%s %s\n",c,res3);
								strupr(c);//chuyển xâu về in hoa
								char *res4=strupr(c);// trả về con trỏ char
								printf("%s %s\n\n",c,res4);
	
// to so sánh 2 xâu theo thứ tự từ điển	
	char a[]="abc";
	char b[]="abd";//a<b return -1;(trả về số âm)
				   //a>b return 1;(trả về số dương)
				   //a=b return 0;
	printf("%s %s %d\n\n",a,b,strcmp(a,b));
	
// Nối xâu 
	char frist[]="huy";	
	char end[]="quang";
	strcat(frist,end);// nối end vào frist
	printf("%s\n\n",frist);
	//nối từng kí tự nhỏ
		char frist[20]="huy";	
		char end[20]="01234";
	/*
	char *strncat(char *dest, const char *src, size_t n);
	dest: Chuỗi đích (nơi nhận).
	src: Chuỗi nguồn (nơi lấy), bắt buộc phải truyền vào một địa chỉ (con trỏ).
	n: Số lượng ký tự muốn lấy.

	*/
	strncat(frist,&end[1],2);
	printf("%s",frist);
	
	
	
//copy
	char frist1[]="new";	
	char end1[]="old";
	printf("%s\n------------",frist1);
	strcpy(frist1,end1);// delete frist and copy end1 vào frist1,
	printf("%s\n\n",frist1);
	
// flip 
//khai tử nốt					strrev(c);
								printf("%s\n\n",c);
	
// check tập con
	char pos1[]="nguyenquanghuy";
	char pos2[]="quang";
	char* pos = strstr(pos1,pos2);// trả về con trỏ tới vin trí xuất hiện đầu tiên của pos1 trong pos2  
	if(pos == NULL){// nếu ko find thì có giá trị "NULL"
		printf("trong frist ko ton tai end \n\n");
	}else{
		printf("trong frist co ton tai end %s\n\n",pos);//check pos2 xem có phải tập con của pos1 ko
	}
// gán giá trị 0 or -1 vào mảng
	int inta[]={1,2,3,4};
	memset(a,0,sizeof(inta));
	for(int i=0;i<4;i++){
		printf("%d ",*(inta+i));
	}
	printf ("\n\n");
//chuyển xâu sang int of long long
	char change[]="123456789101112131";
	
	int change1=atoi(change);//chuyển char to int
	printf("%d\n",change1);//nếu có số 0 ở đầu nó sẽ tự bỏ
	
	long long change2=atoll(change);//chuyển char to long long 
	printf("%lld\n",change2);//nếu có số 0 ở đầu nó sẽ tự bỏ	
	//nếu có kt chữ nó sẽ worng and return 0;
	
// xoa dau n trong fgets();	
	c[strcspn(c, "\n")] = '\0';
	//str = String (Chuỗi)
	//c = Complement (Phần bù / Nghịch đảo)
	//spn = Span (Độ dài đoạn / Khoảng cách)
	
}




int main(){
	//               ham gets(); bị khai tử r 
	ham_xau();
	return 0;
}





