// C 题
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
const int maxn=4000;

struct Point{
	int x,y;
	int id;
	Point(int _x=0,int _y=0,int _id=0):x(_x),y(_y),id(_id){}
}P[maxn];
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

int Norm(Vector v){
	return v.x*v.x+v.y*v.y;
}

// 向量内积
int dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}
// 向量叉积
int cross(Vector A,Vector B){
	return A.x*B.y-B.x*A.y;
}
// 三点叉积
int cross(Point a,Point b,Point c){
	return cross(b-a,c-a);
}

bool cmpy(Point a,Point b){
	if(a.y!=b.y)return a.y<b.y;
	else return a.x<b.x;
}
bool polar(Point a,Point b){
	Vector u=a-P[0];
	Vector v=b-P[0];
	int d=cross(u,v);
	if(d==0)return Norm(u)<Norm(v);
	else return d>0;
}
int main(){
	int T,n;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d %d",&P[i].x,&P[i].y);
			P[i].id=i;
		}
		printf("Case %d:\n",kase);
		sort(P,P+n,cmpy);
		sort(P+1,P+n,polar);
		int i=n-2;
		for(i=n-2;i>0;i--){
			if(cross(P[0],P[n-1],P[i])!=0)
				break;
		}
		if(i==0){printf("Impossible\n");continue;}
		reverse(P+i+1,P+n);
		for(int i=0;i<n;i++){
			if(i==n-1)printf("%d\n",P[i].id);
			else printf("%d ",P[i].id);
		}

	}
	return 0;
}





