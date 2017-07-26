//1011 Bomb Game,二维SG博弈
#include<bits/stdc++.h>
using namespace std;
int sg[55][55];

int SG(int a,int b){
	if(sg[a][b]>=0) return sg[a][b];
	int Hash[600]={0};
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			Hash[SG(i,b)^SG(a,j)]=1;
		}
	}
	sg[a][b]=0;
	while(Hash[sg[a][b]]) sg[a][b]++;
	return sg[a][b];
}

int main(){
	memset(sg,-1,sizeof(sg));
	for(int i=0;i<51;i++){
		sg[i][0]=sg[0][i]=i;
	}
	int n,m;
	char s[55];
	while(scanf("%d %d",&n,&m)&&n){
		int g=0;
		for(int i=0;i<n;i++){
			scanf("%s",s);
			for(int j=0;j<m;j++)if(s[j]=='#'){
				g^=SG(i,j);
			}
		}
		if(g) puts("John");
		else puts("Jack");
	}
	return 0;
}





