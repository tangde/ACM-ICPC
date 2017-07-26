// uvalive 3263
#include<bits/stdc++.h>
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
// 点相等
bool operator==(Point a,Point b){
	return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
// 点小于
bool operator<(Point a,Point b){
	return dcmp(a.x-b.x)<0||(dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)<0);
}
// 向量叉积
double cross(Vector A,Vector B){
	return A.x*B.y-B.x*A.y;
}
// 向量内积
double dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}
// 直线AB与CD交点，（需要保证只有唯一交点）
Point getLineIntersection(Point A,Point B,Point C,Point D){
	Vector v=B-A,w=D-C,u=A-C;
	double t=cross(w,u)/cross(v,w);
	return A+v*t;
}
// 点P是否在线段上AB上(不包含端点)
bool onSegment(Point A,Point B,Point P){
	return dcmp(cross(B-P,A-P))==0&&dcmp(dot(A-P,B-P))<0;
}
// 判断线段是否规范相交
bool segmentProperIntersection(Point A,Point B,Point C,Point D){
	double c1=cross(B-A,C-A),c2=cross(B-A,D-A),
			c3=cross(D-C,B-C),c4=cross(D-C,A-C);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
const int maxn=301;
Point P[maxn],V[maxn*maxn];

int main(){
	int n,kase=1;
	while(scanf("%d",&n)&&n){
		for(int i=0;i<n;i++){
			scanf("%lf %lf",&P[i].x,&P[i].y);
			V[i]=P[i];
		}
		n--;
		int cnt=n;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(segmentProperIntersection(P[i],P[i+1],P[j],P[j+1])){
					V[cnt++]=getLineIntersection(P[i],P[i+1],P[j],P[j+1]);
				}
			}
		}
		sort(V,V+cnt);
		cnt=unique(V,V+cnt)-V;
		int e=n;
		for(int i=0;i<cnt;i++){
			for(int j=0;j<n;j++){
				if(onSegment(P[j],P[j+1],V[i]))
					e++;
			}
		}
		printf("Case %d: There are %d pieces.\n",kase++,e+2-cnt);
	}
	return 0;
}








