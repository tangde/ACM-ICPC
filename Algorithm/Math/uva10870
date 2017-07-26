// uva10870 矩阵递推
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
typedef  long long LL;
const int maxn=100+10;

// n*n的方阵
struct Matrix{
	const static int N=50;
	int mat[N][N];
	int n,P;

	Matrix(int m,int p):n(m),P(p){};

	void init(int *a,int d){
		n=d;
		memset(mat,0,sizeof(mat));
		for(int i=0;i<n-1;i++)mat[i][i+1]=1;
		for(int j=0;j<n;j++)mat[n-1][j]=a[n-1-j];
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
		Matrix ans=*this,a=*this;
		ans.to_unit_matrix();
		while(b){
			if(b&1) ans=ans*a;
			b>>=1;
			a=a*a;
		}
		return ans;
	}

	// 求f[m]
	int slove(int *f,int m){
		if(m<n)return f[m-1];
		Matrix A=(*this)^(m-n);
		int res=0;
		for(int j=0;j<n;j++){
			res=(res+(LL)f[j]*A.mat[n-1][j])%P;
		}
		return res;
	}

};

int a[20];
int f[maxn];
int main(){
	int d,m,n;
	while(scanf("%d%d%d",&d,&n,&m)&&d){
		for(int i=0;i<d;i++)scanf("%d",&a[i]);
		for(int i=0;i<d;i++){
			scanf("%d",&f[i]);
			f[i]%=m;
		}
		Matrix slover(d,m);
		slover.init(a,d);
		int ans=slover.slove(f,n);
		printf("%d\n",ans);
	}
	return 0;
}








