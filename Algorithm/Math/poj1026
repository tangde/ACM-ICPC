// 置换群poj1026
// #include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long LL;
const int maxn=200+10;

vector<int>cir[maxn];  //循环节
int cir_cnt;          //循环节个数

int f[maxn],n,k;
char s[maxn];
bool cheek[maxn];

int main(){
	while(scanf("%d",&n)&&n){
		for(int i=0;i<n;i++){
			scanf("%d",&f[i]);
			f[i]--;
		}
		cir_cnt=0;
		memset(cheek,0,sizeof(cheek));
		for(int i=0;i<n;i++)if(!cheek[i]){
			cir[cir_cnt].clear();
			int k=i;
			while(!cheek[k]){
				cheek[k]=true;
				cir[cir_cnt].push_back(k);
				k=f[k];
			}
			cir_cnt++;
		}
		char ans[maxn];
		ans[n]='\0';
		while(~scanf("%d",&k)&&k){
			gets(s);
			for(int i=0;i<strlen(s)-1;i++)s[i]=s[i+1];
			s[strlen(s)-1]='\0';
			for(int i=strlen(s);i<n;i++)s[i]=' ';
			s[n]='\0';
			for(int i=0;i<cir_cnt;i++){
				int len=cir[i].size();
				for(int j=0;j<len;j++){
					ans[cir[i][(j+k)%len]]=s[cir[i][j]];
				}
			}
			printf("%s\n",ans);
		}
		printf("\n");
	}
	return 0;
}


