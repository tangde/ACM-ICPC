//1009 John
#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,n,a;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int g=0,cnt=0;
		while(n--){
			scanf("%d",&a);
			g^=a;
			if(a>1) cnt++;
		}
		if((!cnt&&!g)||(cnt&&g)) puts("John");
		else puts("Brother");
	}
	return 0;
}

