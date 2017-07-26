//hdu1849
#include<bits/stdc++.h>
using namespace std;
int main(){
	int m;
	while(scanf("%d",&m)&&m){
		int a,res=0;
		while(m--) scanf("%d",&a),res^=a;
		if(res) puts("Rabbit Win!");
		else puts("Grass Win!");
	}
	return 0;
}

