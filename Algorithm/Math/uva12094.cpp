// uva10294 ploya计数
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn=50+10;
LL p[maxn];
int main(){
	int n,t;
	p[0]=1;
	while(~scanf("%d%d",&n,&t)){
		for(int i=1;i<maxn;i++)p[i]=p[i-1]*t;
		LL a=0,b=0;
		for(int i=0;i<n;i++)a+=p[__gcd(n,i)];
		if(n&1)b=n*p[(n+1)>>1];
		else b=(n>>1)*(p[n/2+1]+p[n/2]);
		printf("%lld %lld\n",a/n,(a+b)/(2*n));
	}
	return 0;
}












