// hdu2082 母函数
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn=121;
// w[i]和nl[i]分别为第i个因子的权重和最大个数
// P 为可能的最大指数
// a[i]保存结果，表示x^i的系数
int a[maxn],b[maxn];
void gen_function(vector<int>&w,vector<int>&nl,int P){
	memset(a,0,sizeof(a));
	a[0]=1;
	for(int i=0;i<nl.size();i++)if(nl[i]){
		memset(b,0,sizeof(b));
		for(int j=0;j<=P;j++){
			for(int k=0;k<=nl[i]&&k*w[i]+j<=P;k++){
				b[k*w[i]+j]+=a[j];
			}
		}
		memcpy(a,b,sizeof(b));
	}
}
int main(){
	vector<int>w,nl;
	int x,kase;
	for(int i=1;i<=26;i++)w.push_back(i);
	scanf("%d",&kase);
	while(kase--){
		nl.clear();
		for(int i=0;i<26;i++){
			scanf("%d",&x);
			nl.push_back(x);
		}
		gen_function(w,nl,50);
		int ans=0;
		for(int i=1;i<=50;i++)ans+=a[i];
		printf("%d\n",ans);
	}
	return 0;
}












