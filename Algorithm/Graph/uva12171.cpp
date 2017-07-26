//uva12171
//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
const int maxn = 1000+10;

struct Edge{
	int u,v;
	Edge(int x=0,int y=0):u(x),v(y){}
};
struct Graph{
	const static int V=1000+10;

	int n,dfs_clock,bcc_cnt; //bcc_cnt计数，表示双连通分量编号，从1开始
	vector<int>G[maxn];
	vector<int>bcc[V];
	bool iscut[V];
	int pre[V],low[V];
	int bccno[V];   //记录点所在双连通分量编号，割点无意义。
	stack<Edge>S;

	int color[V];
	int ans[maxn];

	void init(int n){
		this->n=n;
		for(int i=0;i<n;i++)G[i].clear();
		memset(pre,0,sizeof(pre));
		memset(iscut,0,sizeof(iscut));
		memset(bccno,0,sizeof(bccno));
		dfs_clock=bcc_cnt=0;
	}

	void addEdge(int u,int v){
		G[u].push_back(v);
		G[v].push_back(u);
	}

	void dfs_bcc(int u, int fa) {
	    low[u] = pre[u] = ++dfs_clock;
	    int child = 0;
	    for (int i = 0; i < G[u].size(); i++) {
	        int v = G[u][i];
	        Edge e = Edge(u, v);
	        if (!pre[v]) {
	            S.push(e);
	            child++;
	            dfs_bcc(v, u);
	            low[u]= min(low[u], low[v]);
	            if (low[v] >= pre[u]) {
	                iscut[u] = true;
	                bcc[++bcc_cnt].clear(); //从下标从1开始
	                while(1) {
	                    Edge x = S.top(); S.pop();
	                    if (bccno[x.u] != bcc_cnt) {
	                    	bcc[bcc_cnt].push_back(x.u);
	                    	bccno[x.u] = bcc_cnt;
	                    }
	                    if (bccno[x.v] != bcc_cnt) {
	                    	bcc[bcc_cnt].push_back(x.v);
	                    	bccno[x.v] = bcc_cnt;
	                    }
	                    if (x.u == u && x.v == v) break;
	                }
	            }
	        } else if (pre[v] < pre[u] && v != fa) {
	            S.push(e);
	            low[u] = min(low[u], pre[v]);
	        }
	    }
	    if (fa < 0 && child == 1) iscut[u] = false;
	}

	void find_bcc(){
		for(int i=0;i<n;i++)if(!pre[i]){
			dfs_bcc(i,-1);
		}
	}

	bool isbipartite(int u,int b){
		if(!color[u])color[u]=1;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(bccno[v]!=b)continue;
			if(color[u]==color[v])return false;
			if(!color[v]){
				color[v]=3-color[u];
				if(!isbipartite(v,b))return false;
			}
		}
		return true;
	}

	int slove(){
		find_bcc();
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=bcc_cnt;i++){
			for(int j=0;j<bcc[i].size();j++)bccno[bcc[i][j]]=i;
			memset(color,0,sizeof(color));
			if(!isbipartite(bcc[i][0],i)){
				for(int j=0;j<bcc[i].size();j++)ans[bcc[i][j]]=1;
			}
		}
		int cnt=0;
		for(int i=0;i<n;i++)if(!ans[i]){
			cnt++;
		}
		return cnt;
	}
};
Graph g;

int A[maxn][maxn];
int main(){
	int n,m,u,v;
	while(scanf("%d%d",&n,&m)&&n){
		g.init(n);
		memset(A,0,sizeof(A));
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			u--;v--;
			A[u][v]=A[v][u]=1;
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++)if(!A[i][j]){
				g.addEdge(i,j);
			}
		}
		int ans=g.slove();
		printf("%d\n",ans);
	}
	return 0;
}

