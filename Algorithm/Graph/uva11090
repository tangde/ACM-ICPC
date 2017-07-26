#include<bits/stdc++.h>
using namespace std;
const double inf=1e+20;
const double eps=1e-4;
typedef long long LL;
struct Edge{
    int from,to;
    double dist;
    Edge(int u=0,int v=0,double w=0.0):from(u),to(v),dist(w){}
};
struct SPFA{
    const static int V=60;
    const static int E=100000;
    int n,m;             //顶点数和边数
    Edge edges[E];
    vector<int>G[V];
    bool inq[V];    //是否已经永久标号
    int cnt[V];      //节点i入队次数
    double d[V];        //s到各个顶点的距离
    int mm;

    void init(int n){
    	this->n=n;
    	m=0;
    	for(int i=0;i<n;i++)G[i].clear();
    }

    void addEdge(int from,int to,int dist){
    	edges[m++]=Edge(from,to,dist);
    	mm=m;
    	G[from].push_back(m-1);   //边标号记录下来
    }

   bool negativeCycle(){
	   queue<int>Q;
	   memset(inq,0,sizeof(inq));
	   memset(cnt,0,sizeof(cnt));
	   for(int i=0;i<n;i++){d[i]=0;;Q.push(i);}
	   inq[0]=true;
	   while(!Q.empty()){
		   int u=Q.front();Q.pop();
		   inq[u]=false;
		   for(int i=0;i<G[u].size();i++){
			   Edge&e=edges[G[u][i]];
			   if(d[e.to]>d[u]+e.dist){
				   d[e.to]=d[u]+e.dist;
				   if(!inq[e.to]){
					   Q.push(e.to);
					   inq[e.to]=true;
					   if(++cnt[e.to]>n)return true;
				   }
			   }
		   }
	   }
	   return false;
   }

   void update(double diff){
	   for(int i=0;i<mm;i++){
		   edges[i].dist-=diff;
	   }
   }

   bool slove(double diff){
	   update(diff);
	   bool ans=negativeCycle();
	   update(-diff);
	   return ans;
   }

};
SPFA g;
int main(){
	int n,m,kase,u,v,w;
	scanf("%d",&kase);
	for(int i=1;i<=kase;i++){
		scanf("%d%d",&n,&m);
		g.init(n);
		double l=0.00,r=0.00;
		for(int j=0;j<m;j++){
			scanf("%d%d%d",&u,&v,&w);
			u--;v--;
			g.addEdge(u,v,double(w));
			r=max(r,double(w));
		}
		if(!g.slove(r+1)){
			printf("Case #%d: No cycle found.\n",i);
			continue;
		}
		while(r-l>eps){
			double diff=(r+l)/2;
			if(g.slove(diff))r=diff;
			else l=diff;
		}
		printf("Case #%d: %.2lf\n",i,(l+r)/2);
	}
	return 0;
}








