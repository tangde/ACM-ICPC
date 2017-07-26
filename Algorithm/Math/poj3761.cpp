// poj3761
//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000000+10;
const int mod =20100713;

int a[maxn];  // 阶乘表
int quick_mod(int a,int b,int P){
	int ans=1;
	while(b){
		if(b&1)ans=(long long)ans*a%P;
		b>>=1;
		a=(long long)a*a%P;
	}
	return ans;
}

void gen_table(){
	a[0]=1;
	for(int i=1;i<maxn;i++){
		a[i]=(long long)a[i-1]*i%mod;
	}
}

int main(){
	int T,n,k;
	gen_table();
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		int ans=(long long)(quick_mod(k+1,n-k,mod)-quick_mod(k,n-k,mod))*a[k]%mod;
		ans=(ans+mod)%mod;
		printf("%d\n",ans);
	}
	return 0;
}












