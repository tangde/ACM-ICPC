// hdu3400
#include<bits/stdc++.h>
using namespace std;

struct Point{
	double x,y;
	Point(double a=0,double b=0):x(a),y(b){}

	Point operator+(const Point&rhs)const{
		return Point(x+rhs.x,y+rhs.y);
	}
	// 向量乘长数
	Point operator*(const double a)const{
		return Point(a*x,a*y);
	}

	Point operator-(const Point&rhs)const{
		return Point(x-rhs.x,y-rhs.y);
	}

	//  向量模长
	double length(){
		return sqrt(x*x+y*y);
	}

};
Point A,B,C,D,K,M;
double lenAB,lenCD,p,q,r,u;
double f(double u,double v){
	K=A*(1-u)+B*u;
	M=C*(1-v)+D*v;
	return (K-A).length()/p+(K-M).length()/r+(M-D).length()/q;
}

const int iter=100;   // 迭代次数
double search(double u,double l,double r){
	for(int i=0;i<iter;i++){
		double m1=l+(r-l)/3;
		double m2=r-(r-l)/3;
		if(f(u,m1)<f(u,m2))r=m2;
		else l=m1;
	}
	return f(u,l);
}
// 搜索区间为[ul,ur]*[vl,vr]
double slove(double ul,double ur,double vl,double vr){
	double fl,fr,ml,mr;
	for(int i=0;i<iter;i++){
		ml=ul+(ur-ul)/3;
		mr=ur-(ur-ul)/3;
		fl=search(ml,vl,vr);
		fr=search(mr,vl,vr);
		if(fl<fr)ur=mr;
		else ul=ml;
	}
	return fl;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y);
		scanf("%lf%lf%lf%lf",&C.x,&C.y,&D.x,&D.y);
		scanf("%lf%lf%lf",&p,&q,&r);
		lenAB=(A-B).length();
		lenCD=(C-D).length();
		double ans=slove(0,1,0,1);
		printf("%.2f\n",ans);
	}
    return 0;
}






