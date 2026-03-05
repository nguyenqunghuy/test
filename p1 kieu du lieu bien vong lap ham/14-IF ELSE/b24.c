#include<stdio.h>
#include<math.h>

int main(){
	int d1,d2,d3;
	scanf("%d %d %d",&d1,&d2,&d3);
	long long b1,b2,b3,b4;
	b1=d1+d2+d3;
	b2=d1*2+d2*2;
	b3=d1*2+d3*2;
	b4=d2*2+d3*2;
//	if((b1<=b2)&&(b1<=b3)&&(b1<=b4)){                 worng way
//		printf("%lld",b1);
//	}else if((b2<b1)&&(b2<b3)&&(b2<b4)){
//		printf("%lld",b2);
//	}else if((b3<b1)&&(b3<b2)&&(b3<b4)){
//		printf("%lld",b1);
//	}else if((b4<b1)&&(b4<b2)&&(b4<b3)){
//		printf("%lld",b4);
//	}else{
//		printf("erorr");
//	}
	int res =fmin(fmin(b1,b2),fmin(b3,b4));
	printf("%d",res);
	return 0;
}