//poj1681
//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn=400+10;
typedef int Matrix[maxn][maxn];

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
int slove(Matrix A,int m,int n){
	// 消元
	int t=gauss(A,m,n);
	if(t<0)return -1;
	int res=inf,cnt;
	for(int i=0;i<(1<<t);i++){
		cnt=0;
		for(int j=0;j<t;j++){
			if(i&(1<<j)){x[j]=1;cnt++;}
			else x[j]=0;
		}
		for(int j=n-t-1;j>=0;j--){
			x[j]=A[j][n];
			for(int k=j+1;k<n;k++){
				x[j]^=(A[j][k]&&x[k]);
			}
			cnt+=x[j];
		}
		res=min(res,cnt);
	}
	return res;
}
Matrix A;
char s[22][22];
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%s",s[i]);
		memset(A,0,sizeof(A));
		int N=n*n;
		for(int i=0;i<N;i++){
			A[i][N]=(s[i/n][i%n]=='w');
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int t=i*n+j;
				A[t][t]=1;
				if(i>0)A[t][t-n]=1;
				if(i<n-1)A[t][t+n]=1;
				if(j>0)A[t][t-1]=1;
				if(j<n-1)A[t][t+1]=1;
			}
		}
		int ans=slove(A,N,N);
		if(ans<0)printf("inf\n");
		else printf("%d\n",ans);
	}
	return 0;
}




