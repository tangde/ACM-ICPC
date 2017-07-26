#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
int prime[maxn],p_cnt;
int p,q,r,s;
int reslove[maxn];
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

void addFractors(int x,int diff){
	while(x>1){
		int t=x,i=0;
		while(t>1){
			while(t%prime[i]==0){
				reslove[prime[i]]+=diff;
				t/=prime[i];
			}
			i++;
		}
		x--;
	}
}

double slove(){
	memset(reslove,0,sizeof(reslove));
	addFractors(p,1);
	addFractors(s,1);
	addFractors(r-s,1);
	addFractors(q,-1);
	addFractors(r,-1);
	addFractors(p-q,-1);
	double ans=1.00;
	for(int i=0;i<maxn;i++)if(reslove[i]){
		ans*=pow(i,reslove[i]);
	}
	return ans;
}

int main(){
	p_cnt=gen_primes(10000);
	while(~scanf("%d%d%d%d",&p,&q,&r,&s)){
		double ans=slove();
		printf("%.5lf\n",ans);
	}
	return 0;
}










