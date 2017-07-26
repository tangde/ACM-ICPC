//hdu1504 二分图建模，匈牙利算法
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
const int maxn = 100;

struct Point{
	int x,y;
	Point(int a,int b):x(a),y(b){}
	bool operator==(const Point&rsh){
		return x==rsh.x&&y==rsh.y;
	}
};
int g[maxn][maxn];   //关系图
int link[maxn];
bool used[maxn];
int uN,vN;
char m[5][5];

bool dfs(int u){
	for(int i=0;i<vN;i++){
		if(g[u][i]&&!used[i]){
			used[i]=true;
			if(link[i]==-1||dfs(link[i])){
				link[i]=u;
				return true;
			}
		}
	}
	return false;
}

int match(){
	int ans=0;
	memset(link,-1,sizeof(link));
	for(int i=0;i<uN;i++){
		memset(used,0,sizeof(used));
		if(dfs(i))ans++;
	}
	return ans;
}

vector<Point>U[maxn],V[maxn];

int main(){
	int n;
	while(scanf("%d",&n)&&n){
		for(int i=0;i<n;i++)scanf("%s",m[i]);

		uN=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(m[i][j]=='X')continue;
				U[uN].clear();
				while(j<n&&m[i][j]=='.')U[uN].push_back(Point(i,j++));
				uN++;
			}
		}

		vN=0;
		for(int j=0;j<n;j++){
			for(int i=0;i<n;i++){
				if(m[i][j]=='X')continue;
				V[vN].clear();
				while(i<n&&m[i][j]=='.')V[vN].push_back(Point(i++,j));
				vN++;
			}
		}
		memset(g,0,sizeof(g));
		for(int i=0;i<uN;i++){
			for(int j=0;j<vN;j++){
				int flag=0;
				for(int k=0;k<U[i].size();k++){
					if(flag)break;
					for(int h=0;h<V[j].size();h++)
						if(U[i][k]==V[j][h]){
							g[i][j]=1;
							flag=true;
							break;
						}
				}
			}
		}
		int ans=match();
		printf("%d\n",ans);
	}
	return 0;
}













