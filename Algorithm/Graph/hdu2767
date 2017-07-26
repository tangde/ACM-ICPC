//uva12171
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f

struct Edge{
	int u,v;
	Edge(int x=0,int y=0):u(x),v(y){}
};
struct Graph{
	const static int V=20000+10;
	int n,dfs_clock,scc_cnt; //scc_cnt表示强连通分量编号，从1开始
	vector<int>G[V];
	int pre[V],low[V];
	int sccno[V];   //记录点i所在的强连通分量的编号
	stack<int>S;

	int indeg[V],outdeg[V];

	void init(int n){
		this->n=n;
		for(int i=0;i<n;i++)G[i].clear();
		memset(pre,0,sizeof(pre));
		memset(sccno,0,sizeof(sccno));
		dfs_clock=scc_cnt=0;
	}

	void addEdge(int u,int v){
		G[u].push_back(v);
	}

	void dfs_scc(int u) { 
		S.push(u);
	    low[u] = pre[u] = ++dfs_clock;
	    for (int v:G[u]){
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
		if(scc_cnt==1)return 0;
		memset(indeg,0,sizeof(indeg));
		memset(outdeg,0,sizeof(outdeg));
		for(int i=0;i<n;i++){
			for(int k:G[i]){
				if(sccno[i]!=sccno[k]){
					outdeg[sccno[i]]++;
					indeg[sccno[k]]++;
				}
			}
		}
		int a=0,b=0;
		for(int i=1;i<=scc_cnt;i++){
			if(!outdeg[i])a++;
			if(!indeg[i])b++;
		}
		return max(a,b);
	}
};
Graph g;

int main(){
	int kase,n,m,u,v;
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
	return 0;
}


