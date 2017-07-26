// hdu2298 求根
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long LL;
#include<complex>
double const PI=acos(-1.0);
const int maxn=1<<20;
const double eps=1e-6;
double x,y,v;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf",&x,&y,&v);
		if(x==0.0&&y>0.0){
			if(y<=v*v/19.6)printf("%.6f",PI/2);
			else printf("-1\n");
			continue;
		}
		if(x==0.0&&y==0.0){printf("0.000000\n");continue;}
		double a=-4.9*x*x;
		double b=x*v*v;
		double c=-4.9*x*x-y*v*v;
		double theta=b*b-4*a*c;
		if(theta<0){printf("-1\n");continue;}
		double r1=(-b+sqrt(theta))/2/a;
		double r2=(-b-sqrt(theta))/2/a;
		if(r1<0)printf("%.6f\n",atan(r2));
		else printf("%.6f\n",atan(r1));
	}
    return 0;
}






