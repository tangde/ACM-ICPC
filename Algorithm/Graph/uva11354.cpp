// uva11358 最小瓶颈路
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f

struct Edge{
	int u,v,w;
	Edge(int x=0,int y=0,int dist=0):u(x),v(y),w(dist){};
	bool operator<(const Edge&rsh){
		return w<rsh.w;
	}
};
struct Slover{
	const static int N=16;
	int n;
	vector<Edge>edges;  // 图的边集
	vector<Edge>G[1<<N]; // 生成树的邻接表
	int fa[1<<N],d[1<<N],cost[1<<N];
	int maxCost[1<<N][N];
	int anc[1<<N][N];

	void init(int n){
		this->n=n;
		for(int i=0;i<n;i++)G[i].clear();
		edges.clear();
	}

	void addEdge(int u,int v,int w){
		edges.push_back(Edge(u,v,w));
		edges.push_back(Edge(v,u,w));
	}

	int getFather(int u){return fa[u]==-1?u:fa[u]=getFather(fa[u]);}

	void kruskal(){
		int cc=n;
		sort(edges.begin(),edges.end());
		memset(fa,-1,sizeof(fa));
		for(int i=0;i<edges.size();i++){
			Edge &e=edges[i];
			int u=getFather(e.u);
			int v=getFather(e.v);
			if(u!=v){
				fa[u]=v;
				G[e.u].push_back(Edge(e.u,e.v,e.w));
				G[e.v].push_back(Edge(e.v,e.u,e.w));
				if(--cc==1)return; //图已连通
			}
		}
	}

	void dfs(int u,int f,int depth){ // 无根树转化为有根树
		fa[u]=f;d[u]=depth;
		for(int i=0;i<G[u].size();i++){
			Edge&e=G[u][i];
			if(e.v!=f){
				cost[e.v]=e.w; // e.v 到e的父节点的边权值
				dfs(e.v,u,depth+1);
			}
		}
	}

	void preprocess(){
		kruskal();
		memset(d,-1,sizeof(d));
		//memset(fa,-1,sizeof(fa));
		for(int i=0;i<n;i++)if(d[i]<0){
			dfs(i,-1,0);
		}
		for(int i=0;i<n;i++){
			anc[i][0]=fa[i];
			maxCost[i][0]=cost[i];
			for(int j=1;(1<<j)<n;j++)
				anc[i][j]=-1;
		}
		for(int j=1;(1<<j)<n;j++){
			for(int i=0;i<n;i++)if(anc[i][j-1]!=-1){
				int p=anc[i][j-1];
				anc[i][j]=anc[p][j-1];
				maxCost[i][j]=max(maxCost[i][j-1],maxCost[p][j-1]);
			}
		}
	}

	int query(int u,int v){
		int log,ans=-inf;
		if(d[u]<d[v])swap(u,v);
		for(log=1;(1<<log)<=d[u];log++);
		log--;
		int c=d[u]-d[v];
		for(int i=log;i>=0;i--)if(c&(1<<i)){
			ans=max(ans,maxCost[u][i]);
			u=anc[u][i];
		}
		if(u==v)return ans;
		for(int i=log;i>=0;i--){
			if(anc[u][i]!=-1&&anc[u][i]!=anc[v][i]){
				ans=max(ans,maxCost[u][i]);u=anc[u][i];
				ans=max(ans,maxCost[v][i]);v=anc[v][i];
			}
		}
		ans=max(ans,cost[u]);
		ans=max(ans,cost[v]); // fa[u]=fa[v]是u和v的最近公共祖先
		return ans;
	}

}slover;
int main(){
	int n,m,u,v,w,q,kase=1;
	while(~scanf("%d%d",&n,&m)){
		slover.init(n);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&u,&v,&w);
			slover.addEdge(u-1,v-1,w);
		}
		slover.preprocess();
		if(kase++>1)putchar('\n');
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			scanf("%d%d",&u,&v);
			printf("%d\n",slover.query(u-1,v-1));
		}
	}
	return 0;
}

