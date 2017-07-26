// 置换群poj3270
// #include<bits/stdc++.h>
#include<cstdio>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long LL;
const int maxn=100000+10;

// 从 a[i]映射到b[i]
int a[maxn],ind[maxn],b[maxn];
bool check[maxn];

int main(){
	int n;
	while(~scanf("%d",&n)){
		int m=inf,sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			ind[a[i]]=i;
			b[i]=a[i];
			m=min(m,a[i]);
			sum+=a[i];
		}
		sort(b,b+n);
		memset(check,0,sizeof(check));
		for(int i=0;i<n;i++)if(!check[a[i]]){
			int t=inf,k=0;
			while(!check[a[i]]){
				check[a[i]]=true;
				t=min(a[i],t);
				k++;
				i=ind[b[i]];
			}
			sum+=min((k-2)*t,(k+1)*m+t);
		}
		printf("%d\n",sum);
	}
	return 0;
}


