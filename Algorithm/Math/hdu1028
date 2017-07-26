// hdu1028整数拆分
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn=121;
LL d[maxn][maxn];
LL dp(int n,int k){
	if(k>n)return 0;
	if(k==1||n==k)return d[n][k]=1;
	if(d[n][k]>=0)return d[n][k];
	LL ans=0;
	for(int i=1;i<=k;i++)ans+=dp(n-k,i);
	return d[n][k]=ans;
}
int main(){
	memset(d,-1,sizeof(d));
	for(int i=1;i<=120;i++)
		for(int j=1;j<=i;j++)dp(i,j);
	int n;
	while(~scanf("%d",&n)){
		LL tol=0;
		for(int k=1;k<=n;k++)tol+=d[n][k];
		printf("%lld\n",tol);
	}
	return 0;
}












