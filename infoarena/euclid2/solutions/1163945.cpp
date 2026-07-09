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
#define inu "euclid2.in"
#define outu "euclid2.out"
using namespace std;
ifstream f(inu);
ofstream g(outu);
//int dx[]={0,0,0,1,-1};
//int dy[]={0,1,-1,0,0};
int n,i,x,y;
int gcd(int a,int b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
int main ()
{
	f>>n;
	FOR(i,1,n)
	{
		f>>x>>y;
		g<<gcd(x,y)<<"\n";
	}
	return 0;
}