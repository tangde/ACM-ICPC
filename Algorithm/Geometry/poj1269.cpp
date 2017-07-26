//poj1269
//ſ#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
using namespace std;
#define PI acos(-1.0)
#define eps 1e-6
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
// 破甲向量/数值
Vector operator/(Vector A,double k){
    return Vector(A.x/k,A.y/k);
}
// 点相等
bool operator==(Point a,Point b){
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}

bool operator<(Point a,Point b){
    if(dcmp(a.x-b.x)!=0) return dcmp(a.x-b.x)<0;
    else return dcmp(a.y-b.y)<0;
}
// 向量内积
double dot(Vector A,Vector B){
    return A.x*B.x+A.y*B.y;
}
// 向量叉积
double cross(Vector A,Vector B){
    return A.x*B.y-B.x*A.y;
}


int read_point(Point &A){
    return scanf("%lf %lf",&A.x,&A.y);
}
// 判断线段是否规范相交
// 直线AB与CD交点，（需要保证只有唯一交点）
Point get_line_intersection(Point A,Point B,Point C,Point D){
	Vector v=B-A,w=D-C,u=A-C;
	double t=cross(w,u)/cross(v,w);
	return A+v*t;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)==1){
        puts("INTERSECTING LINES OUTPUT");
        while(n--){
            Point A,B,C,D;
            read_point(A);
            read_point(B);
            read_point(C);
            read_point(D);
            if(dcmp(cross(B-A,C-D))==0){
                if(dcmp(cross(B-A,C-A))==0)puts("LINE");
                else puts("NONE");
            }else{
                Point crossPoint=get_line_intersection(A,B,C,D);
                printf("POINT %.2f %.2f\n",crossPoint.x,crossPoint.y);
            }
        }
        puts("END OF OUTPUT");
    }
    return 0;
}


















