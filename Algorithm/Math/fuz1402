// FZU1402
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

// n个方程：x = a[i] (mod m[i])
// 返回(x,M)
pair<LL,LL> chinese_remainder(const vector<int>&a,const vector<int>&m){
	int n=a.size();
	LL M =1,d,y,x=0;
	for(int i=0;i<n;i++) M *=m[i];
	for(int i=0;i<n;i++){
		LL w = M / m[i];
		// 返回的y为w在m[i]下的逆元
		extend_euclid(m[i],w,d,d,y);
		x = (x+y*w*a[i])% M;
	}
	return make_pair((x+M)%M,M);
}

int main(){
	int k;
	while(scanf("%d",&k)!=EOF){
		vector<int>a(k),m(k);
		for(int i=0;i<k;i++){
				scanf("%lld%lld",&m[i],&a[i]);
		}
		//if(k==1){printf("%lld\n",a[0]+m[0]);continue;}
		pair<LL,LL>ans=chinese_remainder(a,m);
		if(ans.first==0)ans.first=ans.second;
		printf("%lld\n",ans.first);
	}
	return 0;
}

