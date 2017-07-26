//uva11381 二分图建模，KM算法
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
const int maxn = 510;

int w[maxn][maxn];
int Lx[maxn],Ly[maxn];
int slack[maxn];
bool S[maxn],T[maxn];
int link[maxn];
int n;

bool match(int i){
	S[i]=true;
	for(int j=0;j<n;j++)if(!T[j]){
		if(Lx[i]+Ly[j]==w[i][j]){
			T[j]=true;
			if(link[j]==-1||match(link[j])){
				link[j]=i;
				return true;
			}
		}
		else slack[j]=min(slack[j],Lx[i]+Ly[j]-w[i][j]);
	}
	return false;
}

void update(){
	int a=inf;
	for(int i=0;i<n;i++)if(!T[i]){
		a=min(a,slack[i]);
	}
	for(int i=0;i<n;i++){
		if(S[i])Lx[i]-=a;
		if(T[i])Ly[i]+=a;
		else slack[i]-=a;
	}
}

void KM(){
	memset(link,-1,sizeof(link));
	for(int i=0;i<n;i++){
		Lx[i]=Ly[i]=0;
		for(int j=0;j<n;j++){
			Lx[i]=max(Lx[i],w[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		memset(slack,0x3f,sizeof(slack));
		for(;;){
			memset(T,0,sizeof(T));
			memset(S,0,sizeof(S));
			if(match(i))break;
			else update();
		}
	}
}

int main(){

	while(~scanf("%d",&n)){

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				scanf("%d",&w[i][j]);
		}

		KM();
		int ans=Lx[0];
		printf("%d",Lx[0]);
		for(int i=1;i<n;i++){
			ans+=Lx[i];
			printf(" %d",Lx[i]);
		}
		ans+=Ly[0];
		printf("\n%d",Ly[0]);
	    for(int i=1;i<n;i++){
	    	ans+=Ly[i];
		    printf(" %d",Ly[i]);
	    }
	    printf("\n%d\n",ans);
	}
	return 0;
}







