// 1003 GG and MM
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int sg[1010][1010],step[1010][1010];

int SG(int a,int b){
    if(a>b) swap(a,b);
    if(a==0) return step[a][b]=sg[a][b]=0;
    if(sg[a][b]!=-1) return sg[a][b];
    int Min=inf,Max=-inf;
    sg[a][b]=sg[b][a]=0;
    for(int i=a;i<=b;i+=a){
        if(!SG(a,b-i)){
            sg[a][b]=sg[b][a]=1;
            Max=max(Max,step[a][b-i]);
        }
        else Min=min(Min,step[a][b-i]);
    }
    if(sg[a][b]>0) step[b][a]=step[a][b]=Max+1;
    else step[a][b]=step[b][a]=Min+1;
    return sg[a][b];
}

int main(){
    int n,a,b;
    memset(sg,-1,sizeof(sg));
    while(~scanf("%d",&n)){
        int s=0;
        while(n--){
            scanf("%d %d",&a,&b);
            if(a>b) swap(a,b);
            SG(a,b);
            s=max(s,step[a][b]);
        }
        if(s&1) puts("MM");
        else puts("GG");
    }
    return 0;
}




