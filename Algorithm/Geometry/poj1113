// poj1113,凸包
//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
#define PI acos(-1.0)
#define eps 1e-8
int dcmp(double x){
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y){}
	void output(){
		printf("( %lf , %lf ) \n",x,y);
	}
};
Point P[10000],ch[10000];

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

bool cmpx(Point a,Point b){
    if(dcmp(a.x-b.x)!=0) return dcmp(a.x-b.x)<0;
    else return dcmp(a.y-b.y)<0;
}
// 向量内积
double dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}
// 向量长度
double len(Vector A){
	return sqrt(dot(A,A));
}

// 向量叉积
double cross(Vector A,Vector B){
	return A.x*B.y-B.x*A.y;
}

/*
int convexHull(Point *P,int n,Point* ch){
	sort(P,P+n,cmpx); // 先按照x排序，再按照y排序
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
*/
// 卷包裹写法
int volume_wrapping(Point *P,int n,Point *ch){
	int k=0;
	for(int i=1;i<n;i++)if(dcmp(P[i].y-P[k].y)<0){
		k=i;
	}
	ch[0]=P[k];  // 找到y坐标最低的点
	int m;
	for(m=1;;m++){
        // 任选一个作为基准
		if(P[0]==ch[m-1])ch[m]=P[1];
		else ch[m]=P[0];
		for(int j=1;j<n;j++){
			// 该写法处共线点可能在或者不在凸包上，找到最右边的点
			Vector u=P[j]-ch[m-1],v=ch[m]-ch[m-1];
			if(dcmp(cross(u,v))>0){
				ch[m]=P[j];
				//ch[m].output();
			}
		}
		//ch[m].output();
		if(ch[m]==ch[0]) break;
	}
	return m;
}

void read_point(Point &A){
    scanf("%lf %lf",&A.x,&A.y);
}

int main(){
   //freopen("in.txt","r",stdin);
	int n,l;
	while(~scanf("%d %d",&n,&l)){
        for(int i=0;i<n;i++){
            read_point(P[i]);
        }
        n=volume_wrapping(P,n,ch);
        //cnt=volume_wrapping(P,n,ch);
        double ans=0;
        ch[n+1]=ch[0];
        for(int i=0;i<n;i++){
            ans+=len(ch[i+1]-ch[i]);
        }
        ans+=2*PI*l;
        printf("%.0f\n",ans);
	}
	return 0;
}






