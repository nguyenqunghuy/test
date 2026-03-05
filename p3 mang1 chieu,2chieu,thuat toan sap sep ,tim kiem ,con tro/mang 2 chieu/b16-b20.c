#include<stdio.h>
#include<math.h>
int d_hang[8]={-1,-1,-1,0,0,1,1,1};
int d_cot[8]={-1,0,1,-1,1,-1,0,1};
int d_hang1[4]={-1,0,0,1};
int d_cot1[4]={0,-1,1,0};
void nhap(int a[][100],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void xuat(int a[][500],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
//Bài 16. Đếm đảo 1
//int d_hang[4]={-1,0,0,+1};
//int d_cot[4]={0,-1,1,0};
void erase_dao(int a[][500],int n ,int m ,int res1,int res2){
	a[res1][res2]=0;
	for(int i=0;i<4;i++){
		if(((res1+d_hang[i])==-1)||((res1+d_hang[i])==n))continue;
		if(((res2+d_cot[i])==-1)||((res2+d_cot[i])==m))continue;
		if(a[res1+d_hang[i]][res2+d_cot[i]]){
			erase_dao(a,n,m,res1+d_hang[i],res2+d_cot[i]);
		}
	}	
}
//Bài 17. Đếm đảo 12
void erase_dao2(int a[][500],int n ,int m ,int res1,int res2){
	a[res1][res2]=0;
	for(int i=0;i<8;i++){
		if(((res1+d_hang[i])==-1)||((res1+d_hang[i])==n))continue;
		if(((res2+d_cot[i])==-1)||((res2+d_cot[i])==m))continue;
		if(a[res1+d_hang[i]][res2+d_cot[i]]){
			erase_dao2(a,n,m,res1+d_hang[i],res2+d_cot[i]);
		}
	}
	
}
//Bài 18. Số điểm cực đại
int point_max(int a[][500],int n ,int m ,int res1,int res2){
	for(int i=0;i<8;i++){
		if(((res1+d_hang[i])==-1)||((res1+d_hang[i])==n))continue;
		if(((res2+d_cot[i])==-1)||((res2+d_cot[i])==m))continue;
		if(a[res1+d_hang[i]][res2+d_cot[i]]>=a[res1][res2]){
			return 0;
		}
	}
	return 1;
}
//Bài 19. Maximum path sum
long long max_land(int a[][100],int n ,int m){// use quy hoach dong
	long long res[100][100];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			res[i][j]=0;
			if((i==0)&&(j==0)){
				res[i][j]=a[i][j];
			}else if(i==0){
				res[i][j]=a[i][j]+res[i][j-1];
			}else if(j==0){
				res[i][j]=a[i][j]+res[i-1][j];
			}else{
				res[i][j]=a[i][j]+fmax(res[i][j-1],res[i-1][j]);
			}
		}
	}
	return res[n-1][m-1];
}
//Bài 20. Tìm đường đi
int find_way(int a[][100],int n,int m,int s,int t,int u ,int v){
	if((s==u)&&(t==v)){
		return 1;
	}
	a[s][t]=0;		
	for(int i=0;i<4;i++){
		if(((0<=(s+d_hang1[i]))&&((s+d_hang1[i])<n))&&((0<=(t+d_cot1[i]))&&((t+d_cot1[i])<m))){
			if(a[s+d_hang1[i]][t+d_cot1[i]]){
				if(find_way(a,n,m,s+d_hang1[i],t+d_cot1[i],u,v)){
					return 1;
				}
			}
		}
	}
	return 0;
}


int main(){
	int a[100][100];
	int n,m,s, t, u , v;
	scanf("%d%d%d%d%d%d",&n,&m,&s, &t, &u , &v);
	nhap(a,n,m);
	if(find_way(a,n,m,s-1,t-1,u-1,v-1)){
		printf("YES");
	}else{
		printf("NO");
	}
	return 0;
}