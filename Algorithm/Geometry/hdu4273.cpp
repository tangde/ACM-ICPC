//poj1556
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
// 向量夹角
double angle(Vector3 A,Vector3 B){
	return acos(dot(A,B)/len(A)/len(B));
}
// 向量叉积
Vector3 cross(Vector3 A,Vector3 B){
	return Vector3(A.y*B.z-B.y*A.z,-(A.x*B.z-B.x*A.z),A.x*B.y-B.x*A.y);
}
// 点p到平面距离,平面任意一点为p0，法向量为n为单位向量
double distance_to_plane(Point3 p,Point3 p0,Vector3 n){
    return fabs(dot(p-p0,n));
}
// p0到平面p1p2p3距离(确保p1,p2,p3不共线)
double distance_to_plane(Point3 p,Point3 p1,Point3 p2,Point3 p3){
    Vector3 n=cross(p2-p1,p3-p1);
    n=n/len(n);
    return distance_to_plane(p,p1,n);
}
// 四面体的重心
Point3 centroid(Point3 A, Point3 B, Point3 C,Point3 D) {
	return (A + B + C + D)/4.0;
}
//四面体的有向体积的6倍
double Volume6(Point3 A,Point3 B,Point3 C,Point3 D){
    return dot(D-A,cross(B-A,C-A));
}

struct Face{
    int v[3];
    Face(int a=0,int b=1,int c=2){ v[0]=a,v[1]=b,v[2]=c; }
    Vector3 normal(Point3*P)const{ // 法向量
        return cross(P[v[1]]-P[v[0]],P[v[2]]-P[v[0]]);
    }
    int cansee(Point3*P,int i)const{
        return dot(P[i]-P[v[0]],normal(P))>0?1:0;
    }
};

// 重心
Point3 polyhedron_mass(const vector<Face>&f,Point3 *P){
    Point3 mass(0,0,0),A=Point3(0,0,0);
    double vol=0;
    for(int i=0;i<f.size();i++){
        int a=f[i].v[0],b=f[i].v[1],c=f[i].v[2];
        /*
        P[a].output();
        P[b].output();
        P[c].output();
        A.output();*/
        double v=Volume6(A,P[a],P[b],P[c]);
       // cout<<v<<endl<<endl;
        vol+=v;
        mass=mass+centroid(A,P[a],P[b],P[c])*v;
    }
    if(dcmp(vol)==0)return mass;
    else return mass/vol;
}

int vis[300][300];
// 增量法求三维凸包
// 没有考虑特殊情况（如4点共面），实际中请将输入点进行微小扰动
vector<Face> convexHull3D(Point3*P,int n){
    vector<Face> cur;
    // 前三个点不公线（已经扰动过）
    cur.push_back(Face(0,1,2));
    cur.push_back(Face(2,1,0));
    for(int i=3;i<n;i++){
        vector<Face>next;
        // 计算每条边左边的克见性
        for(int j=0;j<cur.size();j++){
            Face&f=cur[j];
            int res=f.cansee(P,i);
            if(!res) next.push_back(f);
            for(int k=0;k<3;k++){
                vis[f.v[k]][f.v[(k+1)%3]]=res; // 标记是否可见
            }
        }
        for(int j=0;j<cur.size();j++){
            for(int k=0;k<3;k++){
                int a=cur[j].v[k],b=cur[j].v[(k+1)%3];
                if(vis[a][b]!=vis[b][a]&&vis[a][b]) // (a,b)是分界线，左边对P[i]可见
                    next.push_back(Face(a,b,i));
            }
        }
        cur=next;
    }
    return cur;
}

double rand01(){return rand()/(double)RAND_MAX; } // 0到1之间随机数
double randeps(){return (rand01()-0.5)*eps;} // -eps/2到eps/2之间
// 扰动点
Point3 add_noise(Point3 p){
    return Point3(p.x+randeps(),p.y+randeps(),p.z+randeps());
}

void read_point(Point3&A){
    scanf("%lf %lf %lf",&A.x,&A.y,&A.z);
}

Point3 P[1000],P1[1000];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;i++){
            read_point(P[i]);
        }
        // 去除重复点
        n=unique(P,P+n)-P;
        // 加入干扰
        for(int i=0;i<n;i++){
            P1[i]=add_noise(P[i]);
        }
        vector<Face> f=convexHull3D(P1,n);
        Point3 mass=polyhedron_mass(f,P);
        double ans=1e20;
        for(int i=0;i<f.size();i++){
            int a=f[i].v[0],b=f[i].v[1],c=f[i].v[2];
            ans=min(ans,distance_to_plane(mass,P[a],P[b],P[c]));
        }
        printf("%.3f\n",ans);
    }
    return 0;
}











