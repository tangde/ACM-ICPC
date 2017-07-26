// uva1082 高斯消元法
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
typedef double Matrix[maxn][maxn];
const double eps=1e-6;

void gauss_jordan(Matrix A,int n){
	int i,j,k,r;
	for(i=0;i<n;i++){
		r=i;
		for(j=i+1;j<n;j++){
			// 选一行r并与第i行交换
			if(abs(A[j][i])>abs(A[r][i]))r=j;
		}
		if(abs(A[r][i])<eps)continue; // 放弃这一行，直接处理下一行
		if(r!=i)for(j=0;j<=n;j++)swap(A[i][j],A[r][j]);

		// 与除了第i行外的其它行进行消元
		for(k=0;k<n;k++)if(k!=i){
			for(j=n;j>=i;j--)A[k][j]-=A[k][i]/A[i][i]*A[i][j];
		}
	}
}

vector<int>pre[maxn];
int d[maxn],inf[maxn];
Matrix A;
int main(){
	int n,q,u,v,kase=0;
	while(scanf("%d",&n)&&n){
		memset(d,0,sizeof(d));
		for(int i=0;i<n;i++)pre[i].clear();
		while(scanf("%d%d",&u,&v)&&u){
			u--;v--;
			pre[v].push_back(u);
			d[u]++;
		}
		memset(A,0,sizeof(A));
		// 建立方程
		for(int i=0;i<n;i++){
			A[i][i]=1;
			for(int j=0;j<pre[i].size();j++){
				A[i][pre[i][j]]-=1.0/d[pre[i][j]];
			}
			if(i==0)A[i][n]=1;
		}
		// 消元
		gauss_jordan(A,n);
		memset(inf,0,sizeof(inf));
		// 标记无解的无穷量
		for(int i=n-1;i>=0;i--){
			if(abs(A[i][i])<eps&&abs(A[i][n])>eps)inf[i]=1;
			// 与无穷变量相关的变量也是无穷的
			for(int j=i+1;j<n;j++){
				if(abs(A[i][j])>eps&&inf[j])inf[i]=1;
			}
		}
		scanf("%d",&q);
		printf("Case #%d:\n",++kase);
		while(q--){
			scanf("%d",&u);
			u--;
			if(inf[u])printf("infinity\n");
			else printf("%.3lf\n",abs(A[u][u])<eps? 0.0:A[u][n]/A[u][u]);
		}
	}
	return 0;
}






