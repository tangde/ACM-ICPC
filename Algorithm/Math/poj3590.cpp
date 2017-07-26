// 置换群poj3590
// #include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long LL;
const int maxn=100+10;

int d[maxn][maxn];
int f[maxn];
// 计算可以得到的最大公倍数
int lcm(int a,int b){return a/__gcd(a,b)*b;}
int dp(int i,int j){
	if(j>i)return d[i][j]=0;
	if(j==1)return d[i][j]=i;
	if(d[i][j]>=0)return d[i][j];
	d[i][j]=0;
	for(int k=1;k<=i;k++){
		d[i][j]=max(d[i][j],lcm(k,dp(i-k,j-1)));
	}
	return d[i][j];
}

vector<int> prime_factors(int m){
	vector<int>res;
	int t;
	for(int i=2;(LL)i*i<=m;i++){
		t=1;
		while(m%i==0){
			t*=i;
			m/=i;
		}
		if(t>1)res.push_back(t);
	}
	if(m>1)res.push_back(m);
	return res;
}
void slove(int n){
	memset(d,-1,sizeof(d));
	int l=-1;
	for(int j=1;j<=n;j++){
		l=max(l,dp(n,j));
	}
	vector<int>factors=prime_factors(l);
	sort(factors.begin(),factors.end());
	int k=0,b=1;
	for(int i=0;i<factors.size();i++)k+=factors[i];
	k=n-k;   // 单位循环的个数
	while(k--){
		f[b]=b;
		b++;
	}
	for(int i=0;i<factors.size();i++){
		int m=factors[i],t=b;
		for(int j=0;j<m-1;j++){
			f[b]=b+1;
			b++;
		}
		f[b++]=t;
	}
	printf("%d",l);
	for(int i=1;i<=n;i++){
		printf(" %d",f[i]);
	}
	printf("\n");
}
int main(){
	int n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		slove(n);
	}
	return 0;
}








