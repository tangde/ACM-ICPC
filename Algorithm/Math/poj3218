// 置换群poj3128
// #include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;

int main(){
	char s[30];
	int cnt[30],n;
	bool vis[30];
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<26;i++)if(!vis[i]){
			int l=0,j=i;
			while(!vis[j]){
				l++;
				vis[j]=1;
				j=s[j]-'A';
			}
			cnt[l]++;
		}
		int i;
		for( i=2;i<=26;i+=2){
			if(cnt[i]&1)break;
		}
		if(i<=26)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}


