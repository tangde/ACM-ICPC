// LightOj1366
#include <bits/stdc++.h>
using namespace std;
const int maxn=3000;
typedef long long ll;
typedef pair<int,int>PII;
vector<PII>vec;
ll count(int w,int h){
	ll res=0;
	for(int u=0;u<=w/2;u+=1){
		for(int v=0;v<=h/2;v+=1){
			if(u==v)continue;
			int q=(int)sqrt(u*u+v*v);
			if(q*q!=v*v+u*u)continue;
			for(int r=1;r<q;r++){ // 枚举半径
				ll temp=0;
				int y1=min(-r,v-(q-r)),y2=max(r,v+(q-r));
				int x1=min(-r,u-(q-r)),x2=max(r,u+(q-r));
				int x=x2-x1,y=y2-y1;
				if(x<=w&&y<=h)temp+=(w-x+1)*(h-y+1);
				if(u*v)temp<<=1; // 此时有两个方向
				res+=temp;
			}
		}
	}
	return res;
}
int main(){
	int w,h,T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		scanf("%d%d",&w,&h);
		ll ans=count(h,w);
		printf("Case %d: %lld\n",kase,ans);
	}
	return 0;
}




