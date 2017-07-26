// hdu4609
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#include<complex>
typedef complex<double>Complex;
const double PI=acos(-1.0);
const int maxn=1<<18;
// n必须是2^k次方的形式
// oper=1,做DFT变换，oper=-1,做DFT逆变换
void FFT(Complex *P,int n,int oper){
	for(int i=1,j=0;i<n-1;i++){
		for(int s=n;j^=s>>=1,~j&s;);
		if(i<j)swap(P[i],P[j]);
	}
	for(int d=0;(1<<d)<n;d++){
		int m=1<<d,m2=m*2;
		double p0=PI/m*oper;
		Complex unit_p0(cos(p0),sin(p0));
		for(int i=0;i<n;i+=m2){
			Complex unit=1;
			for(int j=0;j<m;j++){
				Complex &P1=P[i+j+m],&P2=P[i+j];
				Complex t=unit*P1;
				P1=P2-t;
				P2=P2+t;
				unit=unit*unit_p0;
			}
		}
	}
	if(oper==-1){
		for(int i=0;i<n;i++){
			LL w=(LL)(P[i].real()/n+0.5);
			P[i].real(w);
		}
	}
}
// 计算两向量u,v的卷积
// 多项式的乘法相当于直接计算系数卷积
Complex A[maxn],B[maxn];
vector<LL> conv(const vector<LL>&u,const vector<LL>&v){
	int n=1,p=u.size(),q=v.size();
	while(n<p+q-1)n<<=1;  // 将n变为2^k的形式
	for(int i=0;i<n;i++){  // 扩重为n位向量
		A[i]=i<p?u[i]:0;
		B[i]=i<q?v[i]:0;
	}
	// 系数表达达转化为点值表达
	FFT(A,n,1);
	FFT(B,n,1);
	for(int i=0;i<n;i++)A[i]*=B[i];
	// 逆变换将点值表达转换为系数表达
	FFT(A,n,-1);
	vector<LL>w(p+q-1);
	for(int i=0;i<p+q-1;i++){
		w[i]=A[i].real();
	}
	return w;
}

int a[maxn];
LL sumA[maxn],num[maxn];
int main(){
	int T,max_num,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(num,0,sizeof(num));
		max_num=-1;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			num[a[i]]++;
			max_num=max(max_num,a[i]);
		}
		vector<LL>A(max_num+1);
		A[0]=0;
		for(int i=1;i<=max_num;i++)A[i]=num[i];
		A=conv(A,A);

		max_num=A.size()-1;   // 最大和
		for(int i=0;i<=max_num;i+=2)
			A[i]-=num[i>>1];         // 减去自己和自己组合的
		for(int i=0;i<=max_num;i++)
			A[i]>>=1;               // 去掉有顺序限制
		// 上面A[i]表示两根互不相同的棒长度和为i的组合数
		sumA[0]=0;
		for(int i=1;i<=max_num;i++)
			sumA[i]=sumA[i-1]+A[i];
		sort(a,a+n);
		LL res=0;
		// 枚举
		for(int i=0;i<n;i++){
			res+=sumA[max_num]-sumA[a[i]];  // 和比它大的
			res-=(LL)i*(n-1-i);         // 减去一条比它小，一条比它大
			res-=(LL)(n-i-1)*(n-i-2)/2;   // 减去两条都比它大
			res-=(n-1);                 // 包含自己
		}
		double ans=(double)res*6/n/(n-1)/(n-2);
		printf("%.7f\n",ans);
	}
    return 0;
}






