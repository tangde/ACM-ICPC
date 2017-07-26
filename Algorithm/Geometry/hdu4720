// hdu4720,盖住三角形最小面积圆
//#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=400;
const double eps=1e-8;
#define PI acos(-1.0)
int dcmp(double x){
	if(fabs(x)<eps)return 0;
	else return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y){}
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
// 先x再y
bool cmpx(Point a,Point b){
	return dcmp(a.x-b.x)<0||(dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)<0);
}
double dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}
// 向量叉积
double cross(Vector A,Vector B){
	return A.x*B.y-B.x*A.y;
}
// 三点叉积
double cross(Point a,Point b,Point c){
	return cross(b-a,c-a);
}
// 向量旋转，rad是角度
Vector rotate(Vector A,double rad){
	return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
double length(Vector A){
	return sqrt(dot(A,A));
}
// 直线AB与CD交点，（需要保证只有唯一交点）
Point get_line_intersection(Point A,Point B,Point C,Point D){
	Vector v=B-A,w=D-C,u=A-C;
	double t=cross(w,u)/cross(v,w);
	return A+v*t;
}
void read_point(Point&A){
	scanf("%lf %lf",&A.x,&A.y);
}
double ok(double a,double b,double c){ //判断是否是炖角
	double d=a*a+b*b-c*c;
	return dcmp(d)<=0;
}
int main(){
	int T;
	Point P[3],Q,crossPoint,a,b,c,d;
	Vector u,v;
	double r,k;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		for(int i=0;i<3;i++)
			read_point(P[i]);
		read_point(Q);
		double d0=length(P[1]-P[0]);
		double d1=length(P[2]-P[0]);
		double d2=length(P[2]-P[1]);
		if(ok(d0,d1,d2)){
			r=d2/2;
			crossPoint=(P[2]+P[1])/2;
		}
		if(ok(d0,d2,d1)){
			r=d1/2;
			crossPoint=(P[2]+P[0])/2;
		}
		if(ok(d1,d2,d0)){
			r=d0/2;
			crossPoint=(P[0]+P[1])/2;
		}
		else{
			u=rotate(P[1]-P[0],PI/2);
			v=rotate(P[2]-P[0],PI/2);
			a=(P[1]+P[0])/2,b=a+u;
			c=(P[2]+P[0])/2,d=c+v;
			crossPoint = get_line_intersection(a,b,c,d);
			r =length(crossPoint-P[0]);
		}
		k=length(crossPoint-Q);
		if(dcmp(k-r)<=0)printf("Case #%d: Danger\n",kase);
		else printf("Case #%d: Safe\n",kase);
	}
	return 0;
}





