//hdu4643
#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
#define eps 1e-7
int n,m;
double crossSet[maxn*maxn];
int dcmp(double x){
	if(fabs(x)<eps)return 0;
	else return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y){}
}C[maxn],S[maxn];
typedef Point Vector;

Vector operator+(Vector A,Vector B){
	return Vector(A.x+B.x,A.y+B.y);
}
Vector operator-(Vector A,Vector B){
	return Vector(A.x-B.x,A.y-B.y);
}
Vector operator*(Vector A,double k){
	return Vector(A.x*k,A.x*k);
}
double dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}
struct Quadratic{
	double a,b,c;
	Quadratic(double _a=0,double _b=0,double _c=0):a(_a),b(_b),c(_c){}
};

double cross(Quadratic &Q1,Quadratic &Q2){
	if(dcmp(Q1.b-Q2.b)==0)return -1;
	return (Q2.c-Q1.c)/(Q1.b-Q2.b);
}

double get_value(Quadratic&Q,double t){
	return Q.a*t*t+Q.b*t+Q.c;
}
int get_min(vector<Quadratic>&Q,double t){
	int k=0;
	double Min=get_value(Q[0],t);
	for(int i=1;i<m;i++){
		double New=get_value(Q[i],t);
		if(dcmp(New-Min)<0){
			Min=New;
			k=i;
		}
	}
	return k;
}
int slove(int a,int b){
	vector<Quadratic>Q;
	Vector u=C[b]-C[a];
	for(int i=0;i<m;i++){
		Vector v=S[i]-C[a];
		Q.push_back(Quadratic(dot(u,u),-2*dot(u,v),dot(v,v)));
	}
	crossSet[0]=0;
	int cnt=1;
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			double t=cross(Q[i],Q[j]);
			if(dcmp(t)<0||dcmp(t-1)>0)continue;
			crossSet[cnt++]=t;
		}
	}
	crossSet[cnt++]=1;
	sort(crossSet,crossSet+cnt);
	cnt = unique(crossSet,crossSet+cnt)-crossSet;
	set<int>s;
	for(int i=0;i<cnt-1;i++){
		double t=(crossSet[i]+crossSet[i+1])/2;
		int k=get_min(Q,t);
		s.insert(k);
	}
	return s.size()-1;
}
void read_point(Point &A){
	scanf("%lf %lf",&A.x,&A.y);
}
int main(){
	int q,a,b;
	while(~scanf("%d %d",&n,&m)){
		for(int i=0;i<n;i++){
			read_point(C[i]);
		}
		for(int i=0;i<m;i++){
			read_point(S[i]);
		}
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&a,&b);
			printf("%d\n",slove(a-1,b-1));
		}
	}
	return 0;
}








