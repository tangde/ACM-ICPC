// hdu1171 母函数
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn=260000;
// w[i]和nl[i]分别为第i个因子的权重和最大个数
// P 为可能的最大指数,P=sigma(w[i]*nl[i])
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
	int n,c,m,P;
	while(~scanf("%d",&n)&&n>=0){
		nl.clear();w.clear();
		P=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&c,&m);
			w.push_back(c);
			nl.push_back(m);
			P+=m*c;
		}
		gen_function(w,nl,P);
		int x=(P+1)/2;
		while(!a[x])x++;
		printf("%d %d\n",x,P-x);
	}
	return 0;
}












