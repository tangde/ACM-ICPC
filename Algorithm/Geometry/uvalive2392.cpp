#include <bits/stdc++.h>
using namespace std;
const int maxn=300;
const double eps=1e-8;
int dcmp(double x){
	if(fabs(x)<eps)return 0;
	else return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y){}
}P[maxn*10];
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
// 三点叉积
double cross(Point a,Point b,Point c){
	return cross(b-a,c-a);
}

// 直线AB与CD交点，（需要保证只有唯一交点）
Point get_line_intersection(Point A,Point B,Point C,Point D){
	Vector v=B-A,w=D-C,u=A-C;
	double t=cross(w,u)/cross(v,w);
	return A+v*t;
}

// 直线ab线段cd交
bool line_intersect_segment(Point a,Point b,Point c,Point d,Point&crossPoint){
	Vector u=b-a; // 直线方向向量
	if(dcmp(cross(c-a,u)*cross(d-a,u))>0) // c,d在直线同一侧
		return false;
	if(dcmp(cross(u,d-c))==0)return false; //重合
	crossPoint=get_line_intersection(a,b,c,d);
	return true;
}
// 点P是否在线段上AB上(不包含端点)
bool point_on_segment(Point A,Point B,Point P){
	return dcmp(cross(B-P,A-P))==0&&dcmp(dot(A-P,B-P))<=0;
}
// 判断线段是否规范相交
bool segment_proper_intersection(Point A,Point B,Point C,Point D){
	double c1=cross(B-A,C-A),c2=cross(B-A,D-A),
			c3=cross(D-C,B-C),c4=cross(D-C,A-C);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
// 点在多边形内判定(转角法)，O(n)
// 凸，凹多边形均可
int point_in_polygon(const Polygon&poly,Point q){
	int wn=0,n=poly.size();
	for(int i=0;i<n;i++){
		Point a=poly[i],b=poly[(i+1)%n];
		if(point_on_segment(a,b,q))return -1; // 在边界上
		int k=dcmp(cross(b-a,q-a));
		int d1=dcmp(a.y-q.y);
		int d2=dcmp(b.y-q.y);
		if(k>0&&d1<=0&&d2>0)wn++;
		if(k<0&&d2<=0&&d1>0)wn--;
	}
	return wn!=0; // 0外部，1内部
}
// 判断线段AB是否在多边形ploy内
// 复杂度约为O(n)
bool segment_in_polygon(const Polygon&poly,Point A,Point B ){
	if(!point_in_polygon(poly,A)||!point_in_polygon(poly,B))
		return false;
	vector<Point>pointSet;
	int n=poly.size();
	for(int i=0;i<n;i++){ // 循环每条边
		Point C=poly[n],D=poly[(i+1)%n];
		if(segment_proper_intersection(A,B,C,D)) // 内交
			return false;
		if(point_on_segment(A,B,C))pointSet.push_back(C);
		if(point_on_segment(A,B,D))pointSet.push_back(D);
		if(point_on_segment(C,D,A))pointSet.push_back(A);
		if(point_on_segment(C,D,B))pointSet.push_back(B);
	}
	n =pointSet.size();
	sort(pointSet.begin(),pointSet.end(),cmpx);
	for(int i=0;i<n-1;i++){
		Point midPoint=(pointSet[i]+pointSet[i+1])/2;
		if(!point_in_polygon(poly,midPoint))return false;
	}
	return true;
}


double slove(const Polygon &poly){
	double res=0;
	int cnt=0,n=poly.size();
	Point crossPoint;
	for(int i=0;i<n;i++){ // 枚举任何两个点
		for(int j=i+1;j<n;j++){
			Point a=poly[i],b=poly[j];
			cnt=0;
			for(int k=0;k<n;k++){
				Point c=poly[k],d=poly[(k+1)%n]; // 枚举边cd
				if(line_intersect_segment(a,b,c,d,crossPoint)){
					P[cnt++]=crossPoint;
				}
			}
			sort(P,P+cnt,cmpx);
			cnt=unique(P,P+cnt)-P;
			bool ok=true;
			for(int k=0;k<cnt-1;k++)if(!segment_in_polygon(poly,P[k],P[k+1])){
				ok=false;break;
			}
			cout<<res<<endl;
			if(ok)res=max(res,length(P[cnt-1]-P[0]));
		}
	}
	return res;
}
void read_point(Point &A){
	scanf("%lf %lf",&A.x,&A.y);
}
Polygon poly;
int main(){
	int n,m,kase=1;
	Point p;
	while(~scanf("%d",&n)&&n){
		scanf("%d",&m);
		poly.clear();
		for(int i=0;i<n;i++){
			read_point(p);
			poly.push_back(p);
		}
		if(kase>1)putchar('\n');
		printf("Problem %d:\n",kase++);
		for(int i=1;i<=m;i++){
			read_point(p);
			if(point_in_polygon(poly,p))
				puts("Within");
			else puts("Outside");
		}
	}
	return 0;
}




