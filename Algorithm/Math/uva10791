#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=46341+10;
int prime[maxn],p_cnt;
bool vis[maxn];

void sieve(int n){
	int m=sqrt(n+0.5);
	memset(vis,0,sizeof(vis));
	for(int i=2;i<=m;i++)if(!vis[i]){
		for(int j=i*i;j<=n;j+=i){
			vis[j]=1;
		}
	}
}

int gen_primes(int n){
	sieve(n);
	int cnt=0;
	for(int i=2;i<=n;i++)if(!vis[i]){
		prime[cnt++]=i;
	}
	return cnt;
}

LL slove(int x){
	if(x==1)return 2;
	int ans=0,i=0,xx=x;
	int pnum=0;
	while(x>1&&i<p_cnt&&prime[i]<=xx){
		int t=1;
		bool flag=0;
		while(x%prime[i]==0){
			x/=prime[i];
			t*=prime[i];
			flag=1;
		}
		if(flag){
			pnum++;
			ans+=t;
		}
		i++;
	}
	if(pnum==0)return LL(x)+1;
	if(pnum==1&&x==1)return 1+LL(ans);
	else if(pnum==1&&x>1)return LL(x)+ans;
	else if(pnum>1&&x==1)return ans;
	else return x+(LL)ans;
}

int main(){
	p_cnt=gen_primes(maxn);
	int x,kase=1;
	while(scanf("%d",&x)&&x){
		LL ans=slove(x);
		cout<<"Case "<<kase++<<": "<< ans<<endl;
	}
	return 0;
}










