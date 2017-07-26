//hdu1850,Nim游戏
#include<bits/stdc++.h>
using namespace std;
int s[110];
int main(){
	int m;
	while(scanf("%d",&m)&&m){
		int res=0;
		for(int i=0;i<m;i++){
			scanf("%d",&s[i]);
			res^=s[i];
		}
		if(!res) puts("0");
		else{
			int cnt=0;
			for(int i=0;i<m;i++){
				if((s[i]^res)<s[i])cnt++;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}

