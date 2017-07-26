// poj2407
//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int phi(int n){
	int res=1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			res*=(i-1);
			n/=i;
		}
		while(n%i==0){
			res*=i;
			n/=i;
		}
	}
	if(n>1)res*=(n-1);
	return res;
}
int main(){
	int n;
	while(scanf("%d",&n)&&n){
		printf("%d\n",phi(n));
	}

	return 0;
}









