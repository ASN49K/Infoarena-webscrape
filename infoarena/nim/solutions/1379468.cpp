/*
    Those without power, seek us!
    Those with power, fear us!
    We are the Order of the Black Knights!
*/

#include<fstream>
#include<cstdio>
#include<map>
#include<set>
#define FIT(a,b) for(vector<int >::iterator a=b.begin();a!=b.end();a++)
#define FITP(a,b) for(vector<pair<int,int> >::iterator a=b.begin();a!=b.end();a++)
#define RIT(a,b) for(vector<int>::reverse_iterator a=b.end();a!=b.begin();++a)
#include<stack>
#define ROF(a,b,c) for(int a=b;a>=c;--a)
#include<vector>
#include<algorithm>
#define FOR(a,b,c) for(int a=b;a<=c;++a)
#define REP(a,b) for(register int a=0;a<b;++a)
#include<cstring>
#include<ctime>
#include<bitset>
#include<cmath>
#include<iomanip>
#include<set>
#define f cin
#define g cout
#include<queue>
#define debug cerr<<"OK";
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ull unsigned int
#define mod 1000000009LL
#define SQR 350
#define db double
#define inf 1<<30
#define div fdasfasd
#define hash dsafdsfds
#define od 100003
#define mod 666013
#define DIM 60010000
#define base 256
#define bas 255
#define mod 98999
#define N 1010
#define inf 0x3f3f3f3f
#define pdd pair<double,double>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
/*
    int dx[]={0,0,0,1,-1};
    int dy[]={0,1,-1,0,0};
*/
int n,T,sol,x;
int main ()
{
    f>>T;
    while(T--)
    {
    f>>n;
    sol=0;
    FOR(i,1,n)
    {
        f>>x;
        sol^=x;
    }
    if(!sol)
        g<<"NU\n";
    else
        g<<"DA\n";
    }
    return 0;
}
