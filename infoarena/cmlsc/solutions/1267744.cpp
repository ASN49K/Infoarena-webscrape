/*
    Look at me!
    Look at me!
    The monster inside me has grown this big!
*/

#include<fstream>
#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#define FIT(a,b) for(vector<pair<int,int> >::iterator a=b.begin();a!=b.end();a++)
#define RIT(a,b) for(vector<int>::reverse_iterator a=b.end();a!=b.begin();++a)
#include<stack>
#define ROF(a,b,c) for(int a=b;a>=c;--a)
#include<vector>
#include<algorithm>
#define FOR(a,b,c) for(int a=b;a<=c;++a)
#define REP(a,b) for(register int a=0;a<b;++a)
#include<cstring>
#include<bitset>
#include<cmath>
#include<iomanip>
#include<queue>
#define debug cerr<<"OK";
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define eps 1.e-6
#define N 1050
using namespace std;
/*int dx[]={0,0,0,1,-1};
int dy[]={0,1,-1,0,0};*/
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int sol[N],D[N][N],a[N],b[N],n,m,t;
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
	int pa=n,pb=m;
	while(pa&&pb)
	{
		if(a[pa]==b[pb])
		{
			sol[++t]=a[pa];
			--pa;
			--pb;
		}
		else
		if(D[pa][pb]==D[pa-1][pb])
			--pa;
		else
			--pb;
	}
	g<<t<<"\n";
	ROF(i,t,1)
	g<<sol[i]<<" ";
	return 0;
}
