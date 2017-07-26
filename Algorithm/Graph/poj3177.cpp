// poj3177，边-双联通分量
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
const int maxn = 5010;
struct Edge{
	int u,v;
	Edge(int a,int b):u(a),v(b){}
};
struct Graph{
	int n,dfs_clock,bcc_cnt; //bcc_cnt表示边-双连通分量编号，从1开始
	bool g[maxn][maxn];      // 邻接矩阵
	bool isbrige[maxn][maxn]; //标记是否为桥
	int pre[maxn];
	int bccno[maxn];   //记录点所在边-双连通分量编号

	int degree[maxn];

	void init(int n){
		this->n=n;
		memset(g,0,sizeof(g));
		memset(pre,0,sizeof(pre));
		memset(isbrige,0,sizeof(isbrige));
		memset(bccno,0,sizeof(bccno));
		dfs_clock=bcc_cnt=0;
	}
	
	// 使用邻接矩阵过滤了重边
	void addEdge(int u,int v){
		g[u][v]=g[v][u]=1;
	}

	// 先标记桥
	int dfs_ebcc(int u, int fa) {
	    int lowu = pre[u] = ++dfs_clock;
	    for (int v = 0; v < n; v++)if(g[u][v]){
	        if (!pre[v]) {
	            int lowv = dfs_ebcc(v, u);
	            lowu = min(lowu, lowv);
	            if (lowv>pre[u]){
	            	isbrige[u][v]=isbrige[v][u]=true;
	            }
	        }
	        else if (pre[v] < pre[u] && v != fa) {
	            lowu = min(lowu, pre[v]);
	        }
	    }
	    return lowu;
	}

	// 给边连通分量标号
	void dfs_label(int u){
		bccno[u]=bcc_cnt;
		for(int v=0;v<n;v++){
			if(g[u][v]&&!isbrige[u][v]&&!bccno[v]){
				dfs_label(v);
			}
		}
	}

	void find_ebcc(){
		// 先标记出桥
		for(int i=0;i<n;i++)if(!pre[i]){
			dfs_ebcc(i,-1);
		}
		//再标记边-双连通分量
		for(int i=0;i<n;i++)if(!bccno[i]){
			++bcc_cnt;
			dfs_label(i);
		}
	}

	int slove(){
		find_ebcc();
		memset(degree,0,sizeof(degree));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)if(g[i][j]){
				if(bccno[i]!=bccno[j])degree[bccno[j]]++;
			}
		}
		int ans=0;
		for(int i=1;i<=bcc_cnt;i++){
			if(degree[i]==1)ans++;
		}
		return (ans+1)/2;
	}
};
Graph g;

int main(){
	int n,m,u,v;
	while(~scanf("%d%d",&n,&m)){
		g.init(n);
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			if(u>v)swap(u,v);
			u--;v--;
			g.addEdge(u,v);
		}
		int ans=g.slove();
		printf("%d\n",ans);

	}
	return true;
}


