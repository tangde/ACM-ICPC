//poj2230
#include <iostream>
#include<stdio.h>
#include<string>
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
const int maxn = 100010;
struct Edge{
	int from,to;
	Edge(){};
	Edge(int x,int y):from(x),to(y){};
};
struct Graph{
	int n,m;
	vector<Edge>edges;
	vector<int>G[maxn];
	bool vis[maxn];

	void init(int n){
		this->n = n;
		for(int i=0;i<n;i++)G[i].clear();
		edges.clear();
		memset(vis,0,sizeof(vis));
	}

	void addEdge(int u,int v){
		edges.push_back(Edge(u,v));
		edges.push_back(Edge(v,u));
		m=edges.size();
		G[u].push_back(m-2);
		G[v].push_back(m-1);
	}

	void euler(int u){
		for(int x:G[u])if(!vis[x]){
			Edge&e=edges[x];  //取出一条没有访问的边
			vis[x]=true;    //标记访问
			euler(e.to);
			printf("%d\n",e.to+1);
		}
	}

};
Graph g;
int main(){
	int n,m,u,v;
	while(~scanf("%d%d",&n,&m)){
		g.init(n);
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			u--;v--;
			g.addEdge(u,v);
		}
		g.euler(0);
		printf("1\n");
	}
	return 0;
}


