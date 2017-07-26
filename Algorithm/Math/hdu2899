// hdu2899
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100;
double a,b;
const double eps=1e-5;
double f(vector<double>&a,double x){
	double ans=0;
	int n=a.size();
	for(int i=0;i<n;i++){
		ans=ans*x+a[i];
	}
	return ans;
}

double newton(vector<double>&a,double x0){
	int n=a.size();
	vector<double>b(n-1);
	for(int i=0;i<n-1;i++){
		b[i]=(n-1-i)*a[i];         // 求导数
	}
	double x=x0;
	x0++;
	while(abs(x-x0)>eps){
		x0=x;
		x=x0-f(a,x0)/f(b,x0);
	}
	return x;
}
int main(){
	int T;
	vector<double>a(8,0),b(7,0);
	a[0]=6,a[1]=8,a[4]=7,a[5]=5;
	scanf("%d",&T);
	while(T--){
		scanf("%lf",&a[6]);
		a[6]=-a[6];
		double f1=f(a,0),f2=f(a,100);
		for(int i=0;i<7;i++)b[i]=(7-i)*a[i];
		if(f(b,0)*f(b,100)>=0){ // 没有根
			if(f1<f2)printf("%.4f\n",f1);
			else printf("%.4f\n",f2);
			continue;
		}
		double x=newton(b,5);
		printf("%.4f\n",f(a,x));
	}
    return 0;
}






