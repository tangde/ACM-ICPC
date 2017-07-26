//hdu4631，最近点对,每次输入一个点都输出一次最近点对
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
#define inf 0x3f3f3f3f
multiset<PII>S;

int Next(int A,int B,int C,int x){
	return ((ll)A*x+B)%C;
}

int main(){
	int T,n,Ax,Bx,Cx,Ay,By,Cy;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d %d %d %d",&n,&Ax,&Bx,&Cx,&Ay,&By,&Cy);
		S.clear();
		int x=Bx%Cx,y=By%Cy;
		S.insert(PII(x,y));
		ll ans=0,d=(ll)inf*inf;
		for(int i=1;i<n;i++){
			x=Next(Ax,Bx,Cx,x);
			y=Next(Ay,By,Cy,y);
			int dx=(int)sqrt(d*1.0)+1;
			multiset<PII>::iterator it=S.lower_bound(PII(x-dx,-inf));
			for(;it!=S.end();it++){
				ll X=(*it).first-x;
				ll Y=(*it).second-y;
				if(X>=0&&X*X>=d)break; // 剪枝，不要此处会tle
				d=min(d,X*X+Y*Y);
			}
			S.insert(PII(x,y));
			ans+=d;
		}
		printf("%lld\n",ans);
	}
	return 0;
}








