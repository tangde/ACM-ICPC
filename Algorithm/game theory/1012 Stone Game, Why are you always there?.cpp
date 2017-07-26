//1012 Stone Game, Why are you always there?
#include<bits/stdc++.h>
using namespace std;
int sg[1010],a[1010],n;
int SG(int x){
	if(x<a[0]) return sg[x]=0;
	if(sg[x]>=0) return sg[x];
	int Hash[1010]={0};
	for(int i=0;i<n&&a[i]<=x;i++){
		for(int j=0;j+a[i]<=x;j++){
			Hash[SG(j)^SG(x-j-a[i])]=1;
		}
	}
	sg[x]=0;
	while(Hash[sg[x]]) sg[x]++;
	return sg[x];
}

int main(){
	int m,x;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		n=unique(a,a+n)-a;
		scanf("%d",&m);
		memset(sg,-1,sizeof(sg));
		while(m--){
			scanf("%d",&x);
			if(SG(x)) puts("1");
			else puts("2");
		}
	}
	return 0;
}





