// 1005 A New Tetris Game 
#include<bits/stdc++.h>
using namespace std;
char M[60][60];
int n,m;
bool ok(int k,int l){
	if(k+1>=n||l+1>=m) return false;
	if(M[k][l]=='1'||M[k+1][l]=='1'||M[k][l+1]=='1'||M[k+1][l+1]=='1')
		return false;
	return true;
}
int dfs(){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m-1;j++){
			if(!ok(i,j)) continue;
			M[i][j]=M[i+1][j]=M[i][j+1]=M[i+1][j+1]='1';
			if(!dfs()){
				M[i][j]=M[i+1][j]=M[i][j+1]=M[i+1][j+1]='0';
				return 1;
			}
			M[i][j]=M[i+1][j]=M[i][j+1]=M[i+1][j+1]='0';
		}
	}
	return 0;
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%s",M[i]);
		}
		if(dfs()) puts("Yes");
		else puts("No");
	}
	return 0;
}

