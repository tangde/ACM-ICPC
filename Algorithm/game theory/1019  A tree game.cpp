// 1019 A tree game
// 树上删边游戏
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
vector<int>G[100100];

int SG(int u,int fa){
	int g=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==fa) continue;
		g^=(SG(v,u)+1);
	}
	return g;
}

int main(){
	int n,u,v,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++) G[i].clear();
		for(int i=0;i<n-1;i++){
			scanf("%d %d",&u,&v);
			G[u-1].push_back(v-1);
			G[v-1].push_back(u-1);
		}
		int g=SG(0,-1);
		if(g) puts("Alice");
		else puts("Bob");
	}
	return 0;
}

