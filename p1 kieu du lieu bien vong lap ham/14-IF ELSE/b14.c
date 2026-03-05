#include<stdio.h>
int main (){
	float a,b,c,d;
	scanf("%f%f%f%f",&a,&b,&c,&d);
	float tb=(a+b+c*2+d*3)/7;
	if(tb>=8){
		printf("GIOI");	
	}else if(tb>=6.5){
		printf("KHA");
	}else if(tb>=5){
		printf("TRUNG BINH");
	}else if( 0<=tb && 0<5 ){
		printf("YEU");
	}else{
		printf("ERORR");
	}
	
	
	
	
	return 0;
}






