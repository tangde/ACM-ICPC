//uva1658 最小费用流建模，拆分顶点
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
const int maxn = 2000+10;

struct Edge{
	int from,to,cap,flow,cost;
	Edge(int u,int v,int c,int f,int w):from(u),to(v),cap(c),flow(f),cost(w){}
};

struct MCF{
	int n,m;
	vector<Edge>edges;
	vector<int>G[maxn];
	int d[maxn];
	int p[maxn];
	int a[maxn];
	int inq[maxn];

	void init(int n){
		for(int i=0;i<n;i++)G[i].clear();
		edges.clear();
	}

	void addEdge(int from,int to,int cap,int cost){
		edges.push_back(Edge(from,to,cap,0,cost));
		edges.push_back(Edge(to,from,0,0,-cost));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}

	bool BellmanFord(int s,int t,int limit_flow,int &flow,int&cost){
		memset(d,0x3f,sizeof(d));
		memset(inq,0,sizeof(inq));
		d[s]=0;inq[s]=1;a[s]=inf;
		queue<int>Q;
		Q.push(s);
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			inq[u]=0;
			for(int i=0;i<(int)G[u].size();i++){
				Edge &e=edges[G[u][i]];
				if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
					d[e.to]=d[u]+e.cost;
					a[e.to]=min(a[u],e.cap-e.flow);
					p[e.to]=G[u][i];
					if(!inq[e.to]){Q.push(e.to);inq[e.to]=1;}
				}
			}
		}
		if(d[t]==inf)return false;
		if(flow+a[t]>limit_flow)a[t]=limit_flow-flow;
		cost+=d[t]*a[t];
		flow+=a[t];
		for(int u=t;u!=s;u=edges[p[u]].from){
			edges[p[u]].flow += a[t];
			edges[p[u]^1].flow -=a[t];
		}
		return true;
	}

	int MinCostFlow(int s,int t,int limit_flow){
		int cost=0,flow=0;
	    while(BellmanFord(s,t,limit_flow,flow,cost)&&flow!=limit_flow);
	    return cost;
	}
};
MCF g;

int main(){
	int n,m,u,v,w;
	while(~scanf("%d%d",&n,&m)){
		g.init(2*n);
		for(int i=2;i<=n-1;i++){   //节点拆分
			g.addEdge(i,i+n-1,1,0);
		}
		while(m--){
			scanf("%d%d%d",&u,&v,&w);
			if(u==1)g.addEdge(1,v,1,w);  // 源点->其它节点
			else if(u==n)continue;
			else g.addEdge(u+n-1,v,1,w); // 使用拆分节点
		}
		int ans=g.MinCostFlow(1,n,2);
		printf("%d\n",ans);
	}
	return 0;
}










