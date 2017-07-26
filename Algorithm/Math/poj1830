//poj1830
//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=40;
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
int s[maxn],e[maxn];
long long power[maxn];
int main(){
	int T,n,u,v;
	power[0]=1;
	for(int i=1;i<30;i++)power[i]=power[i-1]<<1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(A,0,sizeof(A));
		for(int i=0;i<n;i++)scanf("%d",&s[i]);
		for(int i=0;i<n;i++)scanf("%d",&e[i]);
		for(int i=0;i<n;i++){
			A[i][n]=s[i]^e[i];
			A[i][i]=1;
		}
		while(scanf("%d%d",&u,&v)&&u){
			u--;v--;
			A[v][u]=1;
		}
		int k=gauss(A,n,n);
		if(k==-1)printf("Oh,it's impossible~!!\n");
		else printf("%lld\n",power[k]);
	}
	return 0;
}






