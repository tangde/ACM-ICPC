//poj2926
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;
#define eps 1e-8
const int maxn=100010;

double a[maxn][10];
double slove(int n,int dem){
	double ans=0;
	for(int s=0;s<(1<<dem);s++){
		double Min=1e20,Max=-1e20;
		for(int i=0;i<n;i++){
			double t=0;
			for(int j=0;j<dem;j++){
				if((1<<j)&s)t+=a[i][j];
				else t-=a[i][j];
			}
			Min=min(Min,t);
			Max=max(Max,t);
		}
		ans=max(ans,Max-Min);
	}
	return ans;
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			for(int j=0;j<5;j++){
				scanf("%lf",&a[i][j]);
			}
		}
		printf("%.2f\n",slove(n,5));
	}
	return 0;
}








