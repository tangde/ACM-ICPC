// poj3608,求两不相交凸包间的最短距离
//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
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
// 点小于
bool operator<(Point a,Point b){
	return dcmp(a.x-b.x)<0||(dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)<0);
}
// 向量内积
double dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}
// 向量长度
double length(Vector A){
	return sqrt(dot(A,A));
}

// 向量叉积
double cross(Vector A,Vector B){
	return A.x*B.y-B.x*A.y;
}

// 点P到线段AB的距离
double distanceToSegment(Point A,Point B,Point P){
	if(A==B)return length(P-A);
	Vector u=B-A,v=P-A,w=P-B;
	if(dot(u,v)<0)return length(v);
	else if(dot(u,w)>0)return length(w);
	else return fabs(cross(u,v))/length(u);
}

// 两不相交线段AB和CD间的距离
double distanceTwoSegment(Point A,Point B,Point C,Point D){
	double dis=1e20;
	dis=min(dis,distanceToSegment(A,B,C));
	dis=min(dis,distanceToSegment(A,B,D));
	dis=min(dis,distanceToSegment(C,D,A));
	dis=min(dis,distanceToSegment(C,D,B));
	return dis;
}
// 旋转卡壳
double Rotating_Calipers_Distance(Point*ch1,int n,Point *ch2,int m){
	int q=0,p=0,d;
	for(int i=0;i<n;i++)if(dcmp(ch1[i].y-ch1[p].y)<0){
			p=i;
	}
	for(int i=0;i<m;i++)if(dcmp(ch2[i].y-ch2[q].y)>0){
			q=i;
	}
	ch1[n]=ch1[0];
	ch2[m]=ch2[0];
	double ans=1e20;
	for(int i=0;i<n;i++){
		while((d=dcmp(cross(ch1[p+1]-ch1[p],ch2[q+1]-ch1[p]) - cross(ch1[p+1]-ch1[p],ch2[q]-ch1[p])))>0){
			q=(q+1)%m;
		}
		if(d<0) ans=min(ans,distanceToSegment(ch1[p],ch1[p+1],ch2[q]));
		else ans=min(ans,distanceTwoSegment(ch1[p],ch1[p+1],ch2[q],ch2[q+1]));
		p=(p+1)%n;
	}
	return ans;
}
const int maxn=50000+10;
Point P[maxn],Q[maxn];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)&&n){
		for(int i=0;i<n;i++){
			scanf("%lf %lf",&P[i].x,&P[i].y);
		}
		for(int i=0;i<m;i++){
			scanf("%lf %lf",&Q[i].x,&Q[i].y);
		}
		double ans=Rotating_Calipers_Distance(P,n,Q,m);
		ans=min(ans,Rotating_Calipers_Distance(Q,m,P,n));
		printf("%.5lf\n",ans);
	}
	return 0;
}





