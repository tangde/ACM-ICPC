//hdu1905
//#include<bits/stdc++.h>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long LL;

LL mult_mod(LL a,LL b,LL n){
	LL exp=a%n,res=0;
	while(b){
		if(b&1)res=(res+exp)%n;
		exp=(exp<<1)%n;;
		b>>=1;
	}
	return res;
}

LL quick_mod(LL a,LL b,LL n){
	LL res=1;
	while(b){
		if(b&1)res=mult_mod(res,a,n);
		a=mult_mod(a,a,n);
		b>>=1;
	}
	return res;
}

bool miller_rabin(LL n,int s){
	if(n<2)return false;
	if(n==2)return true;
	if(!(n&1))return false;
	LL m=n-1,j,k=0;
	while(!(m&1))m>>=1,k++;
	srand((LL)time(0));
	for(int i=0;i<s;i++){
		LL x=rand()%(n-2)+2; // [2,n)中的数
		LL a=quick_mod(x,m,n);
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
LL p,a;
int main(){
	while(scanf("%lld%lld",&p,&a)&&p){
		if(quick_mod(a,p,p)==a&&!miller_rabin(p,100))printf("yes\n");
		else printf("no\n");
	}
	return 0;
}







