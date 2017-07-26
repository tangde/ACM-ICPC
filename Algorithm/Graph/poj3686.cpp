//poj3686，最大权完备匹配KM算法
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
const int maxn = 2510;

struct KM{
	int nx,ny;             //左右顶点个数都为n
	int w[maxn][maxn];     //权值矩阵
    int Lx[maxn],Ly[maxn]; //可行顶标函数
    int slack[maxn];       //记录T中每个元素松弛量
    bool S[maxn],T[maxn];  //记录左右节点是否标记
    int link[maxn];  //link[j]=i,表示右节点j与左节点i匹配，记录匹配信息

    bool dfs(int u){
    	S[u]=true;
    	for(int v=0;v<ny;v++)if(!T[v]){
    		if(Lx[u]+Ly[v]==w[u][v]){
    			T[v]=true;
    			if(link[v]==-1||dfs(link[v])){
    				link[v]=u;
    				return true;
    			}
    		}
    		else slack[v]=min(slack[v],Lx[u]+Ly[v]-w[u][v]);
    	}
    	return false;
    }

    void update(){
    	int a=inf;    //改变量
    	for(int i=0;i<ny;i++)if(!T[i]){
    		a=min(a,slack[i]);
    	}
    	for(int i=0;i<nx;i++){
    		if(S[i])Lx[i]-=a;
    	}
    	for(int i=0;i<ny;i++){
    	 	if(T[i])Ly[i]+=a;
    	    else slack[i]-=a;
    	}
    }

    void km(){
    	memset(Ly,0,sizeof(Ly));
    	memset(link,-1,sizeof(link));
    	// 初始化Lx为最大，Ly为0
    	for(int i=0;i<nx;i++){
    		Lx[i]=-inf;
    		for(int j=0;j<ny;j++){
    			Lx[i]=max(Lx[i],w[i][j]);
    		}
    	}
    	for(int i=0;i<nx;i++){
    		memset(slack,0x3f,sizeof(slack));
    		for(;;){
    			memset(T,0,sizeof(T));
    			memset(S,0,sizeof(S));
    			if(dfs(i))break;
    			else update();
    		}
    	}
    }
};
KM g;

int z[51][51];

int main(){
    int n,m,kase;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				scanf("%d",&z[i][j]);
		}
		g.nx=n;g.ny=m*n;
		for(int i=0;i<g.nx;i++){
			for(int j=0;j<g.ny;j++){
				for(int k=0;k<g.nx;k++)
					g.w[i][n*j+k]=-z[i][j]*(k+1);
			}
		}
        g.km();
        int ans=0;
        for(int i=0;i<g.ny;i++){
	       if(g.link[i]!=-1)
		       ans+=g.w[g.link[i]][i];
	    }
	    printf("%.6f\n",-ans*1.0/n);
     }
	return 0;
}







