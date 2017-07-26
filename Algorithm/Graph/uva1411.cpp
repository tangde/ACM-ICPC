//uva1411 二分图建模，KM算法,(求最小时，将权值加负号其他不变)
#include<cstdio>
#include<set>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 110;
const double eps=1e-6;
const double INF =1e+20;

double w[maxn][maxn];
double Lx[maxn],Ly[maxn];
double slack[maxn];
bool S[maxn],T[maxn];
int link[maxn];
int n;

bool match(int i){
	S[i]=true;
	for(int j=1;j<=n;j++)if(!T[j]){
		if(abs(Lx[i]+Ly[j]-w[i][j])<eps){
			T[j]=true;
			if(!link[j]||match(link[j])){
				link[j]=i;
				return true;
			}
		}
		else slack[j]=min(slack[j],Lx[i]+Ly[j]-w[i][j]);
	}
	return false;
}

void update(){
	double a=INF;
	for(int i=1;i<=n;i++)if(!T[i]){
		a=min(a,slack[i]);
	}
	for(int i=1;i<=n;i++){
		if(S[i])Lx[i]-=a;
		if(T[i])Ly[i]+=a;
		else slack[i]-=a;
	}
}
void KM(){
	memset(Lx,0x80,sizeof(Lx));
	memset(link,0,sizeof(link));
	memset(Ly,0,sizeof(Ly));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			Lx[i]=max(Lx[i],w[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		memset(slack,0x7f,sizeof(slack));
		for(;;){
			memset(T,0,sizeof(T));
			memset(S,0,sizeof(S));
			if(match(i))break;
			else update();
		}
	}
}

int x[maxn],y[maxn];

int main(){
	int kase=0;
	int p,q;
	while(scanf("%d",&n)!=EOF){
		if(kase++)printf("\n");
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d",&p,&q);
			for(int j=1;j<=n;j++){
				w[i][j]=-sqrt((double)(p-x[j])*(p-x[j])+(double)(q-y[j])*(q-y[j]));
			}
		}
		KM();
		for(int i=1;i<=n;i++)
			printf("%d\n",link[i]);
	}
	return 0;
}






