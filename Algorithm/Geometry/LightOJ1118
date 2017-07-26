//LightOj1118 ,圆交的面积
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
#define PI acos(-1.0)
const int maxn=4000;
int dcmp(double x){
	if(fabs(x)<eps)return 0;
	else return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y){}
};
Point P[maxn];
int k;
typedef Point Vector;

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
Vector rotate(Vector A,double cost,double sint){
	return Vector(A.x*cost-A.y*sint,A.x*sint+A.y*cost);
}
double length(Vector v){
	return sqrt(v.x*v.x+v.y*v.y);
}

double circle_cross_area(Point A1,double r1,Point A2,double r2){
	double d1=abs(r1-r2),d2=r1+r2;
	Vector v=A2-A1;
	double d=length(v),r=min(r1,r2);;
	if(dcmp(d-d1)<=0)return PI*r*r; // 内含或内切
	if(dcmp(d-d2)>=0)return 0; // 外切或外离
	double cos1=(r1*r1+d*d-r2*r2)/(2*d*r1);  // 余弦定理
	double sin1=sqrt(1-cos1*cos1);
	Vector u=rotate(v,cos1,sin1)*(r1/d);
	Vector w=rotate(v,cos1,-sin1)*(r1/d);
	double area=(abs(cross(u,v))+abs(cross(w,v)))/2;
	double area1=acos(cos1)*r1*r1;
	double cos2=(r2*r2+d*d-r1*r1)/(2*d*r2);
	double area2=acos(cos2)*r2*r2;
	return area1+area2-area;
}
int main(){
	int T;
	Point A1,A2;
	double r1,r2;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		scanf("%lf %lf %lf %lf %lf %lf",&A1.x,&A1.y,&r1,&A2.x,&A2.y,&r2);
		printf("Case %d: %.7f\n",kase,circle_cross_area(A1,r1,A2,r2));
	}
	return 0;
}





