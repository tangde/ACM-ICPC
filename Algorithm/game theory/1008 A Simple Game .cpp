//A Simple Game 
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,T,l,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int res=0;
		while(n--){
			scanf("%d %d",&m,&l);
			res^=(m%(l+1));
		}
		if(res) puts("No");
		else puts("Yes");
	}
	return 0;
}

