// hdu4135 容斥原理
#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
#define inf 0x3f3f3f3f
typedef long long LL;

//[1,m]中被factors中任何一个数整除的数的个数
// 如[1,m]的数中，能被2,3,5任一整除的整数个数
// 注意溢出问题，某些题目使用long long
LL slove(LL m,vector<int>&factors){
	LL res=0,len=factors.size();
	// 枚举子集
	for(int i=1;i<(1<<len);i++){
		int bits=0,mult=1;
		for(int j=0;j<len;j++)if(i&(1<<j)){
			bits++;
			mult*=factors[j];
		}
		if(bits&1)res+=m/mult; // 奇数个
		else res-=m/mult;
	}
	return res;
}

// 整数分解O(sqrt(n))
map<int,int> prime_factor(int n){
	map<int,int>res;
	for(int i=2;i*i<=n;i++){
		while(n%i==0){
			res[i]++;
			n/=i;
		}
	}
	if(n!=1)res[n]=1;
	return res;
}

int main(){
	int T,n;
	LL a,b;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		scanf("%lld %lld %d",&a,&b,&n);
		map<int,int>primes=prime_factor(n);
		vector<int>fractors;
		for(map<int,int>::iterator it=primes.begin();it!=primes.end();it++){
			fractors.push_back(it->first);
		}
		LL rb=b-slove(b,fractors);
		LL ra=a-1-slove(a-1,fractors);
		LL ans=rb-ra;
		printf("Case #%d: %lld\n",kase,ans);
	}
	return 0;
}












