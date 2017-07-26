// hdu3440 差分约束
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f

struct Edge{
    int from,to,dist;    //左右定点和边长度
    Edge(int u=0,int v=0,int w=0):from(u),to(v),dist(w){}
};
struct SPFA{
    const static int V=1010;
    int n,m;             //顶点数和边数
    vector<Edge>edges;
    vector<int>G[V];
    bool inq[V];    //是否已经永久标号
    int cnt[V];      //节点i入队次数
    int d[V];        //s到各个顶点的距离
    int pre[V];

    void init(int n){
    	this->n=n;
    	edges.clear();
    	for(int i=0;i<n;i++)G[i].clear();
    }

    void addEdge(int from,int to,int dist){
    	edges.push_back(Edge(from,to,dist));
    	m=edges.size();
    	G[from].push_back(m-1);   //边标号记录下来
    }

   bool spfa(int s){
	   queue<int>Q;
	   memset(inq,0,sizeof(inq));
	   memset(cnt,0,sizeof(cnt));
	   memset(d,0x3f,sizeof(d));
	   Q.push(s);
	   d[s]=0;pre[s]=s;
	   while(!Q.empty()){
		   int u=Q.front();Q.pop();
		   inq[u]=false;
		   for(int i=0;i<G[u].size();i++){
			   Edge&e=edges[G[u][i]];
			   if(d[u]<inf&&d[e.to]>d[u]+e.dist){
				   d[e.to]=d[u]+e.dist;
				   pre[e.to]=u;
				   if(!inq[e.to]){
					   Q.push(e.to);
					   inq[e.to]=true;
					   if(++cnt[e.to]>n)return false;
				   }
			   }
		   }
	   }
	   return true;
   }

}slover;
int a[1010];
map<int,int>id;
int main(){
	int T,n,D;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		scanf("%d%d",&n,&D);
		slover.init(n+1);
		id.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			id[a[i]]=i;
		}
		for(int i=2;i<=n;i++){
			slover.addEdge(i,i-1,-1);
		}
		/*
		for(int i=1;i<=n;i++){
			slover.addEdge(0,i,0);
		}
		*/
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++){
			int u=id[a[i]];
			int v=id[a[i+1]];
			if(u>v)swap(u,v);
			slover.addEdge(u,v,D);
		}
		int s=id[a[1]],t=id[a[n]];
		if(s>t)swap(s,t);
		bool ans = slover.spfa(s);
		if(!ans)printf("Case %d: -1\n",kase);
		else printf("Case %d: %d\n",kase,slover.d[t]);
	}
	return 0;
}















