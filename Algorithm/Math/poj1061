// poj3735
//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long LL;

void extend_euclid(LL a,LL b,LL &d,LL &x,LL &y){
	if(!b){d=a;x=1;y=0;}
	else{
		extend_euclid(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}

// 求解: ax+by=m，化简方程，并返回基础解
bool indefinite_equation(LL &a,LL &b ,LL &m ,LL &x,LL&y){
	LL d;
	extend_euclid(a,b,d,x,y);
	if(m%d)return false;
	a/=d;b/=d;m/=d;
	x*=m;y*=m;
	return true;
}

int main(){
	LL x,y,n,m,l;
	while(~scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l)){
		LL a=m-n,b=l,m=y-x;
		bool ok=indefinite_equation(a,b,m,x,y);
		if(!ok){printf("Impossible\n");continue;}
		if(b<0)b=-b;
		x=(x%b+b)%b;
		printf("%lld\n",x);
	}
	return 0;
}









