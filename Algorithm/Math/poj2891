// poj2891
//#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
typedef long long LL;
using namespace std;

void extend_euclid(LL a,LL b,LL &d,LL &x,LL &y){
	if(!b){d=a;x=1;y=0;}
	else{
		extend_euclid(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}

// 合并x=a1%m1,x=a2%m2,返回合并方程x=a%m
bool merge(LL a1,LL m1,LL a2,LL m2,LL &a,LL &m){
	LL x,y,g;
	LL d=__gcd(m1,m2);
	LL c=((a2-a1)%m2+m2)%m2;
	if(c%d)return false; // 无解
	c/=d,m1/=d,m2/=d;
	m=m1*m2*d;
	extend_euclid(m1,m2,g,x,y); // x返回m1在m2下的逆元
	LL k=(c*x%m2+m2)%m2;
	a=(k*d*m1+a1)%m;
	a=(a+m)%m;
	return true;
}

// n个方程：x = a[i] (mod m[i])
// 反回(x,M),无解返回(0,0);
pair<LL,LL> chinese_remainder2(const vector<LL>&a,const vector<LL>&m){
	int n=a.size();
	LL M=m[0],x=a[0];
	for(int i=1;i<n;i++){
		LL a1=x,m1=M;
		if(!merge(a1,m1,a[i],m[i],x,M)){
			return make_pair(0,0); // 无解
		}
	}
	return make_pair(x,M);
}

int main(){
	int k;
	while(scanf("%d",&k)!=EOF){
		vector<LL>a(k),m(k);
		for(int i=0;i<k;i++){
				scanf("%lld%lld",&m[i],&a[i]);
		}
		pair<LL,LL>ans=chinese_remainder2(a,m);
		if(!ans.first&&!ans.second)printf("-1\n");
		else printf("%lld\n",ans.first);
	}
	return 0;
}

