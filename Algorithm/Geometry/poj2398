//poj2398
//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
#include<cstring>
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

double cross(Vector A,Vector B){
    return A.x*B.y-B.x*A.y;
}
struct Segment{
    Point s,t;
    bool operator<(const Segment&X)const{
        return dcmp(s.x-X.s.x)<0;
    }
}seg[10000];

int get_id(Point &p,int n){
    int l=0,r=n+1;
    while(r-l>0){
        int m=(r+l)>>1;
        if(dcmp(cross(seg[m].t-seg[m].s,p-seg[m].s))>0)r=m;
        else l=m+1;
        //cout<<r<<" "<<l<<" "<<m<<endl;
    }
    return r;
}
void read_point(Point&A){
    scanf("%lf %lf",&A.x,&A.y);
}
int cnt[10000];
int main(){
    //freopen("in.txt","r",stdin);
    int n,m,kase=1;
    Point p;
    double x1,x2,y1,y2,u,l;
    while(scanf("%d",&n)&&n){
        scanf("%d",&m);
        scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&u,&l);
            seg[i].s=Point(l,y2);
            seg[i].t=Point(u,y1);
        }
        seg[n].s=Point(x2,y2);
        seg[n].t=Point(x2,y1);
        sort(seg,seg+n+1);
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<m;i++){
            read_point(p);
            cnt[get_id(p,n)]++;
        }
        map<int,int>mp;
        for(int i=0;i<=n;i++)if(cnt[i]){
            mp[cnt[i]]++;
        }
        puts("Box");
        for(map<int,int>::iterator it =mp.begin();it!=mp.end();it++){
            printf("%d: %d\n",it->first,it->second);
        }
    }
	return 0;
}




