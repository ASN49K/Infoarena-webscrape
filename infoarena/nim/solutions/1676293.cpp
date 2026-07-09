#include <fstream>
#include <string.h>
#include <vector>
#include <queue>
#include <limits.h>

#define nMax 100001
#define lgMax 19
#define pb push_back
#define INF INT_MAX
#define bit(i) i&(-i)
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int val, t, n;
void solve()
{
    int S=0;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>val;
        S=S^val;
    }

    fout<<(S==0 ? "NU" : "DA")<<'\n';
}
int main()
{
    fin>>t;
    while(t--)
        solve();
    return 0;
}
