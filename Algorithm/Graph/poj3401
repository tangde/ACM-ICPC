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
const int maxn = 1100;

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
			Q.push(s);
			a[s]=inf;
			while(!Q.empty()){
				int x = Q.front();Q.pop();
				for(int i=0;i<(int)G[x].size();i++){
					Edge &e= edges[G[x][i]];
					if(!a[e.to]&&e.cap>e.flow){
						a[e.to]=min(a[x],e.cap-e.flow);
						p[e.to]=G[x][i];
						Q.push(e.to);
					}
				}
				if(a[t])break;
			}
			if(!a[t])break;
			for(int u=t;u!=s;u=edges[p[u]].from){
				edges[p[u]].flow += a[t];
				edges[p[u]^1].flow -= a[t];
			}
			flow+=a[t];
		}
		return flow;
	}
};
EdmondsKap g;
set<int>r,c;

int main(){
// 求最小顶点覆盖，|最小顶点覆盖|=|最大二分匹配|
	int n,k,u,v;
	while(~scanf("%d%d",&n,&k)){
	    g.init(2*n+2);  //一共2*n+2个顶点
	    r.clear();c.clear();
	    for(int i=0;i<k;i++){
		    scanf("%d%d",&u,&v);
		    r.insert(u);c.insert(n+v);
		    g.addEdge(u,n+v,inf);

	    }
	    // 源点->行
	    for(set<int>::iterator it=r.begin();it!=r.end();it++){
	    	g.addEdge(0,*it,1);
	    }
	    // 列->汇点
	    for(set<int>::iterator it=c.begin();it!=c.end();it++){
	    	    	g.addEdge(*it,2*n+1,1);
	    }
	    int ans = g.maxFlow(0,2*n+1);
	    printf("%d\n",ans);
	}
	return 0;
}













