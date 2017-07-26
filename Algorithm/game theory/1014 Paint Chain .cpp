// 1014 Paint Chain 
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int sg[1010];
int SG(int x,int m){
	if(x<m) return sg[x]=0;
    if(sg[x]>=0) return sg[x];
    int Hash[1010]={0};
    for(int i=0;i+m<=x;i++){
    	Hash[SG(i,m)^SG(x-m-i,m)]=1;
    }
    sg[x]=0;
    while(Hash[sg[x]]) sg[x]++;
    return sg[x];
}

int main(){
	int n,m,T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		scanf("%d %d",&n,&m);
		if(n<m){
			printf("Case #%d: abcdxyzk\n",kase);
			continue;
		}
		memset(sg,-1,sizeof(sg));
		int g=!SG(n-m,m);
		printf("Case #%d: ",kase);
		if(g) puts("aekdycoin");
		else puts("abcdxyzk");
	}
    return 0;
}




