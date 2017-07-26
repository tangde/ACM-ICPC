//hdu1142
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long LL;
struct HeapNode{
    LL dist,u;  //顶点u距离s的距离为dist
    HeapNode(LL w=0,LL x=0):dist(w),u(x){}
    bool operator<(const HeapNode&rhs)const{
        return dist>rhs.dist;
    }
};

struct Graph{
    const static int V=1000;
    int n,m;
    int w[V][V];
    bool done[V];   //是否已经永久标号
    LL d[V];     //s到各个顶点的距离
    int pre[V];    //i的父节点

    void init(int n){
        this->n=n;
        m=0;
        memset(w,0x3f,sizeof(w));
    }

    void addEdge(int u,int v,int dist){
        w[u][v]=w[v][u]=dist;
    }

    void dijkstra(int s){
        memset(d,0x3f,sizeof(d));
        memset(done,0,sizeof(done));
        priority_queue<HeapNode>Q;
        d[s]=0;pre[s]=s;
        Q.push(HeapNode(0,s));
        while(!Q.empty()){
            HeapNode x=Q.top();Q.pop();
            int u=x.u;  // 拿最小距离的顶点编号
            if(done[u])continue;  //每个顶点出发只可以松弛一次
            done[u]=true;
            for(int v=0;v<n;v++)if(w[u][v]!=inf){
                if(d[v]>d[u]+w[u][v]){
                    d[v]=d[u]+w[u][v];
                    pre[v]=u;
                    Q.push(HeapNode(d[v],v));
                }
            }
        }
    }

    int dp[V];
    int dfs(int u){
        if(dp[u]!=-1)return dp[u];
        dp[u]=0;
        for(int v=0;v<n;v++)if(w[u][v]!=inf){
            if(d[v]<d[u])dp[u]+=dfs(v);
        }
        return dp[u];
    }

    int slove(){
        dijkstra(1);
        memset(dp,-1,sizeof(dp));
        dp[1]=1;
        for(int i=0;i<n;i++){
            dfs(i);
        }
        return dp[0];
    }

};

Graph g;
int main(){
    int n,m,u,v,w;
    while(scanf("%d",&n)&&n){
        g.init(n);
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            g.addEdge(u,v,w);
        }
        int ans=g.slove();
        printf("%d\n",ans);
    }
    return 0;
}


