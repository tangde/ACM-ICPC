// hdu1695容斥原理
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn=2600000;
//[n,m]中能被factors中任何一个数整除的数的个数
//此时factors中所有数互质
LL inclusion_exclusion_principle(LL n,LL m,vector<int>&factors){
	n--;    // 应该是求m的减去n-1的
	LL resn=0,resm=0,len=factors.size();
	// 枚举子集
	for(int i=1;i<(1<<len);i++){
		int bits=0,mult=1;
		for(int j=0;j<len;j++)if(i&(1<<j)){
			bits++;
			mult*=factors[j];
		}
		if(bits&1){// 奇数个
			resm+=m/mult;
			resn+=n/mult;
		}
		else{
			resm-=m/mult;
			resn-=n/mult;
		}
	}
	return resm-resn;
}

// 整数分解O(sqrt(n))
vector<int> prime_factor(int n){
	vector<int>res;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)res.push_back(i);
		while(n%i==0){
			n/=i;
		}
	}
	if(n!=1)res.push_back(n);
	return res;
}

int main(){
	int T,kase,a,b,c,d,k;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		if(k==0){printf("Case %d: 0\n",kase);continue;}
		b/=k;d/=k;
		if(b>d)swap(b,d);
		LL ans=0;
		for(int i=1;i<=b;i++){
			vector<int>factors=prime_factor(i);
			ans+=d-i+1-inclusion_exclusion_principle(i,d,factors);
		}
		printf("Case %d: %lld\n",kase,ans);
	}
	return 0;
}












