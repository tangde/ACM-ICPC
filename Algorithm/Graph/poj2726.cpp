// poj2767 有向图强连通分量，矩阵会爆内存。
#include <iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<string.h>
#include<cmath>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 2010;
struct Edge{
	int u,v;
	Edge(int a,int b):u(a),v(b){}
};
struct Graph{
	int n,c;
	vector<int>G[2*maxn];
	bool mark[2*maxn];
	int S[2*maxn];

	void init(int n){
		this->n=n;
		for(int i=0;i<2*n;i++)G[i].clear();
		memset(mark,0,sizeof(mark));
	}

	void addEdge(int u,int uval,int v,int vval){
		u=2*u+uval;
		v=2*v+vval;
		G[u^1].push_back(v);
		G[v^1].push_back(u);
	}

	bool dfs(int x){
		if(mark[x^1]) return false;
		if(mark[x]) return true;
		mark[x]=true;
		S[c++]=x;
		for(int i=0;i<G[x].size();i++){
			if(!dfs(G[x][i]))return false;
		}
		return true;
	}

	bool slove(){
		for(int i=0;i<2*n;i+=2){
			if(!mark[i]&&!mark[i+1]){
				c=0;
				if(!dfs(i)){
					while(c>0)mark[S[--c]]=false;
					if(!dfs(i+1))return false;
				}
			}
		}
		return true;
	}

};
Graph g;
int T[maxn][2];

bool test(int n,int diff){
	g.init(n);
	for(int i=0;i<n;i++)
		for(int a=0;a<2;a++)
			for(int j=i+1;j<n;j++)
				for(int b=0;b<2;b++)
					if(abs(T[i][a]-T[j][b])<diff){
						g.addEdge(i,a^1,j,b^1);
					}
	return g.slove();
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		int R=0,L=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<2;j++){
			scanf("%d",&T[i][j]);
			R=max(T[i][j],R);
		}
		while(L<R){
			int mid=L+(R-L+1)/2;
			if(test(n,mid))L=mid;
			else R=mid-1;
		}
		printf("%d\n",R);
	}
	return 0;
}


