// poj2311
//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
using namespace std;
const int maxn=202;
int mex[maxn][maxn];

int SG(int w,int h){
	if(mex[w][h]!=-1)return mex[w][h];
	set<int>s;
	for(int i=2;w-i>=2;i++)s.insert(SG(i,h)^SG(w-i,h));
	for(int i=2;h-i>=2;i++)s.insert(SG(w,i)^SG(w,h-i));
	int g=0;
	while(s.count(g))g++;
	return mex[w][h]=mex[h][w]=g;
}
int main(){
	int w,h;
	memset(mex,-1,sizeof(mex));
	for(int i=1;i<=200;i++){
		for(int j=i;j<=200;j++)if(mex[i][j]==-1){
			SG(i,j);
		}
	}
	while(~scanf("%d%d",&w,&h)){
		if(mex[w][h])puts("WIN");
		else puts("LOSE");
	}
	return 0;
}

