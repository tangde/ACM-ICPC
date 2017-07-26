// uva10652
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn=3000;
const double eps=1e-8;
const double PI=acos(-1.0);

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
	return dcmp(a.x-b.x)<0||
			(dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)<0);
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

// 非0向量A的单位法向量
Vector normal(Vector A){
	double l=length(A);
	return Vector(-A.y/l,A.x/l);
}

// 向量旋转，rad是角度
Vector Rotate(Vector A,double rad){
	return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

// 多边形面积(凸凹多边形均可),以原点作为基点
double polyArea(Point *P,int n){
	double area=0;
	for(int i=0;i<n;i++){
		area+=cross(P[i],P[(i+1)%n]);
	}
	return fabs(area/2);
}

// 输入点数组P，输出点数组ch,函数返回图包定点数。
// 输入点不能有重复
// 如果不希望在凸包边上有输入点，把<=改为<
int andrew(Point *P,int n,Point* ch){
	sort(P,P+n); // 先按照x排序，再按照y排序
	int m=0;
	for(int i=0;i<n;i++){
		while(m>1&&dcmp(cross(ch[m-1]-ch[m-2],P[i]-ch[m-2]))<=0)m--;
		ch[m++]=P[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--){
		while(m>k&&dcmp(cross(ch[m-1]-ch[m-2],P[i]-ch[m-2]))<=0)m--;
		ch[m++]=P[i];
	}
	if(n>1)m--;
	return m;
}
Point P[maxn],ch[maxn];
int main(){
	int T,n;
	double x,y,w,h,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		double area1=0;
		for(int i=0;i<n;i++){
			scanf("%lf %lf %lf %lf %lf",&x,&y,&w,&h,&j);
			area1+=w*h;
			Point p0(x,y);
			j=-j/180*PI; // 将j转化为逆时针旋转，化为弧度值
			Vector u(cos(j),sin(j));
			Vector v=normal(u);
			u=u*w/2;v=v*h/2;
			P[4*i]=p0+u+v;
			P[4*i+1]=p0+u-v;
			P[4*i+2]=p0-u+v;
			P[4*i+3]=p0-u-v;
		}
		n=4*n;
		int m=andrew(P,n,ch);
		double area2=polyArea(ch,m);
		printf("%.1lf %%\n",area1*100/area2);
	}
	return 0;
}








