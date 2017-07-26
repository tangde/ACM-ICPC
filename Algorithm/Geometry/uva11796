// uva11796
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn=100;
const double eps=1e-8;

int dcmp(double x){
	if(fabs(x)<eps)return 0;
	else return x<0?-1:1;
}

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;

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
// 向量内积
double dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}

// 向量叉积
double cross(Vector A,Vector B){
	return A.x*B.y-B.x*A.y;
}

// 向量长度
double length(Vector A){
	return sqrt(dot(A,A));
}

// 点P到线段的距离
double distanceToSegment(Point A,Point B,Point P){
	if(A==B)return length(P-A);
	Vector u=B-A,v=P-A,w=P-B;
	if(dot(u,v)<0)return length(v);
	else if(dot(u,w)>0)return length(w);
	else return fabs(cross(u,v))/length(u);
}

void read_Point(Point&A){
	scanf("%lf %lf",&A.x,&A.y);
}

Point P[maxn],Q[maxn];
int A,B;
double lenA,lenB,Min,Max;

void update(Point A,Point B,Point P){
	Min=min(Min,distanceToSegment(A,B,P));
	Max=max(Max,length(P-A));
	Max=max(Max,length(P-B));
}

int main(){
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		scanf("%d %d",&A,&B);
		lenA=lenB=0;
		for(int i=0;i<A;i++){
			read_Point(P[i]);
			if(i>0)lenA+=length(P[i]-P[i-1]);
		}
		for(int i=0;i<B;i++){
			read_Point(Q[i]);
			if(i>0)lenB+=length(Q[i]-Q[i-1]);
		}
		int sq=0,sp=0;
		Point bp=P[0],bq=Q[0];
		Min=inf,Max=-inf;
		while(sp<A-1&&sq<B-1){
			Vector p=P[sp+1]-bp;
			Vector q=Q[sq+1]-bq;
			double t=min(length(p)/lenA,length(q)/lenB);
			p=p/length(p)*lenA*t;
			q=q/length(q)*lenB*t;
			update(bq,bq+q-p,bp);
			bp=bp+p;
			bq=bq+q;
			if(bp==P[sp+1])sp++;
			if(bq==Q[sq+1])sq++;
		}
		printf("Case %d: %.0lf\n",kase,Max-Min);
	}
	return 0;
}










