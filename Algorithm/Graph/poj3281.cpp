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
const int maxn = 500;

struct Edge{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
struct EdmondsKap{
	int n,m;
	vector<Edge>edges;
	vector<int>G[maxn];
	int a[maxn];
	int p[maxn];

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

	int maxFlow(int s,int t){
		int flow=0;
		for(;;){
			memset(a,0,sizeof(a));
			queue<int>Q;
			a[s]=inf;
			Q.push(s);
			while(!Q.empty()){
				int u=Q.front();Q.pop();
				for(int i=0;i<(int)G[u].size();i++){
					Edge&e=edges[G[u][i]];
					if(!a[e.to]&&e.cap>e.flow){
						p[e.to]=G[u][i];
						a[e.to]=min(a[u],e.cap-e.flow);
						Q.push(e.to);
					}
				}
				if(a[t])break;
			}
			if(!a[t])break;
			flow+=a[t];
			for(int u=t;u!=s;u=edges[p[u]].from){
				edges[p[u]].flow+=a[t];
				edges[p[u]^1].flow-=a[t];
			}
		}
		return flow;
	}


};
EdmondsKap g;

int main(){
	int n,f,d,x,n1,n2;
	while(scanf("%d%d%d",&n,&f,&d)==3){
		int m=f+2*n+d+2;
		g.init(m);
		for(int i=0;i<n;i++){
			scanf("%d%d",&n1,&n2);
			while(n1--){
				scanf("%d",&x);
				g.addEdge(x-1,f+i,1);
			}
			while(n2--){
				scanf("%d",&x);
				g.addEdge(f+n+i,f+2*n+x-1,1);
			}
		}
		for(int i=0;i<f;i++)g.addEdge(m-2,i,1);
		for(int i=f;i<f+n;i++)g.addEdge(i,i+n,1);
		for(int i=f+2*n;i<m-2;i++)g.addEdge(i,m-1,1);
		int ans =g.maxFlow(m-2,m-1);
		printf("%d\n",ans);
	}
	return 0;
}





