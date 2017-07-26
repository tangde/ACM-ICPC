//hdu1077
//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
#define PI acos(-1.0)
#define eps 1e-4
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

bool point_in_cicle(Point A,double r,Point B){
    if(dcmp(len(A-B)-r)<=0) return true;
    else return false;
}
void read_point(Point &A){
    scanf("%lf %lf",&A.x,&A.y);
}

Point P[310];
int Count(Point&A,int n){
    int l=lower_bound(P,P+n,Point(A.x-1.01,0.0))-P;
    int res=0;
    for(int j=l;j<n&&dcmp(P[j].x-A.x-1.01)<=0;j++)if(point_in_cicle(A,1,P[j])){
        res++;
    }
    return res;
}

int main(){
   // freopen("in.txt","r",stdin);
	int T,n;
	scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            read_point(P[i]);
        }
        sort(P,P+n);
        int cnt=0,ans=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                Vector u=P[j]-P[i];
                double d=len(u);
                if(dcmp(d-2)>0) continue;
                Point midPoint=(P[i]+P[j])/2;
                Vector v=normal(u);
                double l=sqrt(1-d*d/4);
                Point p1=midPoint+v*l;
                Point p2=midPoint-v*l;
                ans=max(ans,Count(p1,n));
                ans=max(ans,Count(p2,n));
            }
        }
        printf("%d\n",ans);
	}
	return 0;
}






