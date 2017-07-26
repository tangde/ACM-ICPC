//poj1041 最小序列输出
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
const int maxn = 2010;
struct Edge{
	int from,to;
	Edge(){};
	Edge(int u,int v):from(u),to(v){};
};
struct Graph{
	int n;
	Edge edges[maxn];
	vector<int>G[maxn];
	int deg[maxn];        // 度
	bool vis[maxn];

	void init(){
		for(int i=0;i<maxn;i++)G[i].clear();
		memset(deg,0,sizeof(deg));
	}

	void addEdge(int u,int v,int id){
		edges[id]=Edge(u,v);
		G[u].push_back(id);
		G[v].push_back(id);
		deg[u]++;
		deg[v]++;
	}

	bool isEuler(){
		for(int i=0;i<n;i++)if(deg[i]&1){
			return false;
		}
		return true;
	}

	void euler(int u,vector<int>&ans){ //从点开始
		for(int i=0;i<(int)G[u].size();i++){
			int id=G[u][i],v;
			if(vis[id])continue;
			vis[id]=true;
			if(edges[id].from==u)v=edges[id].to;
			else v=edges[id].from;
			euler(v,ans);
			ans.push_back(id);
		}
	}

	bool cmp(vector<int>&ans1,vector<int>&ans2){
		for(int i=ans1.size()-1;i>=0;i--){
			if(ans1[i]<ans2[i])return true;
			else if(ans1[i]>ans2[i])return false;
		}
	}
	void slove(){
		for(int i=0;G[i].size();i++){
			sort(G[i].begin(),G[i].end());
		}
		int u=edges[1].from,v=edges[1].to;
		vector<int>ans1,ans2,ans;
		memset(vis,0,sizeof(vis));
		euler(u,ans1);
		memset(vis,0,sizeof(vis));
		euler(v,ans2);
		if(cmp(ans1,ans2))ans=ans1;
		else ans=ans2;
		printf("%d",ans.back());
		for(int i=ans.size()-2;i>=0;i--){
			printf(" %d",ans[i]);
		}
		printf("\n");
	}

};
Graph g;
int main(){
	int n,m,u,v;
	while(scanf("%d%d",&u,&v)&&u){
		g.init();
		scanf("%d",&m);
		n=0;
		g.addEdge(u-1,v-1,m);
		n=max(n,max(u,v));
		while(scanf("%d%d",&u,&v)&&u){
			scanf("%d",&m);
		    g.addEdge(u-1,v-1,m);
		    n=max(n,max(u,v));
		}
		g.n=n;
		bool ans=g.isEuler();
		if(!ans)printf("Round trip does not exist.\n");
		else g.slove();
	}
	return 0;
}


