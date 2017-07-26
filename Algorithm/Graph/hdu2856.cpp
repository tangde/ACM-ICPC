// LCA，hdu2856
#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w;
	Edge(int u=-1,int v=-1,int w=-1):u(u),v(v),w(w){}
};
struct LCA{
	const static int N=16;
	int n;
	int fa[1<<N],d[1<<N],cost[1<<N];
	int tolCost[1<<N][N]; // 节点i到它的2^j级最先的路径上的边权和
	int anc[1<<N][N];     // 节点i的第2^j级祖先，不存在就为-1
	vector<Edge>edges[1<<N]; // 原树的邻接表

	void init(int n){
		this->n=n;
		for(int i=0;i<n;i++)edges[i].clear();
	}

	void addEdge(int u,int v,int w){
		edges[u].push_back(Edge(u,v,w));
		edges[v].push_back(Edge(v,u,w));
	}

	void dfs(int u,int f){ // 无根树转化为有根树
		fa[u]=f;
		for(int i=0;i<edges[u].size();i++){
			Edge&e=edges[u][i];
			if(e.v!=f){
				cost[e.v]=e.w; // e.v 到e的父节点的边权值
				dfs(e.v,u);
			}
		}
	}

	int depth(int u){ // 树深度
		if(fa[u]==-1)return d[u]=0;
		if(d[u]>0)return d[u];
		return d[u]=depth(fa[u])+1;
	}

	void preprocess(){
		dfs(0,-1);
		memset(d,-1,sizeof(d));
		for(int u=0;u<n;u++)depth(u);

		for(int i=0;i<n;i++){
			anc[i][0]=fa[i];
			tolCost[i][0]=cost[i];
			for(int j=1;(1<<j)<n;j++)
				anc[i][j]=-1;
		}
		for(int j=1;(1<<j)<n;j++){
			for(int i=0;i<n;i++)if(anc[i][j-1]!=-1){
				int p=anc[i][j-1];
				anc[i][j]=anc[p][j-1];
				tolCost[i][j]=tolCost[i][j-1]+tolCost[p][j-1];
			}
		}
	}

	int query(int u,int v){
		int log,ans=0;
		if(d[u]<d[v])swap(u,v);
		for(log=1;(1<<log)<=d[u];log++);
		log--;
		int c=d[u]-d[v];
		for(int i=log;i>=0;i--)if(c&(1<<i)){
			ans+=tolCost[u][i];
			u=anc[u][i];
		}
		if(u==v)return ans;
		for(int i=log;i>=0;i--){
			if(anc[u][i]!=-1&&anc[v][i]!=-1){
				ans+=tolCost[u][i];u=anc[u][i];
				ans+=tolCost[v][i];v=anc[v][i];
			}
		}
		ans+=(cost[u]+cost[v]); // fa[u]=fa[v]是u和v的最近公共祖先
		return ans;
	}

};
LCA g;
int main(){
	int T,n,m,u,v,w;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		g.init(n);
		for(int i=0;i<n-1;i++){
			scanf("%d%d%d",&u,&v,&w);
			g.addEdge(u-1,v-1,w);
		}
		g.preprocess();
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			printf("%d\n",g.query(u-1,v-1));
		}
	}
	return 0;
}







