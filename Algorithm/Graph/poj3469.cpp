//poj3469 最小割建模
#include<cstdio>
#include<set>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn =20000+10;

struct Edge{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
struct Dinic{
	int n,m,s,t;
	vector<Edge>edges;
	vector<int>G[maxn];
	int d[maxn];    // 保存层次
	bool vis[maxn];  // bfs使用
	int cur[maxn];    // 当前弧下标

	void init(int n){
		for(int i=0;i<n;i++)G[i].clear();
		edges.clear();
	}

	void addEdge(int from,int to,int cap){
		edges.push_back(Edge(from,to,cap,0));
		edges.push_back(Edge(to,from,0,0));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}

	bool bfs(){
		memset(vis,0,sizeof(vis));
		queue<int>Q;
		Q.push(s);
		d[s]=0;
		vis[s]=1;
		while(!Q.empty()){
			int x=Q.front();Q.pop();
			for(int i=0;i<G[x].size();i++){
				Edge&e=edges[G[x][i]];
				if(!vis[e.to]&&e.cap>e.flow){
					vis[e.to]=1;
					d[e.to]=d[x]+1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}

	int dfs(int x,int a){
		if(x==t||a==0)return a;
		int flow=0,f;
		for(int&i=cur[x];i<G[x].size();i++){
			Edge&e=edges[G[x][i]];
			if(d[e.to]>d[x]&&(f=dfs(e.to,min(a,e.cap-e.flow)))){
				e.flow+=f;
				edges[G[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
				if(a==0)break;
			}
		}
		return flow;
	}

	int maxFlow(int s,int t){
		this->s;this->t=t;
		int flow=0;
		while(bfs()){
			memset(cur,0,sizeof(cur));
			flow+=dfs(s,inf);
		}
		return flow;
   }

};
Dinic g;

int main(){
	int n,m,a,b,w;
	while(~scanf("%d%d",&n,&m)){
		g.init(n+2);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a,&b);
			g.addEdge(i,n+1,a);
			g.addEdge(0,i,b);
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&w);
			g.addEdge(a,b,w);
			g.addEdge(b,a,w);
		}
		int ans=g.maxFlow(0,n+1);
		printf("%d\n",ans);
	}
	return 0;
}






