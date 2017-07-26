// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cstdio>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn=50+10;
// 约数枚举O(sqrt(n))
vector<int> divisor(LL n){
	vector<int>res;
	for(LL i=1;i*i<=n;i++){
		if(n%i==0){
			res.push_back(i);
			if(i!=n/i)res.push_back(n/i);
		}
	}
	return res;
}

// 整数分解O(sqrt(n))
vector<int> prime_factor(LL n){
	vector<int>res;
	for(LL i=2;i*i<=n;i++){
		if(n%i==0)res.push_back(i);
		while(n%i==0){
			n/=i;
		}
	}
	if(n!=1)res.push_back(n);
	return res;
}

LL slove(LL n){
	vector<int>primes=prime_factor(n);

	vector<int>div=divisor(n);
	LL res=0;
	for(int i=0;i<div.size();i++){ //枚举约数
		LL phi=1,d=n/div[i];
		for(int i=0;i<primes.size();i++){
			if(d%primes[i]==0){
				phi*=(primes[i]-1);
				d/=primes[i];
				while(d%primes[i]==0){
					d/=primes[i];
					phi*=primes[i];
				}
			}
		}
		res+=phi*div[i];
	}
	return res;
}
int main(){
	LL n;
	while(~scanf("%lld",&n)){
		LL ans=slove(n);
		printf("%lld\n",ans);
	}
	return 0;
}




