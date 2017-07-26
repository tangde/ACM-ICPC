#include <iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<cmath>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 510;

struct Edge{ //边信息
    int from,to,dist,a,b; //左右定点和边长度
    Edge(int u,int v,int d,int x,int y):from(u),to(v),dist(d),a(x),b(y){};
};
struct HeapNode{ //最小堆的节点
    int dist,u;  //Dijkstra算法用到的优先队列节点,距离dist和顶点编号u
    bool operator<(const HeapNode&rhs)const{
	    return dist>rhs.dist;
    }
};
struct Dijkstra{
    int n,m;             //顶点数和边数
    vector<Edge>edges;   //边集
    vector<int>G[maxn];  //每邻接表
    bool done[maxn];     //是否已经永久标号
    int d[maxn];         //s到各个顶点的距离

    void init(int n){
    	this->n=n;
    	for(int i=0;i<n;i++)G[i].clear();
    	edges.clear();
    }

    void addEdge(int u,int v,int dist,int a,int b){
    	edges.push_back(Edge(u,v,dist,a,b));
    	m=edges.size();
    	G[u].push_back(m-1);   //边标号记录下来
    }

    void dijkstra(int s){
    	//每次都是取出权值最小的一条边
        priority_queue<HeapNode>Q;
        memset(d,0x3f,sizeof(d));
        d[s]=0;
        memset(done,0,sizeof(done));
        Q.push(HeapNode{0,s});
        while(!Q.empty()){
        	HeapNode x=Q.top();Q.pop();
        	int u =x.u;  // 拿最小距离的顶点编号
        	if(done[u])continue;  //每个顶点出发只可以松弛一次
        	done[u]=true;
        	for(int i=0;i<(int)G[u].size();i++){
        		Edge&e  = edges[G[u][i]];   //取出一条邻边
        		int a=e.a,b=e.b,t=e.dist,dt=0;
        		int T1=d[u]%(a+b);
                if(T1+t<=a)dt=t;
                else dt=t+(a+b)-T1;
        		if(d[e.to]>d[u]+dt){
        			d[e.to]=d[u]+dt;
        			Q.push(HeapNode{d[e.to],e.to});
        		}
        	}
        }
    }
};

Dijkstra g;

int main(){
	int n,m,s,t,a,b,dist,u,v,kase=1;
	while(~scanf("%d%d%d%d",&n,&m,&s,&t)){
		g.init(n);
		s--;t--;
		for(int i=0;i<m;i++){
			scanf("%d%d%d%d%d",&u,&v,&a,&b,&dist);
			if(a>=dist)g.addEdge(u-1,v-1,dist,a,b);
		}
		g.dijkstra(s);
		printf("Case %d: %d\n",kase++,g.d[t]);
	}

	return 0;
}




