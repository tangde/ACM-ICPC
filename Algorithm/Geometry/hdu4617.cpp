// hdu4617
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
	double x,y,z;
	Point(double _x=0,double _y=0,double _z=0):x(_x),y(_y),z(_z){}
};
typedef Point Vector;

Point operator+(Vector a,Vector b){
	return Point(a.x+b.x,a.y+b.y,a.z+b.z);
}
Point operator-(Vector a,Vector b){
	return Vector(a.x-b.x,a.y-b.y,a.z-b.z);
}
Point operator*(Vector a,double k){
	return Vector(a.x*k,a.y*k,a.z*k);
}
Vector cross(Vector A,Vector B){
	return Vector(A.y*B.z-B.y*A.z,-(A.x*B.z-B.x*A.z),A.x*B.y-B.x*A.y);
}
double dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y+A.z*B.z;
}
double len(Vector A){
	return sqrt(dot(A,A));
}
struct Cylinder{
	Point o;
	Vector v;
	double r;
	Cylinder(){}
	Cylinder(Point _o,Vector _v,double _r):o(_o),v(_v),r(_r){}
};
Cylinder cylinder[maxn];
// 需要考虑直线共面的情况
double distance_cylinder(Cylinder C1,Cylinder C2){
	Vector u=C2.o-C1.o;
	Vector v=cross(C2.v,C1.v);
	double r;
	if(dcmp(dot(u,v))==0){ // 2直线共面
		if(len(v)==0)r=sqrt(dot(u,u)-fabs(dot(u,C1.v)/len(C1.v)))-C1.r-C2.r;
		else r=0;
	}
	else{
		r=fabs(dot(u,v)/len(v));
		r-=(C1.r+C2.r);
	}
	if(dcmp(r)<0)return 0;
	else return r;
}
void read_point(Point &A){
	scanf("%lf %lf %lf",&A.x,&A.y,&A.z);
}
int main(){
	int T,n;
	Point a,b,c;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			read_point(a);
			read_point(b);
			read_point(c);
			Vector v=cross(b-a,c-a);
			double r=len(a-b);
			cylinder[i]=Cylinder(a,v,r);
		}
		double dis=1e+20;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				dis=min(dis,distance_cylinder(cylinder[i],cylinder[j]));
				if(dcmp(dis)==0)break;
			}
			if(dcmp(dis)==0)break;
		}
		if(dcmp(dis)==0)printf("Lucky\n");
		else printf("%.2f\n",dis);
	}
	return 0;
}









