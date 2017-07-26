// poj2187
//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn=50000+10;
const double eps=1e-8;

struct Point{
	int x,y;
	Point(int _x=0,int _y=0):x(_x),y(_y){}
	bool operator<(const Point &rhs)const{
		if(x!=rhs.x)return x<rhs.x;
		else return y<rhs.y;
	}
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

int cross(Vector A,Vector B){
	return A.x*B.y-B.x*A.y;
}

int length(Vector v){
	return v.x*v.x+v.y*v.y;
}

int convexHull(Point *P,int n,Point* ch){
	sort(P,P+n); // 先按照x排序，再按照y排序
	int m=0;
	for(int i=0;i<n;i++){
		while(m>1&&cross(ch[m-1]-ch[m-2],P[i]-ch[m-2])<=0)m--;
		ch[m++]=P[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--){
		while(m>k&&cross(ch[m-1]-ch[m-2],P[i]-ch[m-2])<=0)m--;
		ch[m++]=P[i];
	}
	if(n>1)m--;
	return m;
}

// 旋转卡壳求凸包最远点对距离
int dia_rotating_calipers(Point *ch,int n){
	int dia=0;
	for(int i=0,q=1;i<n;i++){
		while(cross(ch[i+1]-ch[i],ch[q+1])>cross(ch[i+1]-ch[i],ch[q]))
			q=(q+1)%n;
		dia=max(dia,length(ch[q]-ch[i]));
		dia=max(dia,length(ch[i+1]-ch[q]));
	}
	return dia;
}
Point P[maxn],ploy[maxn],ch[maxn];
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d %d",&P[i].x,&P[i].y);
		}
		int m=convexHull(P,n,ch);
		int ans=dia_rotating_calipers(ch,m);
		printf("%d\n",ans);
	}
	return 0;
}













