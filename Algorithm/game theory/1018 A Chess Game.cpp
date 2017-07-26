// 1018 A Chess Game
// SG的定义
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
vector<int>G[1010];
int sg[1010];
int SG(int x){
	if(sg[x]!=-1) return sg[x];
	int Hash[1010]={0};
	for(int i=0;i<G[x].size();i++){
		int v=G[x][i];
		Hash[SG(v)]=1;
	}
	sg[x]=0;
	while(Hash[sg[x]]) sg[x]++;
	return sg[x];
}
int main(){
	int n,m,u;
	while(scanf("%d",&n)==1){
		for(int i=0;i<n;i++){
			G[i].clear();
			scanf("%d",&m);
			while(m--){
				scanf("%d",&u);
				G[i].push_back(u);
			}
		}
		memset(sg,-1,sizeof(sg));
		while(scanf("%d",&m)&&m){
			int g=0;
			while(m--){
				scanf("%d",&u);
				g^=SG(u);
			}
			if(g) puts("WIN");
			else puts("LOSE");
		}
	}
	return 0;
}




