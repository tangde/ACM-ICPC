// uva11582 
// 坑1:0<=a,b<2^64,所以必须用unsigned long long 
// 坑2：a=0,b=0时候无意义，特殊处理
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int maxn=1002;
ULL f[maxn*maxn];

ULL init(int n){
	f[0]=0;f[1]=1;
	int i;
	for(i=2;i<n*n+n;i++){
		f[i]=(f[i-1]+f[i-2])%n;
		if(f[i]==1&&f[i-1]==0)break;
	}
	return ULL(i-1);
}

int quick_mod(ULL a,ULL b,ULL m){
	ULL ans=1;
	while(b){
		if(b&1)ans=ans*(a%m)%m;
		a=(a%m)*(a%m)%m;
		b>>=1;
	}
	return (int)ans;
}

int main(){
	ULL a,b,n;
	int kase;
	scanf("%d",&kase);
	while(kase--){
		cin>>a>>b>>n;
		ULL T=init(n);
		int ans=quick_mod(a,b,T);
		if(a==0||n==1)cout<<0<<endl;
		else cout<<f[ans]<<endl;
	}
	return 0;
}










