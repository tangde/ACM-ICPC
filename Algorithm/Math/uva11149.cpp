// uva11149
// #include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f3f
typedef  long long LL;
const int maxn=100+10;

// n*n的方阵
struct Matrix{
	const static int N=50;
	const static int P=10;
	int mat[N][N];
	int n;

	Matrix(int m=0):n(m){}

	void to_unit_matrix(){
		memset(mat,0,sizeof(mat));
		for(int i=0;i<n;i++)mat[i][i]=1;
	}

	Matrix operator+(Matrix x){
		int n=x.n;
		Matrix ans(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ans.mat[i][j]=(x.mat[i][j]+mat[i][j])%P;
			}
		}
		return ans;
	}

	void output(){
		for(int i=0;i<n;i++){
			cout<<mat[i][0];
			for(int j=1;j<n;j++){
				cout<<" "<<mat[i][j];
			}
			cout<<endl;
		}
	}

	Matrix operator*(Matrix x){
		int n=x.n;
		Matrix ans(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ans.mat[i][j]=0;
				for(int k=0;k<n;k++){
					ans.mat[i][j]+=(LL)x.mat[i][k]*mat[k][j]%P;
					ans.mat[i][j]%=P;
				}
			}
		}
		return ans;
	}

	Matrix operator^(int b){
		Matrix ans(n),a=*this;
		ans.to_unit_matrix();
		while(b){
			if(b&1) ans=ans*a;
			b>>=1;
			a=a*a;
		}
		return ans;
	}
};

Matrix slove(Matrix a,int n){
	if(n==1)return a;
	Matrix temp=slove(a,n/2);
	Matrix x=a^(n/2);
	Matrix sum=temp+x*temp;
	if(n&1) return sum+a*x*x;
	else return sum;
}

int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)&&n){
		Matrix M(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&M.mat[i][j]);
				M.mat[i][j]%=10;
			}
		}
		Matrix ans=slove(M,k);
		ans.output();
		printf("\n");
	}
	return 0;
}








