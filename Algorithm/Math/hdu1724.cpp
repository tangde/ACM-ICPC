// hdu1724
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100;
double a,b;
double f(double x){
	return b/a*sqrt(a*a-x*x);
}
// 三点Simpson法
double simpson(double a,double b){
	double m=(a+b)/2;
	return (f(a)+4*f(m)+f(b))*(b-a)/6;
}

// 自适应Simpson公式（递归过程）
double asr(double a,double b,double eps,double A){
	double m=(a+b)/2;
	double L=simpson(a,m),R=simpson(m,b);
	if(abs(L+R-A)<=15*eps)return L+R+(L+R-A)/15.0;
	return asr(a,m,eps/2,L)+asr(m,b,eps/2,R);
}
// 主过程
double asr(double a,double b,double eps){
	return asr(a,b,eps,simpson(a,b));
}
int main(){
	double l,r;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf%lf",&a,&b,&l,&r);
		double ans=2*asr(l,r,1e-4);
		printf("%.3f\n",ans);
	}
    return 0;
}






