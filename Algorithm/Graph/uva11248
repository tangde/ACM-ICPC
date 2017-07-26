#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
#define inf 0x3f3f3f3f

struct Edge{
	int from,to,cap,flow;
	Edge(int u=0,int v=0,int c=0,int f=0):from(u),to(v),cap(c),flow(f){}
};
struct Dinic{
	const static int V=800;
	const static int E=30000;
	int n,m,s,t;
	Edge edges[E];    //边
	vector<int>G[V];
	int d[V];
	int vis[V];
	int cur[V];    //当前弧下标(当前弧优化)

	int C;
	int now_flow;

	void init(int n){
		this->n=n;
		m=0;
		for(int i=0;i<n;i++)G[i].clear();
	}

	void addEdge(int from,int to,int cap){
		edges[m++]=Edge(from,to,cap,0);
		edges[m++]=Edge(to,from,0,0);
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
    //BFS构造层次图
	bool bfs(){
		memset(vis,0,sizeof(vis));
		queue<int>Q;
		Q.push(s);d[s]=0;vis[s]=1;
		while(!Q.empty()){
			int x=Q.front();Q.pop();
			for(int i=0;i<(int)G[x].size();i++){
				Edge&e=edges[G[x][i]];
				if(!vis[e.to]&&e.cap>e.flow){ //只考虑残留网路中的弧
					vis[e.to]=1;
					d[e.to]=d[x]+1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}

    // DFS进行多路增广
	int dfs(int x,int a){
		if(x==t||a==0)return a;
		int flow=0,f;
		// 当前弧优化
		for(int &i=cur[x];i<(int)G[x].size();i++){
			Edge&e=edges[G[x][i]];
			if(d[e.to]==d[x]+1&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
				e.flow+=f;
				ff[G[x][i]]+=f;
				ff[G[x][i]]-=f;
				edges[G[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
			//a==0终止，提高效率避免无用搜索。
				if(a==0)break;
			}
		}
		return flow;
	}

	int maxFlow(int s,int t){
		this->s=s;this->t=t;
		int flow=now_flow;
		while(bfs()){
			memset(cur,0,sizeof(cur));
			flow+=dfs(s,inf);
			if(flow>=C)break;
		}
		return flow;
   }

	int ff[E];
	void slove(int C,int n,int &kase){
		now_flow=0;
		this->C=C;
		now_flow=maxFlow(0,n-1);
		if(now_flow>=C){printf("Case %d: possible\n",kase++);return;}

		vector<PII>ans;
		for(int i=0;i<m;i+=2)if(edges[i].cap==edges[i].flow){
			edges[i].cap=inf*2;
			memset(ff,0,sizeof(ff));
			int l=maxFlow(s,t);
			if(l>=C)ans.push_back(PII(edges[i].from,edges[i].to));
			for(int j=0;j<m;j++)if(ff[j]){
				edges[j].flow-=ff[j];
			}
			edges[i].cap=edges[i].flow;
		}
		if(ans.size()==0){printf("Case %d: not possible\n",kase++);return;}
		sort(ans.begin(),ans.end());
		printf("Case %d: possible option:",kase++);
		for(int i=0;i<ans.size();i++){
			PII &x=ans[i];
			if(i)printf(",");
			printf("(%d,%d)",x.first+1,x.second+1);
		}
		printf("\n");
	}

};

Dinic g;
int main(){
	int n,m,c,u,v,f,kase=1;
	while(scanf("%d%d%d",&n,&m,&c)&&n){
		g.init(n);
		while(m--){
			scanf("%d%d%d",&u,&v,&f);
			u--;v--;
			g.addEdge(u,v,f);
		}

		g.slove(c,n,kase);
	}
	return 0;
}










