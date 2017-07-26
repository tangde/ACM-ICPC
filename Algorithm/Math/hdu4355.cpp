// hdu4355
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn=100000;
const int iter=50;  // 迭代次数
double w[maxn],x[maxn];
int n;

double f(double y){
	double ans=0;
	for(int i=0;i<n;i++){
		double m=y-x[i];
		if(m<0)m=-m;
		ans+=m*m*m*w[i];
		//ans+=abs((y-x[i],3))*w[i]; // 用pow或者abs函数相当慢，会超
	}
	return ans;
}

double search(double l,double r){
	for(int i=0;i<iter;i++){
		double m1=(r-l)/3+l;
		double m2=r-(r-l)/3;
		if(f(m1)<f(m2))r=m2;
		else l=m1;
	}
	return f(l);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		scanf("%d",&n);
		double l=inf,r=-inf;
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&x[i],&w[i]);
			l=min(l,x[i]);
			r=max(r,x[i]);
		}
		double ans=search(l-1,r+1);
		printf("Case #%d: %.0f\n",kase,ans);
	}
    return 0;
}






