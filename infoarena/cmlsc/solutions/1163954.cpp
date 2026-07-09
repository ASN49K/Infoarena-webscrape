#include<fstream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#define FOR(a,b,c) for(int a=b;a<=c;++a)
#include<cstring>
#include<bitset>
#include<cmath>
#include<iomanip>
#include<queue>
#define f cin
#define g cout
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define ll unsigned long long
#define bit (1<<18)
#define M 1000100
#define N 1100
#define mod 1000000007
#define inu "cmlsc.in"
#define outu "cmlsc.out"
using namespace std;
ifstream f(inu);
ofstream g(outu);
//int dx[]={0,0,0,1,-1};
//int dy[]={0,1,-1,0,0};
int D[N][N],a[N],n,m,s[N],b[N],t;
int main ()
{
	f>>n>>m;
	FOR(i,1,n)
		f>>a[i];
	FOR(i,1,m)
		f>>b[i];
	FOR(i,1,n)
	FOR(j,1,m)
	{
		if(a[i]==b[j])
			D[i][j]=D[i-1][j-1]+1;
		else
			D[i][j]=max(D[i-1][j],D[i][j-1]);
	}
	while(D[n][m])
	{
		if(a[n]==b[m])
		{
			s[++t]=a[n];
			n--; m--;
		}
		else
		if(D[n-1][m]>D[n][m-1])
			n--;
		else
			m--;
	}
	for(int i=1;i<=t/2;++i)
		swap(s[i],s[t-i+1]);
	g<<t<<"\n";
	FOR(i,1,t)
	g<<s[i]<<" ";
	return 0;
}