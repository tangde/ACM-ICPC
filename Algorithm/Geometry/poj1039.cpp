// poj1039
//#include <bits/stdc++.h>
#include<iostream>
#include<map>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=400;
#define eps 1e-8
int dcmp(double x){
	if(fabs(x)<eps)return 0;
	else return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y){}
};
typedef Point Vector;
typedef vector<Point>Polygon;
Point operator+(Vector A,Vector B){
	return Vector(A.x+B.x,A.y+B.y);
}
Point operator-(Vector A,Vector B){
	return Vector(A.x-B.x,A.y-B.y);
}
Point operator*(Vector A,double r){
	return Vector(A.x*r,A.y*r);
}
bool operator==(Point a,Point b){
	return dcmp(a.x-b.x)==0&&dcmp(b.y-a.y)==0;
}
bool cmpx(Point a,Point b){
	if(dcmp(a.x-b.x)!=0)return dcmp(a.x-b.x)<0;
	else return dcmp(a.y-b.y)<0;
}
double dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}
double cross(Vector A,Vector B){
	return A.x*B.y-B.x*A.y;
}
double cross(Point a,Point b,Point c){
	return cross(b-a,c-a);
}
double len(Vector v){
	return sqrt(dot(v,v));
}
// 点P到线段的距离
double distance_to_segment(Point A,Point B,Point P){
	if(A==B)return len(P-A);
	Vector u=B-A,v=P-A,w=P-B;
	if(dot(u,v)<0)return len(v);
	else if(dot(u,w)>0)return len(w);
	else return fabs(cross(u,v))/len(u);
}
// 点P是否在线段上AB上(包含端点)
bool point_on_segment(Point A,Point B,Point P){
	return dcmp(cross(B-P,A-P))==0&&dcmp(dot(A-P,B-P))<=0;
}

// 直线AB与CD交点，（需要保证只有唯一交点）
Point get_line_intersection(Point A,Point B,Point C,Point D){
	Vector v=B-A,w=D-C,u=A-C;
	double t=cross(w,u)/cross(v,w);
	return A+v*t;
}
// 不相交0,交点在端点-1,规范相交，1
int line_intersect_segment(Point a,Point b,Point c,Point d,Point&crossPoint){
	Vector u=b-a;
	int d1=dcmp(cross(c-a,u));
	int d2=dcmp(cross(d-a,u));
	if(d1*d2>0) return 0;
	crossPoint=get_line_intersection(a,b,c,d);
	if(d1*d2==0) return -1;
	return 1;
}
double slove(const Polygon&poly){
	int n=poly.size();
	double ans=-1e20;
	Point c=poly[0],d=poly[0];
	d.y-=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)if(i!=j){
			Point a=poly[i],b=poly[j];
			a.y-=1;
			Point crossPoint;
			if(!line_intersect_segment(a,b,c,d,crossPoint)) continue;
			double maxX=poly[0].x;
			int k;
			for(k=1;k<n;k++){
				Point s=poly[k],t=poly[k];
				s.y-=1;
				if(!line_intersect_segment(a,b,s,t,crossPoint))
					break;
				maxX=max(maxX,poly[k].x);
			}
			if(k<n){
				Point s=poly[k-1],t=poly[k];
				if(line_intersect_segment(a,b,s,t,crossPoint)==1)
					maxX=max(maxX,crossPoint.x);
				s.y-=1;
				t.y-=1;
				if(line_intersect_segment(a,b,s,t,crossPoint)==1)
					maxX=max(maxX,crossPoint.x);

			}
			//printf("%d %d %.2f\n",i,j,maxX);
			ans=max(ans,maxX);
		}
	}
	return ans;
}

void read_point(Point&A){
	scanf("%lf %lf",&A.x,&A.y);
}

int main(){
	int n;
	Point p;
	while(scanf("%d",&n)&&n){
		Polygon poly(n);
		for(int i=0;i<n;i++){
			read_point(poly[i]);
		}
		double res=slove(poly);
		if(dcmp(res-poly[n-1].x)==0)puts("Through all the pipe.");
		else printf("%.2f\n",res);
	}
	return 0;
}


