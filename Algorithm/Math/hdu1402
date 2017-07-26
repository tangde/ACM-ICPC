#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1<<18;
const int P = (479 << 21) + 1;
const int G = 3;

int quick_mod(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=(LL)ans*a%P;
        b>>=1;
        a=(LL)a*a%P;
    }
    return ans;

}
// n必须是2^k次方
// oper=1,做DFT变换，oper=-1,做DFT逆变换
void NTT(LL *A,int n,int oper){
    for(int i=1,j=0;i<n-1;i++){
        for(int s=n;j^=s>>=1,~j&s;);
        if(i<j)swap(A[i],A[j]);
    }
    for(int d=0;(1<<d)<n;d++){
        int m=1<<d,m2=m*2;
        int w=quick_mod(G,oper*(P-1)/m2+P-1);
        for(int i=0;i<n;i+=m2){
            int unit=1;
            for(int j=0;j<m;j++){
                LL u=A[i+j]%P;
                LL t=(LL)unit*A[i+j+m]%P;
                A[i+j+m]=(u-t+P)%P;
                A[i+j]=(u+t)%P;
                unit=(LL)unit*w%P;
            }
        }
    }
    if(oper==-1){
        int inv=quick_mod(n,P-2);
        for(int i=0;i<n;i++){
            A[i]=(LL)A[i]*inv%P;
        }
    }
}

LL A[maxn],B[maxn];
vector<int> conv(const vector<int>&u,const vector<int>&v){
    int n=1,p=u.size(),q=v.size();
    while(n<p+q-1)n<<=1;  // 将n变为2^k的形式
    for(int i=0;i<n;i++){  // 扩重为n位向量
        A[i]=i<p?u[i]:0;
        B[i]=i<q?v[i]:0;
    }
    // 系数表达达转化为点值表达
    NTT(A,n,1);
    NTT(B,n,1);
    for(int i=0;i<n;i++)A[i]*=B[i];
    // 逆变换将点值表达转换为系数表达
    NTT(A,n,-1);
    vector<int>w(p+q-1);
    for(int i=0;i<p+q-1;i++){
        w[i]=A[i];
    }
    return w;
}
// 返回大数a*b的结果，用字符数组存储
char a[maxn],b[maxn];
char *big_number_mult(char*a,char*b){
    int lena=strlen(a),lenb=strlen(b);
    vector<int>u(lena),v(lenb);
    // 采用低位到高位的顺序存储
    for(int i=0;i<lena;i++)u[i]=a[lena-1-i]-'0';
    for(int i=0;i<lenb;i++)v[i]=b[lenb-1-i]-'0';
    vector<int>x=conv(u,v);
    //for(int i=0;i<x.size();i++)cout<<x[i]<<endl;
    int c=0,len=x.size();
    for(int i=0;i<len;i++){
        x[i]+=c;c=x[i]/10;x[i]%=10;
    }
    while(c>0){x.push_back(c%10);c/=10;}
    int p=x.size()-1;
    while(p>=0&&x[p]==0)p--;
    // 将结果放在a数组中返回
    if(p<0){a[0]='0';a[1]=0;return a;}
    a[p+1]=0;
    for(int i=p;i>=0;i--)a[i]='0'+x[p-i];
    return a;
}
int main(){
    while(~scanf("%s%s",a,b)){
        char*p=big_number_mult(a,b);
        printf("%s\n",p);
    }
    return 0;
}


