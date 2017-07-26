//poj1556
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<cmath>
#define inf 0x3f3f3f3f
using namespace std;
const double eps=1e-8;
int dcmp(double x){
	if(fabs(x)<eps)return 0;
	else return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y){}
};
typedef Point Vector;        // Vector是Point的别名，表示向量
// 向量+向量
Vector operator+(Vector A,Vector B){
	return Vector(A.x+B.x,A.y+B.y);
}
// 向量-向量
Vector operator-(Vector A,Vector B){
	return Vector(A.x-B.x,A.y-B.y);
}
// 向量*数值
Vector operator*(Vector A,double k){
	return Vector(A.x*k,A.y*k);
}
// 向量/数值
Vector operator/(Vector A,double k){
	return Vector(A.x/k,A.y/k);
}
// 点相等
bool operator==(Point a,Point b){
	return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
// 范数
int Norm(Vector v){
	return v.x*v.x+v.y*v.y;
}
// 向量内积
double dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}
// 向量长度
double len(Vector A){
	return sqrt(dot(A,A));
}
// 向量叉积
double cross(Vector A,Vector B){
	return A.x*B.y-B.x*A.y;
}
// 三点叉积
double cross(Point a,Point b,Point c){
	return cross(b-a,c-a);
}
// 判断线段是否规范相交
bool segment_proper_intersection(Point A,Point B,Point C,Point D){
	double c1=cross(B-A,C-A),c2=cross(B-A,D-A),
			c3=cross(D-C,B-C),c4=cross(D-C,A-C);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
//

struct Edge{
    int from,to;
    double dist;
    Edge(int u=0,int v=0,double w=0):from(u),to(v),dist(w){}
    void output(){
        printf("( %d , %d , %.2f )\n",from,to,dist);
    }
};

struct HeapNode{
    int u;  //顶点u距离s的距离为dist
    double dist;
    HeapNode(double w=0,int x=0):dist(w),u(x){}
    bool operator<(const HeapNode&rhs)const{
	    return dcmp(dist-rhs.dist)>0;
    }
};

struct Graph{
    const static int V=10000+10;
    int n,m;
    vector<Edge>edges;    // 边集
    vector<int>G[V];
    bool done[V];   //是否已经永久标号
    double d[V];     //s到各个顶点的距离

    void init(int n){
    	this->n=n;
    	m=0;
    	for(int i=0;i<n;i++)G[i].clear();
    	edges.clear();
    }

    void addEdge(int from,int to,double dist){
    	edges.push_back(Edge(from,to,dist));
    	G[from].push_back(m++);
    	edges.push_back(Edge(to,from,dist));
    	G[to].push_back(m++);
    }

    void dijkstra(int s){
    	for(int i=0;i<n;i++)d[i]=inf*1.0;
        memset(done,0,sizeof(done));
        priority_queue<HeapNode>Q;
        d[s]=0;
        Q.push(HeapNode(0,s));
        while(!Q.empty()){
        	HeapNode x=Q.top();Q.pop();
        	int u=x.u;  // 拿最小距离的顶点编号
        	if(done[u])continue;  //每个顶点出发只可以松弛一次
        	done[u]=true;
        	for(int i=0;i<G[u].size();i++){
        		Edge&e=edges[G[u][i]];   //取出一条邻边
        		if(dcmp(d[e.to]-d[u]-e.dist)>0){
        			d[e.to]=d[u]+e.dist;
        			Q.push(HeapNode(d[e.to],e.to));
        		}
        	}
        }
    }

}g;

struct Segment{
    Point s,t;
}seg[40000];

Point P[40000];
int m;
bool check(int i,int j){
// 首先考虑同一堆墙上
    int k1=(i-1)%4+1;
    int k2=(j-1)%4+1;
    if(i!=0&&(i-1)/4==(j-1)/4){
        if(k1==1&&k2==2)return true;
        else if(k1==3&&k2==4)return true;
        else return false;
    }
    for(int k=0;k<m;k++){
        if(segment_proper_intersection(P[i],P[j],seg[k].s,seg[k].t))
            return false;
    }
    return true;
}
int main(){
    //freopen("in.txt","r",stdin);
    int n;
    double x,y1,y2,y3,y4;
    while(~scanf("%d",&n)&&n!=-1){
        int cnt1=0,cnt2=0;
        P[cnt1++]=Point(0,5);
        for(int i=0;i<n;i++){
           scanf("%lf %lf %lf %lf %lf",&x,&y1,&y2,&y3,&y4);
           P[cnt1++]=Point(x,y1);
           P[cnt1++]=Point(x,y2);
           P[cnt1++]=Point(x,y3);
           P[cnt1++]=Point(x,y4);
           seg[cnt2].s=Point(x,0);
           seg[cnt2++].t=Point(x,y1);
           seg[cnt2].s=Point(x,y2);
           seg[cnt2++].t=Point(x,y3);
           seg[cnt2].s=Point(x,y4);
           seg[cnt2++].t=Point(x,10);
        }
        P[cnt1++]=Point(10,5);
        n=cnt1;     //定点数量
        m=cnt2; // 线段数量
        g.init(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)if(check(i,j)){
               // printf("%d %d %.2f\n",i,j,len(P[i]-P[j]));
                g.addEdge(i,j,len(P[i]-P[j]));
            }
        }
        g.dijkstra(0);
        //for(int i=0;i<n;i++){
         //   printf("%d : %.2f\n",g.d[i]);
        //}
        printf("%.2f\n",g.d[n-1]);
    }
    return 0;
}






