// 高斯消元法
#include<bits/stdc++.h>
using namespace std;
const int maxn=2000;
const int P=1000000007;
typedef int Matrix[maxn][maxn];
// 求xor方程的秩
// m个方程，n个变量
int matrix_rank(Matrix A,int m,int n){
    int i=0,j=0,k,r,u;
    while(i<m&&j<n){
        r=i;        // 处理第i个方程第j列
        for(k=i;k<m;k++)if(A[k][j]){
            r=k;break;    // 找到一第u>=i行，第j列不为0的数A[r][j]
        }
        if(A[r][j]){   // 如果找到就消元，否则跳到下一列
            if(r!=i)for(k=0;k<=n;k++)swap(A[r][k],A[i][k]);
            for(u=i+1;u<m;u++)if(A[u][j]){ // 用第i行消元
                for(k=i;k<=n;k++)A[u][k]^=A[i][k];
            }
            i++;
        }
        j++;
    }
    return i;  // 返回矩阵的秩
}

int primes[maxn],prime_cnt;
bool cheek[maxn];
int gen_primes(int n){
    int cnt=0;
    memset(cheek,0,sizeof(cheek));
    for(int i=2;i<=n;i++)if(!cheek[i]){
        primes[cnt++]=i;
        for(int j=i*2;j<=n;j+=i){
            cheek[j]=true;
        }
    }
    return cnt;
}

// 2^b %P
int quick_mod(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=(long long)res*a%P;
        a=(long long)a*a%P;
        b>>=1;
    }
    return res;
}
Matrix A;
int main(){
    prime_cnt=gen_primes(maxn);
    int n,m,T;
    long long x;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++){
        m=0;
        memset(A,0,sizeof(A));
        scanf("%d",&n);
        // 数字顺序代表变量顺序，素数顺序代表方程顺序
        for(int i=0;i<n;i++){
            scanf("%lld",&x);
            for(int j=0;j<prime_cnt;j++){ // 第j+1个方程
                m=max(j+1,m);
                while(x%primes[j]==0){
                    x/=primes[j];
                    A[j][i]^=1;
                }
            }
        }
        int r=matrix_rank(A,m,n);
        // 自由变量个数等于n-r
        int res=((long long)quick_mod(2,n-r)-1+P)%P;
        printf("Case #%d:\n%d\n",kase,res);
    }
    return 0;
}


