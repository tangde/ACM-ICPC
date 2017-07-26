// hdu1465错排
#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
#define inf 0x3f3f3f3f
typedef long long LL;

LL D[maxn];
int main(){
	int n;
	while(~scanf("%d",&n)){
		D[1]=0,D[2]=1;
		for(int i=3;i<=n;i++)
			D[i]=(i-1)*(D[i-1]+D[i-2]);
		printf("%lld\n",D[n]);
	}
	return 0;
}












