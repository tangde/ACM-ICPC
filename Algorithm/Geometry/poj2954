// poj2954,Pick公式
//#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
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
typedef vector<Point>Ploygon; // 多边形的定义
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
// 先y再x
bool cmpy(Point a,Point b){
	return dcmp(a.y-b.y)<0||(dcmp(a.y-b.y)==0&&dcmp(a.x-b.x)<0);
}
//极角排序
bool polar(Point a,Point b){
	return atan2(a.y,a.x)<atan2(b.y,b.x);
}
// 向量内积
double dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}
// 向量长度
double length(Vector A){
	return sqrt(dot(A,A));
}
// 向量夹角
double angle(Vector A,Vector B){
	return acos(dot(A,B)/length(A)/length(B));
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
// 非0向量A的单位法向量
Vector normal(Vector A){
	double l=length(A);
	return Vector(-A.y/l,A.x/l);
}
// 直线AB与CD交点，（需要保证只有唯一交点）
Point get_line_intersection(Point A,Point B,Point C,Point D){
	Vector v=B-A,w=D-C,u=A-C;
	double t=cross(w,u)/cross(v,w);
	return A+v*t;
}
// 点 P到直线AB的距离
double distance_to_line(Point A,Point B,Point P){
	Vector u=B-A,v=P-A;
	return fabs(cross(u,v))/length(u);
}
// 点P到线段的距离
double distance_to_segment(Point A,Point B,Point P){
	if(A==B)return length(P-A);
	Vector u=B-A,v=P-A,w=P-B;
	if(dot(u,v)<0)return length(v);
	else if(dot(u,w)>0)return length(w);
	else return fabs(cross(u,v))/length(u);
}
// 点P到直线AB的投影点
Point get_line_projection(Point A,Point B,Point P){
	Vector v=B-A;
	return A+v*(dot(v,P-A)/dot(v,v));
}
// 点P是否在线段上AB上(不包含端点)
bool point_on_segment(Point A,Point B,Point P){
	return dcmp(cross(B-P,A-P))==0&&dcmp(dot(A-P,B-P))<0;
}
// 判断线段是否规范相交
bool segment_proper_intersection(Point A,Point B,Point C,Point D){
	double c1=cross(B-A,C-A),c2=cross(B-A,D-A),
			c3=cross(D-C,B-C),c4=cross(D-C,A-C);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

// 多边形面积(凸凹多边形均可),以原点作为基点
double ploygon_area(const Ploygon&ploy){
	double area=0;
	int n=ploy.size();
	for(int i=0;i<n;i++){
		area+=cross(ploy[i],ploy[(i+1)%n]);
	}
	return fabs(area/2);
}
int	ploygon_border_point_cnt(const Ploygon &ploy){
	int n=ploy.size(),ans=0;
	for(int i=0;i<n;i++){
		Point p=ploy[(i+1)%n]-ploy[i%n];
		int x = abs(p.x),y = abs(p.y);
		ans+=__gcd(x,y);
	}
	return ans;
}
int	ploygon_inside_point_cnt(Ploygon&ploy)	{
	return	int(ploygon_area(ploy))+1-ploygon_border_point_cnt(ploy)/2;
}
int main(){
	Ploygon ploy;
	int x1,x2,x3,y1,y2,y3;
	while(scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3)){
		if(x1==0&&x2==0&&x3==0&&y1==0&&y2==0&&y3==0)break;
		ploy.clear();
		ploy.push_back(Point(x1,y1));
		ploy.push_back(Point(x2,y2));
		ploy.push_back(Point(x3,y3));
		printf("%d\n",ploygon_inside_point_cnt(ploy));
	}
	return 0;
}






