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
const int maxn = 12;
const int MAX_SIZE=21000;

struct Point{
	int x,y;
	Point(int a,int b):x(a),y(b){}
};

vector<Point>peo,doors;
char filed[maxn][maxn];
int vis[maxn][maxn];
int dist[maxn][maxn][maxn][maxn];
int dir[4][2]={{-1,0},{1,0,},{0,1},{0,-1}};

bool bfs(int n,int m){
	memset(dist,-1,sizeof(dist));
	for(int i=0;i<(int)doors.size();i++){
		int x1=doors[i].x,y1=doors[i].y;
		dist[x1][y1][x1][y1]=0;
		queue<Point>Q;
		Q.push(doors[i]);
		while(!Q.empty()){
			Point door=Q.front();Q.pop();
			int x=door.x,y=door.y;
			for(int k=0;k<4;k++){
				int dx=x+dir[k][0];
				int dy=y+dir[k][1];
				if(dx<0||dx>=n||dy<0||dy>=m)continue;
				if(filed[dx][dy]!='.'||dist[x1][y1][dx][dy]>=0)continue;
				dist[x1][y1][dx][dy]=dist[x1][y1][x][y]+1;
				Q.push(Point(dx,dy));
			}
		}
	}
}

struct Edge{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
struct EdmondsKap{
	int n,m;
	vector<Edge>edges;
	vector<int>G[MAX_SIZE];
	int a[MAX_SIZE];
	int p[MAX_SIZE];

	void init(){
		for(int i=0;i<MAX_SIZE;i++)G[i].clear();
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
void update(int T,EdmondsKap&g){
		set<int>pp;
		for(int i=0;i<(int)peo.size();i++){
			int x1=peo[i].x,y1=peo[i].y;
			int u =12*x1+y1;   //人顶点
			for(int j=0;j<(int)doors.size();j++){
				int dx=doors[j].x,dy=doors[j].y;
				int k=dist[dx][dy][x1][y1];
				if(k>0&&k<=T){
				     int v =30*30*dx+30*dy+T+200; //组合体顶点
				     pp.insert(v);
			         g.addEdge(u,v,1);
			   }
			}
		}

		for(set<int>::iterator it=pp.begin();it!=pp.end();it++){
			g.addEdge(*it,20999,1);
		}
}


int main(){
	int m,n,kase;
	scanf("%d",&kase);
	while(kase--){
		peo.clear();doors.clear();
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%s",filed[i]);
			for(int j=0;j<m;j++){
				if(filed[i][j]=='.')peo.push_back(Point(i,j));
				if(filed[i][j]=='D')doors.push_back(Point(i,j));
			}
		}
		bfs(n,m);
		g.init();
		int p=peo.size();
		for(int i=0;i<p;i++){
			int x=peo[i].x,y=peo[i].y;
			int u=12*x+y;
			g.addEdge(199,u,1);
		}
		int ans=0,T=1;
		for(;T<n*m;T++){
			update(T,g);
			ans+=g.maxFlow(199,20999);
			if(ans==p)break;
		}
		if(ans<p)printf("impossible\n");
		else printf("%d\n",T);
	}
	return 0;
}











