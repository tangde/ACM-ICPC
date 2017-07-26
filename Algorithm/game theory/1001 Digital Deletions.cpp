// 1001 Digital Deletions 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1771561;
int sg[maxn];

int Hash(char*p){
	int h=0;
	while(*p!=0){
		h=h*11+(*p++)-'0'+1;
	}
	return h;
}
int SG(char*s){
	int x=Hash(s);
	if(sg[x]>=0) return sg[x];
	int H[301]={0},n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]>'0')
			for(int j='1';j<=s[i];j++){
				s[i]-=(j-'0');
				H[SG(s)]=1;
				s[i]+=(j-'0');
			}
		else{
			s[i]=0;
			H[SG(s)]=1;
			s[i]='0';
		}
	}
	sg[x]=0;
	while(H[sg[x]]) sg[x]++;
	return sg[x];
}
int main(){

	char s[10];
	memset(sg,-1,sizeof(sg));
	while(~scanf("%s",s)){
		if(SG(s)) puts("Yes");
		else puts("No");
	}
	return 0;
}



