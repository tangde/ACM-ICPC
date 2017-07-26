//poj3449
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef vector<char> VC;
#define eps 1e-8
int dcmp(double x){
	if(fabs(x)<eps)return 0;
	else return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y){}
	void output(){
		printf("(%f,%f)\n",x,y);
	}
};
typedef Point Vector;
typedef vector<Point>Polygon;

Vector operator+(Vector A,Vector B){
	return Vector(A.x+B.x,A.y+B.y);
}
Vector operator-(Vector A,Vector B){
	return Vector(A.x-B.x,A.y-B.y);
}
Vector operator*(Vector A,double k){
	return Vector(A.x*k,A.y*k);
}
double dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}
double cross(Vector A,Vector B){
	return A.x*B.y-B.x*A.y;
}
double cross(Point a,Point b,Point c){
	return cross(b-a,c-a);
}
// 点P是否在线段上AB上(包含端点)
bool point_on_segment(Point A,Point B,Point P){
	return dcmp(cross(B-P,A-P))==0&&dcmp(dot(A-P,B-P))<=0;
}
// 判断线段是否相交
bool segment_intersection(Point A,Point B,Point C,Point D){
	if(point_on_segment(A,B,C)||point_on_segment(A,B,D)) return true;
	if(point_on_segment(C,D,A)||point_on_segment(C,D,B)) return true;
	double c1=cross(B-A,C-A),c2=cross(B-A,D-A),
			c3=cross(D-C,B-C),c4=cross(D-C,A-C);
	return dcmp(c1*c2)<0 &&dcmp(c3*c4)<0;
}
// 多边形，线段，三角形
Polygon input_polygon(int n){
	Polygon poly(n);
	for(int i=0;i<n;i++){
		scanf(" (%lf,%lf)",&poly[i].x,&poly[i].y);
	}
	return poly;
}
Polygon input_square(){
	Polygon poly(4);
	for(int i=0;i<3;i+=2){
		scanf(" (%lf,%lf)",&poly[i].x,&poly[i].y);
	}
	poly[1].x=(poly[0].x+poly[2].x+poly[2].y-poly[0].y)/2;
	poly[3].x=(poly[0].x+poly[2].x-poly[2].y+poly[0].y)/2;
	poly[1].y=(poly[0].x-poly[2].x+poly[2].y+poly[0].y)/2;
	poly[3].y=(-poly[0].x+poly[2].x+poly[2].y+poly[0].y)/2;
	return poly;
}
Polygon input_rectangle(){
	Polygon poly(4);
	for(int i=0;i<3;i++){
		scanf(" (%lf,%lf)",&poly[i].x,&poly[i].y);
	}
	poly[3]=poly[0]+poly[2]-poly[1];
	return poly;
}
bool is_intersect(Polygon&P1,Polygon&P2){
	int n=P1.size(),m=P2.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(segment_intersection(P1[i],P1[(i+1)%n],P2[j],P2[(j+1)%m])){
				return true;
			}
		}
	}
	return false;
}
map<char,Polygon> MP;
int main(){
	char ch;
	char s[30];
	int n,kase=1;
	while(cin>>ch&&ch!='.'){
		MP.clear();
		while(ch!='-'){
			scanf("%s",s);
			if(strcmp(s,"line")==0) MP[ch]=input_polygon(2);
			else if(strcmp(s,"square")==0) MP[ch]=input_square();
			else if(strcmp(s,"triangle")==0) MP[ch]=input_polygon(3);
			else if(strcmp(s,"rectangle")==0) MP[ch]=input_rectangle();
			else {
				scanf("%d",&n);
				MP[ch]=input_polygon(n);
			}
			cin>>ch;
		}
		if(kase++>1)printf("\n");
		map<char,Polygon>::iterator i,j;
		map<char,VC>ans;
		for(i=MP.begin();i!=MP.end();i++){
			for(j=MP.begin();j!=MP.end();j++)if(j!=i){
				if(is_intersect(i->second,j->second))
					ans[i->first].push_back(j->first);
			}
		}
		for(i=MP.begin();i!=MP.end();i++){
			char key=i->first;
			if(!ans.count(key)){
				printf("%c has no intersections\n",key);
				continue;
			}
			VC &v=ans[key];
			int m=v.size();
			if(m==1) printf("%c intersects with %c\n",key,v[0]);
			else if(m==2) printf("%c intersects with %c and %c\n",key,v[0],v[1]);
			else{
				printf("%c intersects with %c",key,v[0]);
				for(int i=1;i<m;i++){
					if(i==m-1)printf(", and %c\n",v[i]);
					else printf(", %c",v[i]);
				}
			}
		}
	}
	return 0;
}










