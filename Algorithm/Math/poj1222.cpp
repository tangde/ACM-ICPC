//poj1222
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=200;
typedef int Matrix[40][40];

bool free_x[maxn]; // 标记自由变元
int x[maxn];   // 记录解
// A为增广矩阵，m个方程，n个未知数
// 无解返回-1,唯一解返回在x中，否则返回自由变元个数
int gauss(Matrix A,int m,int n){
	memset(free_x,0,sizeof(free_x));
	int i=0,j=0,k,r,u;
	while(i<m&&j<n){
		r=i;        // 处理第i个方程第j列
		for(k=i;k<m;k++)if(A[k][j]){
			r=k;break;    // 找到一第u>=i行，第j列不为0的数A[r][j]
		}
		if(A[r][j]){   // 如果找到就消元，否则跳到下一列
			if(r!=i)for(k=0;k<=n;k++)swap(A[r][k],A[i][k]);
			for(u=i+1;u<m;u++)if(A[u][j]){ // 用第i行消元
				for(k=j;k<=n;k++)A[u][k]^=A[i][k];
			}
			i++;
		}
		j++;
	}
	for(int k=i;k<m;k++){
		if(A[k][j]!=0)return -1;  // 无解
	}
	if(i<n)return n-i;  // 解不唯一，返回自由变元个数
	// 回代
	for(i=n-1;i>=0;i--){
		x[i]=A[i][n];
		for(j=i+1;j<n;j++){
			x[i]^=(A[i][j]*x[j]);
		}
	}
	return 0;
}

Matrix A;
int a[6][6];
int main(){
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		memset(A,0,sizeof(A));
		for(int i=0;i<30;i++){
			scanf("%d",&A[i][30]);
		}
		for(int i=0;i<5;i++){
			for(int j=0;j<6;j++){
				int k=6*i+j;
				A[k][k]=1;
				if(i>0)A[k][k-6]=1;
				if(i<4)A[k][k+6]=1;
				if(j>0)A[k][k-1]=1;
				if(j<5)A[k][k+1]=1;
			}
		}
		gauss(A,30,30);
		printf("PUZZLE #%d\n",kase);
		for(int i=0;i<5;i++){
			for(int j=0;j<6;j++){
				if(j==0)printf("%d",x[6*i+j]);
				else printf(" %d",x[6*i+j]);
			}
			putchar('\n');
		}
	}
	return 0;
}






