// 1017 Doubloon Game
// 打表找规律
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
int k;
int SG(int x){
	if(k&1) return x&1;
	int t=x%(k+1);
	if(t==k) return 2;
	if(t&1) return 1;
	else return 0;
}
int main(){
	int T,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&s,&k);
		if(SG(s)==0) puts("0");
		else{
			ll i;
			for(i=1;i<=s;i*=k){
				if(SG(s-i)==0) break;
			}
			printf("%lld\n",i);
		}
	}
	return 0;
}



