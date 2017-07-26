#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int quick_mod(int a,int b,int m){
    int ans=1;
    while(b){
        if(b&1)ans=(LL)ans*a%m;
        a=(LL)a*a%m;
        b>>=1;
    }
    return ans;
}

//判断n的原根是否存在
//存在返回n包含的素因子，否则返回0
int ok(int n){
    if(n==2||n==4) return n;
    if(n%2==0)n/=2;
    if(n%2==0)return 0;
    int m=(int)sqrt(n+0.5);
    for(int i=2;i<=m;i++){
        if(n%i==0){
            while(n%i==0)n/=i;
            if(n==1)return i;
            else return 0;
        }
    }// 跳出循环说明n本身是一个素数
    return n;
}

// 存在原根返回true和所有原根，不存在原根返回false
bool original_roots(int n,vector<int>&root){
    root.clear();
    int p=ok(n),phi;
    if(!p)return false;
    if(p==2||p==4){root.push_back(p-1);return true;};
    if(n%2==0)phi=n/2/p*(p-1); // 先除再乘
    else phi=n/p*(p-1);
    // 寻找phi素数因子
    vector<int>primes;
    int m=phi;
    for(int i=2;LL(i)*i<=m;i++){
        if(m%i==0){
            primes.push_back(i);
            while(m%i==0)m/=i;
        }
    }
    if(m>1)primes.push_back(m);

    // 枚举原根，逐一检查，先找到最小原根
    for(int x=2;x<n;x++){
        if(__gcd(x,n)==1){
            int i,len=primes.size();
            for(i=0;i<len;i++){
                if(quick_mod(x,phi/primes[i],n)==1)break; //不符合
            }
            if(i==len){root.push_back(x);break;};  // 找到最小的原根
        }
    }
    // 逐一枚举
    int g=root[0];
    for(int i=2;i<phi;i++){
        g=(LL)g*root[0]%n;
        if(__gcd(i,phi)==1)root.push_back(g);
    }
    return true;
}
int main(){
    int n;
    vector<int>root;
    while(~scanf("%d",&n)){
        if(!original_roots(n,root))printf("-1\n");
        else{
            sort(root.begin(),root.end());
            int len=root.size();
            for(int i=0;i<len;i++){
                if(i==0)printf("%d",root[i]);
                else printf(" %d",root[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
