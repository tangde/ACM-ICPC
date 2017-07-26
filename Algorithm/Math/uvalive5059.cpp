//uvalive 5059
#include<bits/stdc++.h>
using namespace std;

long long SG(long long x){
	if(x&1)return SG(x>>1);
	else return x>>1;
}
int main(){
	long long x;
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		long long v=0;
		for(int i=0;i<n;i++){
			scanf("%lld",&x);
			v^=SG(x);
		}
		if(v)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}





