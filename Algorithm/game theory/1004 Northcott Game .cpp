// 1004 Northcott Game 
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,a,b;
	while(~scanf("%d %d",&n,&m)){
		int res=0;
		while(n--){
			scanf("%d %d",&a,&b);
			if(a>b)swap(a,b);
			res^=(b-a-1);
		}
		if(res) puts("I WIN!");
		else puts("BAD LUCK!");
	}
	return 0;
}

