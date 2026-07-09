#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>

using namespace std;
typedef long long               LL;
typedef vector<int>             vi;
typedef vector<vi>              vii;
typedef pair<int,int>           pii;
typedef pair<int, pii>          piii;
typedef pair<LL, int>           pLLii;
typedef pair<int, LL>           piiLL;
typedef pair<LL,  LL>           pLLLL;
typedef pair<double, double>    pdd;

#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)
#define     rep(i,a)        for(int i=0; i<a; ++i)
#define     irep(i,a)       for(int i=a; i>=0; --i)
#define     fore(x,i)       for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define     rfore(x,i)      for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
#define     dforup(i,a,b)   for(i=a; i<b; ++i)
#define     dfordn(i,a,b)   for(i=a; i>b; --i)
#define     drep(i,a)       for(i=0; i<a; ++i)

#define     slenn(s,n)      for(n=0; s[n]!='\0'; ++n)

#define     MAX(a,b)        (((a) > (b)) ? (a) : (b))
#define     MIN(a,b)        (((a) < (b)) ? (a) : (b))
#define     last(a)         int(a.size() - 1)

#define     gl(x)           cin>>x
#define     gr(x)           fin>>x

#define     pls(x)          cout<<x<<" "
#define     plsr(x)         fout<<x<<" "
#define     pln(x)          cout<<x<<"\n"
#define     plnr(x)         fout<<x<<"\n"

#define     mem(a,b)        memset(a,b,sizeof(a))
#define     mp              make_pair
#define     fs              first
#define     sc              second
#define     clr(a)          a.clear()
#define     pob             pop_back
#define     pub             push_back
#define     eps             1E-7
#define     all(a)          a.begin(),a.end()
#define     allr(a)         a.rbegin(),a.rend()
#define     full(a,l)       a,a+l
#define     rin(a)          ifstream fin(a)
#define     rout(a)         ofstream fout(a);
#define     rclose()        fin.close(); fout.close();
#define     sz(a)           a.size()
#define     count_one       __builtin_popcount;
#define     count_onell     __builtin_popcountll;
#define     fastIO          ios_base::sync_with_stdio(false)
#define     PI              (acos(-1.0))
#define     linf            (1LL<<62)//>4e18
#define     inf             (0x7f7f7f7f)//>2e9

#ifdef DEBUG
#define D(x) x
#else
#define D(x)
#endif

rin("cmlsc.in");
rout("cmlsc.out");

int ni() { int a; gr(a); return a; }
double nf() { double a; gr(a); return a; }
long long nll() { long long a; gr(a); return a; }

const int NMAX = 1024;
int v1[NMAX], v2[NMAX], out[NMAX], din[NMAX][NMAX];
int best = 0;

int main()
{
    int a = ni(), b = ni(); D(pln("Reading a, b"););
    For(i, 1, a)
        v1[i] = ni();
    D(pln("Reading line1"););
    For(i, 1, b)
        v2[i] = ni();
    D(pln("Reading line2"););

    For(i, 1, a)
        For(j, 1, b)
            if(v1[i] == v2[j])
                din[i][j] = 1 + din[i-1][j-1];
            else
                din[i][j] = max(din[i-1][j],din[i][j-1]);
    D(pln("Doing dynamic programming"););
    for(int i = a, j = b; i;)
            if(v1[i] == v2[j])
                out[++best] = v1[i], i--, j--;
            else
                if(din[i][j-1] > din[i-1][j])
                    j--;
                else
                    i--;
    D(pln("Getting max length and a substring"););
    plnr(best);
    rFor(i, best, 1)
        plsr(out[i]);

    rclose();
    return 0;
}
