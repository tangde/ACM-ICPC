// poj2079,最大三角形面积
//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-8;
const int maxn=50000+10;

int dcmp(double x){
	if(fabs(x)<eps)return 0;
	else return x<0?-1:1;
}

struct Point{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y){}
};
typedef Point Vector;   // Vector是Point的别名，表示向量
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
double cross(Point A,Point B,Point C){
	return cross(B-A,C-A);
}
// 输入点数组P，输出点数组ch,函数返回图包定点数。
// 输入点不能有重复
// 如果不希望在凸包边上有输入点，把<=改为<
int convexHull(Point *P,int n,Point* ch){
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
// 点 P到直线AB的距离
double distanceToLine(Point A,Point B,Point P){
	Vector u=B-A,v=P-A;
	return fabs(cross(u,v))/length(u);
}

double Rotating_Calipers_Area(Point*ch,int n){
	double ans=0;
	ch[n]=ch[0];
	for(int i=0;i<n;i++){ // 枚举第1个点
		int j=(i+1)%n;
		int k=(j+1)%n;
		while(dcmp(cross(ch[i],ch[j],ch[k+1])-cross(ch[i],ch[j],ch[k]))>0){
			k=(k+1)%n;
		}
		while(i!=j&&k!=i){
			ans=max(ans,cross(ch[i],ch[j],ch[k]));
			while(dcmp(cross(ch[i],ch[j],ch[k+1])-cross(ch[i],ch[j],ch[k]))>0){
				k=(k+1)%n;
			}
			j=(j+1)%n;
		}
	}
	return ans/2;
}

Point P[maxn],ch[maxn];
int main(){
	int n;
	while(~scanf("%d",&n)&&n>0){
		for(int i=0;i<n;i++){
			scanf("%lf %lf",&P[i].x,&P[i].y);
		}
		n=convexHull(P,n,ch);
		printf("%.2f\n",Rotating_Calipers_Area(ch,n));
	}
	return 0;
}





