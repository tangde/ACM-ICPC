// uva11178
#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;

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

// 向量内积
double dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}
// 向量长度
double length(Vector A){
	return sqrt(dot(A,A));
}
// 向量夹角
double angle(Vector A,Vector B){
	return acos(dot(A,B)/length(A)/length(B));
}
// 向量叉积
double cross(Vector A,Vector B){
	return A.x*B.y-B.x*A.y;
}
// 向量旋转，rad是角度
Vector rotate(Vector A,double rad){
	return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

// 直线AB与CD交点，（需要保证只有唯一交点）
Point getLineIntersection(Point A,Point B,Point C,Point D){
	Vector v=B-A,w=D-C,u=A-C;
	double t=cross(w,u)/cross(v,w);
	return A+v*t;
}

Point slove(Point A,Point B,Point C){
	double rad1=angle(B-A,C-A)/3;
	Vector v1=rotate(B-A,rad1);
	double rad2=angle(A-B,C-B)/3;
	Vector v2=rotate(A-B,-rad2);
	return getLineIntersection(A,A+v1,B,B+v2);
}

void read_point(Point &A){
	scanf("%lf %lf",&A.x,&A.y);
}
int main(){
	Point A,B,C;
	int T;
	scanf("%d",&T);
	while(T--){
		read_point(A);
		read_point(B);
		read_point(C);
		Point F=slove(A,B,C);
		Point D=slove(B,C,A);
		Point E=slove(C,A,B);
		printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",D.x,D.y,E.x,E.y,F.x,F.y);
	}
	return 0;
}






