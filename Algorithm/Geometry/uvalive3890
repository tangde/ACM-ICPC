// uvaLive 3890
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn=500;
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

double cross(Vector A,Vector B){
	return A.x*B.y-B.x*A.y;
}
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
// 点p在有向直线的左边(线上不算)
bool onLeft(Line L,Point p){
	return cross(L.v,p-L.P)>0;
}
// 两直线交点。假设交点唯一存在
Point getIntersection(Line a,Line b){
	Vector u=a.P-b.P;
	double t= cross(b.v,u)/cross(a.v,b.v);
	return a.P+a.v*t;
}
// 半平面交过程
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
		if(dcmp(cross(q[last].v,q[last-1].v))==0){
			last--;
			if(onLeft(q[last],L[i].P))q[last]=L[i];
		}
		if(first<last) p[last-1]=getIntersection(q[last-1],q[last]);
	}
	while(first<last&&!onLeft(q[first],p[last-1])) last--;
	if(last-first<=1) return 0; // 空集
	p[last]=getIntersection(q[last],q[first]); // 首尾两个半平面交点
	memcpy(poly,p+first,last-first+1);
	return last-first+1;
}

double length(Vector v){
	return sqrt(v.x*v.x+v.y*v.y);
}
Vector normal(Vector v){
	double l=length(v);
	return Vector(-v.y/l,v.x/l);
}
Point ploy[maxn],P[maxn];
Vector v1[maxn],v2[maxn];
Line L[maxn];
int main(){
	int n;
	double x,y;
	while(~scanf("%d",&n)&&n){
		for(int i=0;i<n;i++){
			scanf("%lf %lf",&P[i].x,&P[i].y);
		}
		for(int i=0;i<=n;i++){
			v1[i]=P[(i+1)%n]-P[i];
			v2[i]=normal(v1[i]);
		}
		double left =0,right =20000;
		while(right-left>eps){
			double mid=(right+left)/2;
			for(int i=0;i<=n;i++)L[i]=Line(P[i]+v2[i]*mid,v1[i]);
			int m=halfPlaneIntersection(L,n,ploy);
			if(m)left=mid;else right=mid;
		}
		printf("%.5lf\n",left);
	}
	return 0;
}















