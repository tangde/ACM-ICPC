// hdu2152 母函数
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn=260000;
// w[i]和nl[i]分别为第i个因子的权重和最大个数
// P 为可能的最大指数,P=sigma(w[i]*nl[i])
// a[i]保存结果，表示x^i的系数
int a[maxn],b[maxn];
void gen_function(vector<int>&w,vector<int>&nl0,vector<int>&nl,int P){
	memset(a,0,sizeof(a));
	a[0]=1;
	for(int i=0;i<nl.size();i++)if(nl[i]){
		memset(b,0,sizeof(b));
		for(int j=0;j<=P;j++){
			for(int k=nl0[i];k<=nl[i]&&k*w[i]+j<=P;k++){
				b[k*w[i]+j]+=a[j];
			}
		}
		memcpy(a,b,sizeof(b));
	}
}
int main(){
	vector<int>w,nl,nl0;
	int n,m,x,y;
	while(~scanf("%d%d",&n,&m)){
		nl.clear();w.clear();nl0.clear();
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			w.push_back(1);
			nl0.push_back(x);
			nl.push_back(y);
		}
		gen_function(w,nl0,nl,m);
		printf("%d\n",a[m]);
	}
	return 0;
}












