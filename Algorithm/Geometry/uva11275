//uva11275
#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<cmath>
#define inf 0x3f3f3f3f
using namespace std;
const double eps=1e-8;
int dcmp(double x){
	if(fabs(x)<eps)return 0;
	else return x<0?-1:1;
}
struct Point3{
	double x,y,z;
	Point3(double _x=0,double _y=0,double _z=0):x(_x),y(_y),z(_z){}
	void output(){
        printf("( %.2f , %.2f , %.2f )\n",x,y,z);
	}
};
typedef Point3 Vector3;        // Vector是Point的别名，表示向量
// 向量+向量
Vector3 operator+(Vector3 A,Vector3 B){
	return Vector3(A.x+B.x,A.y+B.y,A.z+B.z);
}
// 向量-向量
Vector3 operator-(Vector3 A,Vector3 B){
	return Vector3(A.x-B.x,A.y-B.y,A.z-B.z);
}
// 向量*数值
Vector3 operator*(Vector3 A,double k){
	return Vector3(A.x*k,A.y*k,A.z*k);
}
// 向量/数值
Vector3 operator/(Vector3 A,double k){
	return Vector3(A.x/k,A.y/k,A.z/k);
}

// 点相等
bool operator==(Point3 a,Point3 b){
	return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0&&dcmp(a.z-b.z)==0;
}

// 向量内积
double dot(Vector3 A,Vector3 B){
	return A.x*B.x+A.y*B.y+A.z*B.z;
}
// 向量长度
double len(Vector3 A){
	return sqrt(dot(A,A));
}

// 向量叉积
Vector3 cross(Vector3 A,Vector3 B){
	return Vector3(A.y*B.z-B.y*A.z,-(A.x*B.z-B.x*A.z),A.x*B.y-B.x*A.y);
}

// 空间三角形状面积
double area2(Point3 A,Point3 B,Point3 C){
    return len(cross(B-A,C-A));
}
// 点P在三角形P0P1P2中
bool point_in_tri(Point3 P,Point3 P0,Point3 P1,Point3 P2){
    // 先判断是否共面
    double t=dot(P0-P,cross(P1-P,P2-P));
    if(dcmp(t)!=0) return false;
    double a1=area2(P,P0,P1);
    double a2=area2(P,P0,P2);
    double a3=area2(P,P1,P2);
    return dcmp(a1+a2+a3-area2(P0,P1,P2))==0;
}

// 线段AB是否和三角形P0P1P2相交（这里是和三角形区域相交），平行或者共面返回0
bool seg_tri_intersection(Point3 P0,Point3 P1,Point3 P2,Point3 A,Point3 B,Point3&P){
    Vector3 n=cross(P1-P0,P2-P0); // 三角形所在平面法向量
    if(dcmp(dot(n,B-A))==0) return false;  // 线段AB和三角形共面或平行
    double t=dot(n,P0-A)/dot(n,B-A);
    if(dcmp(t)<0||dcmp(t-1)>0) return false; // 交点不在线段AB上
    P=A+(B-A)*t;
    return point_in_tri(P,P0,P1,P2); // 判断交点是否在三角形中
}
// 判断三角形是否相交
bool tri_tri_intersection(Point3*tri1,Point3*tri2){
    Point3 P;
    for(int i=0;i<3;i++){
        if(seg_tri_intersection(tri2[0],tri2[1],tri2[2],tri1[i],tri1[(i+1)%3],P))
            return true;
        //if(seg_tri_intersection(tri1[0],tri1[1],tri1[2],tri2[i],tri2[(i+1)%3],P))
       //     return true;
    }
    return false;
}

void read_point3(Point3&A){
    scanf("%lf %lf %lf",&A.x,&A.y,&A.z);
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        Point3 tri1[3];
        Point3 tri2[3];
        for(int i=0;i<3;i++){
            read_point3(tri1[i]);
        }
        for(int i=0;i<3;i++){
            read_point3(tri2[i]);
        }
        if(tri_tri_intersection(tri1,tri2)) puts("1");
        else puts("0");
    }
    return 0;
}




