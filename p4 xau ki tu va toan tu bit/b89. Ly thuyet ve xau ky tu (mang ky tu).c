#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void strtok_(){		//str = String (Chuỗi ký tự)
	char c[1000];	//tok = Token (Dấu hiệu, hoặc đơn vị nhỏ)
	fgets(c,1000,stdin);
	char*  word=strtok(c,"-/ ");//có thẻ là nh kí hiệu hay các từ
	// tách từ khỏ char và về con trỏ nếu nó tách hết thì nó trả về con trỏ "NUUL"
	while(word!=NULL){
		printf("%s\n",word);//đã tách
		word=strtok(NULL,"-/");//strtok đã đánh dấu ở bộ nhớ đệm
	}
}
int main(){
	char c[1000];
	fgets(c,1000,stdin);
	char  a[100][100];
	char* word=strtok(c," ");
	int n1=0;
	while(word!=NULL){
		strcpy(a[n1++],word);// copy word vao a[]n
		word=strtok(NULL," ");
	}
	for(int i=0;i<n1;i++){
		printf("%s\n",a[i]);
	}
	return 0;
}