#include<fstream>
#include<cstdio>
#include<set>
#include<stack>
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
#define ll long long
#define inf (1<<30)
#define base 256
#define ba 255
#define N 5
#define EPS 1e-12
#define mod  666013
#define inu "nim.in"
#define outu "nim.out"
using namespace std;
ifstream f(inu);
ofstream g(outu);
//int dx[]={0,0,0,1,-1};
//int dy[]={0,1,-1,0,0};
int x,n,sol,T;
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
        if(sol)
        g<<"DA\n";
        else
        g<<"NU\n";
    }
    return 0;
}
