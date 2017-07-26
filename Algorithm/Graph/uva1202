#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define rd(a,b) (rand()%(b-a)+a)
const int maxn=510;
typedef long long LL;

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
	int h;
	char mus[110];
	char sport[110];

	void setValue(int x,char*m,char*s){
		h=x;
		strcpy(mus,m);
		strcpy(sport,s);
	}

};

Node boy[maxn],girl[maxn];

int main(){
	int n,T,x;
	char ch;
	char m[100],s[110];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int boy_cnt=0,girl_cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d %c %s %s",&x,&ch,m,s);
			if(ch=='M')
				boy[boy_cnt++].setValue(x,m,s);
			else
				girl[girl_cnt++].setValue(x,m,s);
		}
		slover.init(boy_cnt,girl_cnt);
		for(int i=0;i<boy_cnt;i++){
			for(int j=0;j<girl_cnt;j++){
				if(abs(boy[i].h-girl[j].h)>40)continue;
				if(strcmp(boy[i].mus,girl[j].mus)!=0)continue;
				if(strcmp(boy[i].sport,girl[j].sport)==0)continue;
				slover.addEdge(i,j);
			}
		}
		int ans = slover.hungary();
		printf("%d\n",n-ans);
	}
	return 0;
}






