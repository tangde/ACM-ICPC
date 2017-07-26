//hdu4454,暴力枚举
#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
#define eps 1e-6
int dcmp(double x){
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(double _x=0,double _y=0):x(_x),y(_y){}
    void output(){
        printf("( %lf , %lf ) \n",x,y);
    }
};

Point A0,C;// A0初始位置，C为圆心
double R; // 圆半径
Point rec[5];

typedef Point Vector;        // Vector是Point的别名，表示向量
typedef vector<Point>Polygon; // 多边形的定义
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

bool operator<(Point a,Point b){
    if(dcmp(a.x-b.x)!=0) return dcmp(a.x-b.x)<0;
    else return dcmp(a.y-b.y)<0;
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

Vector normal(Vector A){
    double l=len(A);
    return Vector(-A.y/l,A.x/l);
}
// 点P到线段的距离
double distance_to_segment(Point A,Point B,Point P){
    if(A==B)return len(P-A);
    Vector u=B-A,v=P-A,w=P-B;
    if(dot(u,v)<0)return len(v);
    else if(dot(u,w)>0)return len(w);
    else return fabs(cross(u,v))/len(u);
}

double dis(Point*rec,Point p){
    double ans=1e50;
    for(int i=0;i<4;i++){
        ans=min(ans,len(p-A0)+distance_to_segment(rec[i],rec[(i+1)%4],p));
    }
    return ans;
}


Point get_point(double theta){
    return Point(C.x+R*cos(theta),C.y+R*sin(theta));
}
// 三分求最小值
const int iter=500;   // 迭代次数
double search(double l,double r){
    for(int i=0;i<iter;i++){
        double m1=(r-l)/3+l;
        Point x1=get_point(m1);
        double m2=r-(r-l)/3;
        Point x2=get_point(m2);
        if(dis(rec,x1)<dis(rec,x2))r=m2;
        else l=m1;
    }
    return dis(rec,get_point(l));
}

int read_point(Point &A){
    return scanf("%lf %lf",&A.x,&A.y);
}

int main(){
    freopen("in.txt","r",stdin);
    while(read_point(A0)&&!(A0==Point(0,0))){
        read_point(C);
        scanf("%lf",&R);
        read_point(rec[0]);
        read_point(rec[2]);
        rec[1].x=rec[2].x;
        rec[1].y=rec[0].y;
        rec[3].x=rec[0].x;
        rec[3].y=rec[2].y;
        double ans=1e50;
        for(double theta=0;theta<=2*PI;theta+=0.0001){
            Point x=get_point(theta);
            ans=min(ans,dis(rec,x));
        }
        printf("%.2f\n",ans);
    }
    return 0;
}

