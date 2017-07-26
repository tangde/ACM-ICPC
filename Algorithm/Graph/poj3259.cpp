//poj3259 SPFA 判负圈
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
const int maxn =600;

struct Edge{
	int from,to,dist;
	Edge(int u,int v,int d):from(u),to(v),dist(d){}
};

struct SPFA{
	int n,m;
	vector<Edge>edges;
    vector<int>G[maxn];
    int d[maxn];
	int inq[maxn];
	int cnt[maxn];
	int p[maxn];

	void init(int n){
		this->n=n;
		for(int i=0;i<n;i++)G[i].clear();
		edges.clear();
	}

	bool Beallman_Ford(int s){
		memset(d,0x3f,sizeof(d));
		memset(inq,0,sizeof(inq));
		memset(cnt,0,sizeof(cnt));
		d[s]=0;inq[s]=1;
		queue<int>Q;
		Q.push(s);

		while(!Q.empty()){
			int u=Q.front();Q.pop();
			inq[u]=0;
			for(int i=0;i<G[u].size();i++){
				Edge&e=edges[G[u][i]];
				if(d[u]<inf&&d[e.to]>d[u]+e.dist){
					d[e.to]=d[u]+e.dist;
					p[e.to]=G[u][i];
					if(!inq[e.to]){
						Q.push(e.to);inq[e.to]=1;
						if(++cnt[e.to]>n)return false;
					}
				}
			}
		}
		return true;
	}
};

SPFA g;

int main(){
	int f,n,m,w,u,v,t;
	scanf("%d",&f);
	while(f--){
		scanf("%d%d%d",&n,&m,&w);
		g.init(n+1);
		int cnt=0;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&u,&v,&t);
			g.edges.push_back(Edge(u,v,t));
			g.edges.push_back(Edge(v,u,t));
			g.G[u].push_back(cnt++);g.G[v].push_back(cnt++);
		}
		for(int i=0;i<w;i++){
			scanf("%d%d%d",&u,&v,&t);
			g.edges.push_back(Edge(u,v,-t));
            g.G[u].push_back(cnt++);
		}
		bool ans=g.Beallman_Ford(1);
		if(ans)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}












