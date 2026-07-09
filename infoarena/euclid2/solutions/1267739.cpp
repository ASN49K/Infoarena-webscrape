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
#define N 300100
using namespace std;
/*int dx[]={0,0,0,1,-1};
int dy[]={0,1,-1,0,0};*/
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,T,b;
int main ()
{
	f>>T;
	while(T--)
	{
		f>>a>>b;
		g<<__gcd(a,b)<<"\n";
	}
	return 0;
}
