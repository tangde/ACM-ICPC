#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn=510;

struct Hungry{
	const static int V=510;
    int nx,ny;          //左右顶点个数
    int g[V][V];  //邻接矩阵
    int link[V];     //记录匹配信息
    int used[V];     //记录右边是否以标记

    void init(int nx,int ny){
    	this->nx=nx;this->ny=ny;
    	memset(g,0,sizeof(g));
    }

    void addEdge(int u,int v){
    	g[u][v]=1;
    }

    bool dfs(int u){
        for(int v=0;v<ny;v++){
            if(g[u][v]&&!used[v]){
                used[v]=true;
                if(link[v]==-1||dfs(link[v])){
                    link[v]=u;
                    return true;
                }
            }
        }
        return false;
    }

    int hungary(){
        int res=0;
        memset(link,-1,sizeof(link));
        for(int u=0;u<nx;u++){
            memset(used,0,sizeof(used));
            if(dfs(u))res++;
        }
        return res;
    }
};

Hungry slover;

struct Node{
	int s,x1,y1,x2,y2;
	void setValue(int s,int a,int b,int c,int d){
		this->s=s;
		x1=a;y1=b;
		x2=c,y2=d;
	}
};

int contoint(char*s){
	int a,b;
	sscanf(s,"%d:%d",&a,&b);
	return 60*a+b;
}

Node peo[maxn];
bool vis[maxn][maxn];

int nextTime(Node&p,Node&q){
	return p.s+(int)(abs(p.x1-p.x2)+abs(p.y1-p.y2)+abs(p.x2-q.x1)+abs(p.y2-q.y1));
}

void dfs(int u,int &n){
	for(int v=u+1;v<n;v++){
		if(!vis[u][v]&&nextTime(peo[u],peo[v])<peo[v].s){
			vis[u][v]=1;
			slover.addEdge(u,v);
			dfs(v,n);
		}
	}
}

void handle(int n){
	slover.init(n,n);
	memset(vis,0,sizeof(vis));
	for(int u=0;u<n;u++){
		dfs(u,n);
	}
}

int main(){
	char s[6];
	int n,m,x1,y1,x2,y2;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%s %d%d%d%d",s,&x1,&y1,&x2,&y2);
			peo[i].setValue(contoint(s),x1,y1,x2,y2);
		}
		handle(m);
		int ans=m-slover.hungary();
		printf("%d\n",ans);
	}
	return 0;
}






