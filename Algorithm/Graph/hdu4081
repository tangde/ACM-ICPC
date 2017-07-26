// hdu4081
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
// O(v^2)
struct Graph{
	const static int V=1000+10;
	int n;
	double g[V][V],maxCost[V][V];
	int pre[V],vis[V];
	double dis[V];

	void init(int n){
		this->n=n;
		memset(g,0x3f,sizeof(g));
	}

	void addEdge(int u,int v,double w){
		g[u][v]=g[v][u]=w;
	}

	double prim(){
		double ans=0;
		memset(maxCost,0,sizeof(maxCost));
		dis[0]=0;pre[0]=-1;vis[0]=1;
		for(int i=1;i<n;i++){
			dis[i]=g[0][i];
			vis[i]=0;
		}
		for(int i=0;i<n-1;i++){
			int u=-1;
			double d=inf*1.0;
			for(int v=1;v<n;v++)if(!vis[v]&&dis[v]<d){
				d=dis[u=v];
			}
			if(u==-1)return -1;
			for(int v=0;v<n;v++)if(vis[v]){
				maxCost[u][v]=maxCost[v][u] =
					max(maxCost[pre[u]][v],d);
			}
			ans+=d;vis[u]=1;
			for(int v=1;v<n;v++)if(!vis[v]&&g[u][v]<dis[v]){
				dis[v]=g[u][v];
				pre[v]=u;
			}
		}
		return ans;
	}
}slover;
double P[1010],x[1010],y[1010];
int main(){
	int n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		slover.init(n);
		for(int i=0;i<n;i++){
			scanf("%lf %lf %lf",&x[i],&y[i],&P[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				slover.addEdge(i,j,sqrt((x[i]-x[j])*(x[i]-x[j])+
						(y[i]-y[j])*(y[i]-y[j])));
			}
		}
		double cost=slover.prim();
		double roate=-inf*1.0;
		for(int u=0;u<n;u++){
			for(int v=u+1;v<n;v++){
					roate=max(roate,(P[u]+P[v])/(cost-slover.maxCost[u][v]));
			}
		}
		printf("%.2lf\n",roate);
	}
	return 0;
}
















