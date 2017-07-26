// poj2348
// #include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;

bool slove(int a,int b){
	bool f=true;
	for(;;){
		if(a>b)swap(a,b);
		if(b%a==0)break; // b是a的倍数，必胜
		if(b-a>a)break;  // 第二中情况,必胜
		b-=a;
		f=!f;
	}
	return f;
}
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)&&(a||b)){
		if(slove(a,b))puts("Stan wins");
		else puts("Ollie wins");
	}
	return 0;
}





