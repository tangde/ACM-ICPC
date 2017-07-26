//poj2653
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
bool segment_proper_intersection(Point A,Point B,Point C,Point D){
	double c1=cross(B-A,C-A),c2=cross(B-A,D-A),
			c3=cross(D-C,B-C),c4=cross(D-C,A-C);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
struct Node{
    int x;
    Node(int _x=0):x(_x),next(NULL){}
    Node*next;
}List;
Point s[100010],t[100010];
int main(){
    //freopen("in.txt","r",stdin);
    int n;
    Node*p,*pre;
    while(scanf("%d",&n)&&n){
        Node*List=new Node; // 空头链表
        for(int i=1;i<=n;i++){
            read_point(s[i]);
            read_point(t[i]);
            p=List->next,pre=List;
            while(p){
                int k=p->x;
                if(segment_proper_intersection(s[k],t[k],s[i],t[i])){
                    p=p->next;
                    pre->next=p;
                }
                else{
                    pre=p;
                    p=p->next;
                }
            }
            pre->next=new Node(i);
        }
        printf("Top sticks: ");
        p=List->next;
        while(p){
            if(!p->next) printf("%d.\n",p->x);
            else printf("%d, ",p->x);
            p=p->next;
        }
        while(List){
            p=List;
            List=List->next;
            delete p;
        }
    }
    return 0;
}


















