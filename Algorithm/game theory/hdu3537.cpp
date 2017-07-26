// hdu3537,可以取1个2个或者3个，不要求连续但是保证最右边必须是正面朝上
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int SG(int x){
	int cnt=0;
	for(int i=1;i<=(int)1e8;i<<=1)if(x&i){
		cnt++;
	}
	if(cnt&1) return 2*x;
	else return 2*x+1;
}
int a[110];
int main(){
	int n;
	while(scanf("%d",&n)==1){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		n=unique(a,a+n)-a;
		int g=0;
		for(int i=0;i<n;i++){
			g^=SG(a[i]);
		}
		if(!g) puts("Yes");
		else puts("No");
	}
	return 0;
}

