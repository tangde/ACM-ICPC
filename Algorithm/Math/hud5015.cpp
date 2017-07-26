//hdu5015
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long LL;
const int maxn=100+10;

const int P=1e7+7;
struct Matrix{
	const static int N=15;
	int mat[N][N];
	int n;

	Matrix(int m):n(m){};

	void init(int n){
		this->n=n;
		memset(mat,0,sizeof(mat));
		for(int i=0;i<n-1;i++){
			mat[i][0]=10;
			mat[i][n-1]=1;
		}
		for(int i=1;i<n-1;i++){
			for(int j=1;j<=i;j++)
				mat[i][j]=1;
		}
		mat[n-1][n-1]=1;
	}

	void to_unit_matrix(){
		memset(mat,0,sizeof(mat));
		for(int i=0;i<n;i++)mat[i][i]=1;
	}

	Matrix operator*(Matrix y){
		Matrix ans(y);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ans.mat[i][j]=0;
				for(int k=0;k<n;k++){
					ans.mat[i][j]+=(LL)mat[i][k]*y.mat[k][j]%P;
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
//
int slove(Matrix A, int *f,int m){
	int n=A.n;
	Matrix B=A^m;
	int res=0;
	for(int j=0;j<n;j++){
		res=(res+(LL)f[j]*B.mat[n-2][j])%P;
	}
	return (res+P)%P;
}

int f[20];
int main(){
	int n,m;
	f[0]=23;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++)scanf("%d",&f[i]);
		f[n+1]=3;
		Matrix A(n+2);
		A.init(n+2);
		int ans=slove(A,f,m);
		printf("%d\n",ans);
	}
	return 0;
}















