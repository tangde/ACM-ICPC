// hud4990
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long LL;
const int maxn=100+10;

int P;
struct Matrix{
	const static int N=3;
	int mat[N][N];
	int n;

	Matrix(int m):n(m){};

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

int f1[3]={1,5,1};
int f2[3]={0,2,2};
int slove(Matrix A,int n){
	if(n==1)return 1%P;
	else if(n==2)return 2%P;
	else if(n==3)return 5%P;
	Matrix B=A^((n-2)/2);
	int ans=0;
	if(n&1){
		for(int i=0;i<3;i++){
			ans=(ans+(LL)B.mat[1][i]*f1[i])%P;
		}
	}
	else{
		for(int i=0;i<3;i++){
			ans=(ans+(LL)B.mat[1][i]*f2[i])%P;
		}
	}
	return ans;
}
int main(){
	Matrix A(3);
	memset(A.mat,0,sizeof(A.mat));
	A.mat[0][1]=A.mat[1][2]=A.mat[2][2]=1;
	A.mat[1][1]=4;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		P=m;
		int ans=slove(A,n);
		printf("%d\n",ans);
	}
	return 0;
}















