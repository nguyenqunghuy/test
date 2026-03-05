#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>




int cmp(const void *a,const void *b){//comparator
	char* x=(char*)a;
	char* y=(char*)b;
	return strcmp(x,y);//ss ca xau x va y trỏ đến con trỏ cần sắp sếp
}



int main(){
	char c[1000];
	//fgets(c,1000,stdin);
	gets(c);
	char a[100][100];
	char* token=strtok(c," ");
	int k=0;
	while(token!=NULL){
		strcpy(a[k],token);k++;
		token=strtok(NULL," ");
	}
	for(int i=0;i<k;i++){
		printf("so thu %d la: %s\n",i,a[i]);
	}
	qsort(a,k,sizeof(a[0]),cmp);// vì a[0] có đó là khoảng cách giữa các hàng trong a
			//100*sizeof(char)	
	for(int i=0;i<k;i++){
		printf("so thu %d la: %s\n",i,a[i]);
	}
	
	return 0;
}




