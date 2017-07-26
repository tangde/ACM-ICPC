// hdu1695莫比乌斯反演
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn=100000+10;

bool cheek[maxn];
int prime[maxn],mu[maxn];
void gen_moebius(int n){
	memset(cheek,0,sizeof(cheek));
	mu[1]=1;
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(!cheek[i]){
			prime[cnt++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<cnt;j++){
			if(i*prime[j]>n)break;
			cheek[i*prime[j]]=true;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}
			else mu[i*prime[j]]=-mu[i];
		}
	}
}

LL F(LL x,LL m,LL n){
	m/=x;n/=x;
	if(m>n)swap(m,n);
	return (2*n-m+1)*m/2;
}
int main(){
	int T,kase,a,b,c,d,k;
	gen_moebius(maxn-10);
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		if(k==0){printf("Case %d: 0\n",kase);continue;}
		b/=k;d/=k;
		if(b>d)swap(b,d);
		LL ans=0;
		for(int i=1;i<=b;i++){
			ans+=mu[i]*F(i,b,d);
		}
		printf("Case %d: %lld\n",kase,ans);
	}
	return 0;
}












