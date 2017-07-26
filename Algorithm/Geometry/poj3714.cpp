// poj3714,最近邻点对
//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-8;
const int maxn=500000+10;

int dcmp(double x){
	if(fabs(x)<eps)return 0;
	else return x<0?-1:1;
}
struct Point{
	bool flag;
	double x,y;
	Point(double _x=0,double _y=0,bool _flag=0):x(_x),y(_y),flag(_flag){}
}X[maxn],Y[maxn];
typedef Point Vector;
bool cmpx(Point a,Point b){ // 按照x排序
	return dcmp(a.x-b.x)<0||(dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)<0);
}

bool cmpy(Point a,Point b){ // 按照y排序
	return dcmp(a.y-b.y)<0||(dcmp(a.y-b.y)==0&&dcmp(a.x-b.x)<0);
}

double dis(Point&a,Point&b){
	if(a.flag==b.flag)return 1e20;
	else return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
// 首先X[]是排序好的
double nearest(int l,int r){
	if(r-l==1) return dis(X[l],X[l+1]);
	if(r-l==2) return min(min(dis(X[l],X[l+1]),dis(X[l],X[l+2])),
			dis(X[l+1],X[l+2]));
	int mid=(r+l)>>1;
	double d=min(nearest(l,mid),nearest(mid+1,r));
	if(dcmp(d)==0) return 0;
	int cnt=0;
	for(int i=mid;i>=l&&X[mid].x-X[i].x<d;i--){
		Y[cnt++]=X[i];
	}
	for(int i=mid+1;i<=r&&X[i].x-X[mid+1].x<d;i++){
		Y[cnt++]=X[i];
	}
	sort(Y,Y+cnt,cmpy);
	for(int i=0;i<cnt;i++){
		for(int j=i+1;j<cnt&&Y[j].y-Y[i].y<d;j++){
			d=min(d,dis(Y[j],Y[i]));
		}
	}
	return d;
}
int main(){
	int n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lf %lf",&X[i].x,&X[i].y);
			X[i].flag=true;
		}
		for(int i=n;i<2*n;i++){
			scanf("%lf %lf",&X[i].x,&X[i].y);
			X[i].flag=false;
		}
		sort(X,X+2*n,cmpx);
		printf("%.3f\n",nearest(0,2*n-1));
	}
	return 0;
}





