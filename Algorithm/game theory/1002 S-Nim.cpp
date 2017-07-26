//1002 S-Nim
#include<bits/stdc++.h>
using namespace std;
/*
1.获得单个的SG值;
2.可选步数为一系列不连续的数,存放在a中，已排序
 */
int sg[10010],a[101],n;
int SG(int x){
    if(sg[x]>=0) return sg[x];
    if(x<a[0]) return sg[x]=0;
    int Hash[101]={0};
    for(int i=0;i<n&&a[i]<=x;i++){
        Hash[SG(x-a[i])]=1;
    }
    sg[x]=0;
    while(Hash[sg[x]]) sg[x]++;
    return sg[x];
}
int main(){
    int m,h,x;
    while(scanf("%d",&n)&&n){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        memset(sg,-1,sizeof(sg));
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",&h);
            int g=0;
            while(h--){
                scanf("%d",&x);
                g^=SG(x);
            }
            if(g) printf("W");
            else printf("L");
        }
        printf("\n");
    }
    return 0;
}




