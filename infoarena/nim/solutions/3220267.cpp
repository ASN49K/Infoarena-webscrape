#include <fstream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
ifstream fin ("nim.in");
ofstream fout("nim.out");
int t,S,n,i,x;
void solve()
{
    fin>>n;
    S=0;
    for(i=1;i<=n;i++)
    {
        fin>>x;
        S^=x;
    }
    if(S)
        fout<<"DA\n";
    else
        fout<<"NU\n";
}
int main()
{
    fin>>t;
    while(t--)
        solve();
    return 0;
}
