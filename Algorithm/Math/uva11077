// 置换群poj11077
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
typedef unsigned long long ULL;
const int maxn=100+10;

ULL f[30][30];
int main(){
	int n,k;
	memset(f,0,sizeof(f));
	f[1][0]=1;
	for(int i =2;i<=21;i++){
		for(int j=0;j<i;j++){
			f[i][j]=f[i-1][j];
			if(j>0)f[i][j]+=f[i-1][j-1]*(i-1);
		}
	}
	while(~scanf("%d%d",&n,&k)&&n){
		cout<<f[n][k]<<endl;
	}
	return 0;
}
