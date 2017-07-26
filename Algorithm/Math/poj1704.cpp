// poj1704
// #include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=10000+10;
int p[maxn];
void slove(int n){
	if(n&1)p[n++]=0;
	sort(p,p+n);
	int ans=0;
	for(int i=0;i+1<n;i+=2)
		ans^=(p[i+1]-p[i]-1);
	if(ans) puts("Georgia will win");
	else puts("Bob will win");
}

int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&p[i]);
		slove(n);
	}
	return 0;
}





