// poj3735
//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn=110;

struct Matrix{
	int n;
	LL mat[maxn][maxn];

	Matrix(int _n=0):n(_n){}

	void to_unit(){
		memset(mat,0,sizeof(mat));
		for(int i=0;i<n;i++)mat[i][i]=1;
	}

	Matrix operator*(const Matrix&x){
		Matrix res(n);
		memset(res.mat,0,sizeof(res.mat));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)if(mat[i][j]){ // 优化，不然回TLE
				for(int k=0;k<n;k++){
					res.mat[i][k]+=mat[i][j]*x.mat[j][k];
				}
			}
		}
		return res;
	}

	vector<LL> operator*(const vector<LL>&x){
		vector<LL>res(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				res[i]+=mat[i][j]*x[j];
			}
		}
		return res;
	}

	Matrix operator^(int b){
		Matrix res(n),a=*this;
		res.to_unit();
		while(b){
			if(b&1)res=res*a;
			a=a*a;
			b>>=1;
		}
		return res;
	}


};

int main(){
	int n,m,k,u,v;
	char ch;
	while(scanf("%d%d%d",&n,&m,&k)&&(n||m||k)){
		Matrix A(n+1);
		A.to_unit();
		while(k--){
			Matrix B(n+1);
			B.to_unit();
			cin>>ch;
			if(ch=='g'){
				scanf("%d",&u);
				B.mat[u-1][n]=1;
			}
			else if(ch=='e'){
				scanf("%d",&u);
				B.mat[u-1][u-1]=0;
			}
			else{
				scanf("%d%d",&u,&v);
				B.mat[u-1][u-1]=0,B.mat[v-1][u-1]=1;
				B.mat[v-1][v-1]=0,B.mat[u-1][v-1]=1;
			}
			A=B*A;
		}
		A=A^m;
		vector<LL>x(n+1);
		x[n]=1;
		x=A*x;

		int len=x.size();
		for(int i=0;i<len-1;i++){
			if(i!=len-2)printf("%lld ",x[i]);
			else printf("%lld\n",x[i]);
		}
	}

	return 0;
}









