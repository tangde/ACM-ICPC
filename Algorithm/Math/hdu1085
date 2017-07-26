// hdu1085 母函数
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn=10000;
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
	vector<int>w,nl(3,0);
	w.push_back(1);
	w.push_back(2);
	w.push_back(5);
	while(scanf("%d%d%d",&nl[0],&nl[1],&nl[2])&&(nl[0]||nl[1]||nl[2])){
		int P=nl[0]+2*nl[1]+5*nl[2];
		gen_function(w,nl,P);
		int ans;
		for(ans=1;;ans++)if(!a[ans])break;
		printf("%d\n",ans);
	}
	return 0;
}












