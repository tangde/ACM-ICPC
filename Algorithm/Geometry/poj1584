// J题
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
// 点在多边形内判定(转角法)，O(n)
// 凸，凹多边形均可
int point_in_polygon(const Polygon&poly,Point q){
	int wn=0,n=poly.size();
	for(int i=0;i<n;i++){
		Point a=poly[i],b=poly[(i+1)%n];
		if(point_on_segment(a,b,q))return -1; // 在边界上
		int k=dcmp(cross(b-a,q-a));
		int d1=dcmp(a.y-q.y);
		int d2=dcmp(b.y-q.y);
		if(k>0&&d1<=0&&d2>0)wn++;
		if(k<0&&d2<=0&&d1>0)wn--;
	}
	return wn!=0; // 0外部，1内部
}
// 逆时针输入，判断简单多边形是否是凸多边形
bool is_convex(Polygon&poly){
	int n=poly.size();
	int d=dcmp(cross(poly[n-1],poly[0],poly[1]));
	for(int i=1;i<n-1;i++){
		if(dcmp(cross(poly[i],poly[i+1],poly[(i+2)%n]))*d<0)
			return false;
	}
	return true;
}
bool circle_in_polygon(Point A,double r,const Polygon&poly){
	if(point_in_polygon(poly,A)!=1) return false;
	int n=poly.size();
	for(int i=0;i<n;i++){
		double d=distance_to_segment(poly[i],poly[(i+1)%n],A);
		if(dcmp(d-r)<0) return false;
	}
	return true;
}

void read_point(Point&A){
	scanf("%lf %lf",&A.x,&A.y);
}
Polygon poly;

int main(){
	int n;
	Point A,p;
	double r;
	while(scanf("%d",&n)&&n>2){
		poly.clear();
		scanf("%lf",&r);
		read_point(A);
		for(int i=0;i<n;i++){
			read_point(p);
			poly.push_back(p);
		}
		if(!is_convex(poly))puts("HOLE IS ILL-FORMED");
		else if(circle_in_polygon(A,r,poly))puts("PEG WILL FIT");
		else puts("PEG WILL NOT FIT");
	}
	return 0;
}









