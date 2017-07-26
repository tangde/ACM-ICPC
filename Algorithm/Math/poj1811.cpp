// poj1811
//#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<ctime>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

long long mult_mod(long long a,long long b,long long n){
	long long res=0;
	a%=n;
	while(b){
		if(b&1)res=(res+a)%n;
		b>>=1;
		a=(a<<1)%n;
	}
	return res;
}

long long quick_mod(long long a,long long b,long long n){
	long long res=1;
	while(b){
		if(b&1)res=mult_mod(res,a,n);
		a=mult_mod(a,a,n);
		b>>=1;
	}
	return res;
}

bool miller_rabin(long long n,int s){
	if(n<2)return false;
	if(n==2)return true;
	if(!(n&1))return false;
	long long m=n-1,j,k=0;
	while(!(m&1))m>>=1,k++;
	//srand((long long)time(0));
	srand(19260817);
	for(int i=0;i<s;i++){
		long long x=rand()%(n-2)+2; // [2,n)中的数
		long long a=quick_mod(x,m,n);
		if(a==1)continue;
		// 平方探测
		for(j=0;j<k;j++){
			if(a==n-1)break;
			a=mult_mod(a,a,n);
		}
		if(j==k)return false;
	}
	return true;
}

long long pollard_rho(long long n,long long c){
	long long x,y,k=2,i=1;
	//srand((long long)time(0));
	srand(19260817);
	y=x=rand()%n;
	do{
		i++;
		long long d=__gcd(y-x,n);
		if(d>1&&d<n)return d;
		if(i==k)k<<=1,y=x;
		x=(mult_mod(x,x,n)+c)%n;

	}while(y!=x);
	return n;
}

void find(long long n,map<long long,int>&factors){
	if(n==1)return;
	if(miller_rabin(n,50)){
		factors[n]++;
		return;
	}
	long long p=n;
	//srand((long long)time(0));
	srand(19280637);
	while(p>=n) p=pollard_rho(n,rand()%(n-1)+1);
	find(p,factors);
	find(n/p,factors);
}

int main(){
	long long n;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		map<long long,int>factors;
		if(miller_rabin(n,50))printf("Prime\n");
		else{
			find(n,factors);
			printf("%lld\n",factors.begin()->first);
		}

	}
	return 0;
}
