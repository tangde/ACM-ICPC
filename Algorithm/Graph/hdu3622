#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn=100+10;
typedef long long LL;

struct Point{
    int x,y;
    Point(int a=0,int b=0):x(a),y(b){}
};
struct Graph{
    const static int V=100+10;
    int n,c;
    vector<int>G[2*V];
    bool mark[2*V];  // 标记节点
    int S[2*V];     //临时数组

    void init(int n){
        this->n=n;
        for(int i=0;i<2*n;i++)G[i].clear();
        memset(mark,0,sizeof(mark));
    }

    void addEdge(int u,int uval,int v,int vval){
        u=2*u+uval;
        v=2*v+vval;
        G[u^1].push_back(v);
        G[v^1].push_back(u);
    }

    bool dfs(int x){
        if(mark[x^1]) return false;
        if(mark[x]) return true;
        mark[x]=true;
        S[c++]=x;
        for(int v:G[x]){
            if(!dfs(v))return false;
        }
        return true;
    }

    bool twoSat(){
        for(int i=0;i<2*n;i+=2){
            if(!mark[i]&&!mark[i+1]){
                c=0;
                if(!dfs(i)){
                    while(c>0)mark[S[--c]]=false;
                    if(!dfs(i+1))return false;
                }
            }
        }
        return true;
    }

};
Graph g;
Point T[maxn][2];
int n;
const double eps=1e-4;
double dist(Point a,Point b){
    return sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
bool ok(double diff){
    g.init(n);
    for(int i=0;i<n;i++){
        for(int a=0;a<2;a++){
            for(int j=i+1;j<n;j++){
                for(int b=0;b<2;b++){
                    if(dist(T[i][a],T[j][b])<diff){
                        g.addEdge(i,a^1,j,b^1);
                    }
                }
            }
        }
    }
    return g.twoSat();
}
int main(){
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            for(int a=0;a<2;a++){
                scanf("%d%d",&T[i][a].x,&T[i][a].y);
            }
        }
        double l=0.00,r=2*17320.00;
        while(r-l>eps){
            double p=(r+l)/2;
            if(ok(p))l=p;
            else r=p;
        }
        printf("%.2lf\n",(l+r)/4);
    }
    return 0;
}

