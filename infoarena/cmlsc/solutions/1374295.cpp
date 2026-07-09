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
#define FITP(a,b) for(vector<pair<unsigned int,int> >::iterator a=b.begin();a!=b.end();a++)
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
#define inf 1<<30
#define div fdasfasd
#define hash dsafdsfds
#define od 100003
#define mod  4398042316799LL
#define DIM 60010000
#define base 256
#define bas 255
#define N 1050
using namespace std;
/*
    int dx[]={0,0,0,1,-1};
    int dy[]={0,1,-1,0,0};
*/
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[N],b[N],D[N][N],t,sol[N];

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
    int p=n;
    int q=m;
    while(p&&q)
    {
        if(a[p]==b[q])
        {
            sol[++t]=a[p];
            p--;
            q--;
        }
        else
        if(D[p][q]==D[p-1][q])
        p--;
        else
        q--;
    }
    g<<t<<"\n";
    ROF(i,t,1)
    g<<sol[i]<<" ";






    return 0;
}
