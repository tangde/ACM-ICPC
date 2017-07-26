//hdu4666，曼哈顿距离
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;

int a[maxn][5]; // 存储dem维空间坐标
multiset<int>mst[1<<5];
int main(){
	int n,k,op,x;
	while(~scanf("%d %d",&n,&k)){
		for(int i=0;i<(1<<k);i++)mst[i].clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&op);
			if(op==0){
				for(int j=0;j<k;j++)scanf("%d",&a[i][j]);
				for(int t=0;t<(1<<k);t++){
					int s=0;
					for(int j=0;j<k;j++){
						if((1<<j)&t)s+=a[i][j];
						else s-=a[i][j];
					}
					mst[t].insert(s);
				}
			}
			else{
				scanf("%d",&x);
				for(int t=0;t<(1<<k);t++){
					int s=0;
					for(int j=0;j<k;j++){
						if((1<<j)&t)s+=a[x][j];
						else s-=a[x][j];
					}
					multiset<int>::iterator it = mst[t].find(s);
					mst[t].erase(it);
				}
			}
			int ans=0;
			for(int t=0;t<(1<<k);t++){
				multiset<int>::iterator it1=mst[t].begin();
				multiset<int>::iterator it2=mst[t].end();
				it2--;
				ans=max(ans,(*it2-*it1));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}








