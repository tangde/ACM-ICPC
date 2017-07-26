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
Point P0[maxn],P[maxn];
Vector v[maxn];
int n;
double f(double t){
	for(int i=0;i<n;i++){
		P[i]=P0[i]+v[i]*t;
	}
	double ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans=max(ans,length(P[j]-P[i]));
		}
	}
	return ans;
}
// 其中f需要计算的函数，保证f是下凸函数
// 需要保证f在区间[l,r]有唯一极值
const int iter=100;   // 迭代次数
double search(double l,double r){
	for(int i=0;i<iter;i++){
		if(dcmp(r)<=0)return 0; // 剪枝
		double m1=(r-l)/3+l;
		double m2=r-(r-l)/3;
		if(dcmp(f(m1)-f(m2))<0)r=m2;
		else l=m1;
	}
	return l;
}
void slove(int kase){
	double l=-1e10,r=1e10;
	double t=search(l,r);
	if(dcmp(t)<=0)t=0;
	printf("Case #%d: %.2f %.2f\n",kase,t,f(t));
}

int main(){
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lf %lf %lf %lf",&P0[i].x,&P0[i].y,&v[i].x,&v[i].y);
		}
		slove(kase);
	}
	return 0;
}





