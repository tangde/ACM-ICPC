// 置换群poj1721
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
const int maxn=1000+10;

int quick_mod(int a,int b,int n){
	int ans=1;
	while(b){
		if(b&1)ans=(LL)ans*a%n;
		b>>=1;
		a=(LL)a*a%n;
	}
	return ans;
}

bool check[maxn];
vector<int> cycle(int *f,int n){
	vector<int>res;
	memset(check,0,sizeof(check));
	for(int i=1;i<=n;i++)if(!check[i]){
		for(int k=i;!check[k];k=f[k]){
			res.push_back(k);
			check[k]=true;
		}
	}
	return res;
}

int f[maxn];
int main(){
	int n,k,m,s;
	while(~scanf("%d%d",&n,&s)){
		for(int i=1;i<=n;i++)scanf("%d",&f[i]);
		m=1;
		for(k=1;;k++){
			m=m*2%n;
			if(m==1)break;
		}
		int r=k-s%k;  //差的状态
		int t=quick_mod(2,r,n);
		vector<int>cyc=cycle(f,n);
		for(int i=0;i<n;i++){
			f[cyc[i]]=cyc[(i+t)%n];
		}
		for(int i=1;i<=n;i++)printf("%d\n",f[i]);
	}
	return 0;
}









