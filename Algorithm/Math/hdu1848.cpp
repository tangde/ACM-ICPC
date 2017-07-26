//hdu1848
#include<bits/stdc++.h>
using namespace std;
int sg[1010],fei[100];
void SG(){
	sg[0]=0;
	for(int j=1;j<=1000;j++){
		set<int>s;
		for(int i=0;fei[i]<=j;i++){
			s.insert(sg[j-fei[i]]);
		}
		sg[j]=0;
		while(s.count(sg[j]))sg[j]++;
	}
}
int main(){
	fei[0]=1;
	fei[1]=2;
	for(int i=2;i<20;i++)
		fei[i]=fei[i-1]+fei[i-2];
	SG();
	int n,m,p;
	while(scanf("%d %d %d",&n,&m,&p)&&n){
		int g=sg[n]^sg[m]^sg[p];
		if(g) puts("Fibo");
		else puts("Nacci");
	}
	return 0;
}

