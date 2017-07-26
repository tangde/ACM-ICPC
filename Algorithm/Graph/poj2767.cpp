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
const int maxn = 20010;
struct Edge{
	int u,v;
	Edge(int a,int b):u(a),v(b){}
};
struct Graph{
//有向图强连通分量
// 算法结果保存在sccno数组中
	int n,dfs_clock,scc_cnt; //scc_cnt表示强连通分量编号，从1开始
	vector<int>G[maxn];
	int indegree[maxn];
	int outdegree[maxn];
	int low[maxn];   // u及其后代可以追溯到的最早的pre值
	int pre[maxn];
	int sccno[maxn];   //记录点i所在的强连通分量的编号
	stack<int>S;

	void init(int n){
		this->n=n;
		for(int i=0;i<n;i++)G[i].clear();
		memset(pre,0,sizeof(pre));
		memset(low,0,sizeof(low));
		memset(sccno,0,sizeof(sccno));
		memset(outdegree,0,sizeof(outdegree));
		memset(indegree,0,sizeof(indegree));
		dfs_clock=scc_cnt=0;
	}

	// 使用邻接矩阵过滤了重边
	void addEdge(int u,int v){
		G[u].push_back(v);
	}

	void dfs_scc(int u) {
		S.push(u);
	    low[u] = pre[u] = ++dfs_clock;
	    for (int i = 0;i<G[u].size(); i++){
	    	int v=G[u][i];
	        if (!pre[v]) {
	            dfs_scc(v);
	            low[u]=min(low[u],low[v]);
	        }
	        else if (!sccno[v]) {
	            low[u] = min(low[u], pre[v]);
	        }
	    }
	    if(low[u]==pre[u]){
	    	scc_cnt++;
	    	for(;;){
	    		int x=S.top();S.pop();
	    		sccno[x]=scc_cnt;
	    		if(x==u)break;
	    	}
	    }
	}

	void find_scc(){
		for(int i=0;i<n;i++)if(!pre[i]){
			dfs_scc(i);
		}
	}

	int slove(){
		find_scc();
		if(scc_cnt==1)return 0; //原图强连通
		for(int i=0;i<n;i++){
			for(int j=0;j<G[i].size();j++){
				int k=G[i][j];
				if(sccno[i]!=sccno[k]){
					indegree[sccno[k]]++;
					outdegree[sccno[i]]++;
				}
			}
		}
		int a=0,b=0;
		for(int i=1;i<=scc_cnt;i++){
			if(!indegree[i])a++;
			if(!outdegree[i])b++;
		}
		return max(a,b);
	}
};
Graph g;

int main(){
	int n,m,u,v,kase;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d%d",&n,&m);
		g.init(n);
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			u--;v--;
			g.addEdge(u,v);
		}
		int ans=g.slove();
		printf("%d\n",ans);

	}
	return true;
}


