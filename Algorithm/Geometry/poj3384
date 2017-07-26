// poj3384,半平面交
//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1500+10;
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

Vector operator+(Vector A,Vector B){
	return Vector(A.x+B.x,A.y+B.y);
}

Vector operator-(Vector A,Vector B){
	return Vector(A.x-B.x,A.y-B.y);
}

Vector operator*(Vector A,double k){
	return Vector(A.x*k,A.y*k);
}
bool operator==(Point a,Point b){
	return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double cross(Vector A,Vector B){
	return A.x*B.y-B.x*A.y;
}
// 有向直线的数据结构
struct Line{
	Point P;      // 直线上任意一点
	Vector v;     // 方向向量
	double angle;  // 极角
	Line(){}
	Line(Point P,Vector v):P(P),v(v){angle=atan2(v.y,v.x);}
	bool operator<(const Line&L)const{  // 极角排序
		return angle<L.angle;
	}
};
// 点p在有向直线的左边(包括边界)
bool onLeft(Line L,Point p){
	return dcmp(cross(L.v,p-L.P))>=0;
}
// 两直线交点。假设交点唯一存在
Point getIntersection(Line a,Line b){
	Vector u=a.P-b.P;
	double t= cross(b.v,u)/cross(a.v,b.v);
	return a.P+a.v*t;
}
// 半平面交过程,返回0是空集，返回1是一个点，但是不能处理返回无界区域(可以人为加一个大正方形)。
int halfPlaneIntersection(Line*L,int n,Point*poly){
	sort(L,L+n);    // 极角排序
	int first,last;   // 双端队列第一个元素和最后一个元素下标
	Point *p=new Point[n]; //p[i]为q[i]和q[i+1]的交点
	Line*q=new Line[n];    // 双端队列
	q[first=last=0]=L[0];
	for(int i=1;i<n;i++){
		while(first<last&&!onLeft(L[i],p[last-1])) last--;
		while(first<last&&!onLeft(L[i],p[first])) first++;
		q[++last]=L[i];
		if(dcmp(cross(q[last].v,q[last-1].v))==0){ // 两个半平面平行
			last--;
			if(onLeft(q[last],L[i].P))q[last]=L[i]; // 保留左边的半平面
		}
		if(first<last) p[last-1]=getIntersection(q[last-1],q[last]); // 末尾两个半平面交
	}
	while(first<last&&!onLeft(q[first],p[last-1])) last--;
	p[last]=getIntersection(q[last],q[first]); // 首尾两个半平面交点
	for(int i=0;i<last-first+1;i++){
		poly[i]=p[i+first];
	}
	int m=unique(poly,poly+last-first+1)-poly;
	return m;
}
double length(Vector v){
	return sqrt(v.x*v.x+v.y*v.y);
}
Vector normal(Vector v){
	double l=length(v);
	return Vector(-v.y/l,v.x/l);
}
Point P[maxn];
Line L[maxn];
int main(){
	int n,r;
	while(~scanf("%d %d",&n,&r)){
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&P[i].x,&P[i].y);
		reverse(P,P+n);
		P[n]=P[0];
		for(int i=0;i<n;i++){
			Vector v = P[i+1]-P[i];
			L[i]=Line(normal(v)*r+P[i],v);
		}
		n=halfPlaneIntersection(L,n,P);
		Point a=P[0],b=P[0];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(dcmp(length(P[j]-P[i])-length(a-b))>0){
					a=P[j];b=P[i];
				}
			}
		}
		printf("%.4f %.4f %.4f %.4f\n",a.x,a.y,b.x,b.y);
	}
	return 0;
}





