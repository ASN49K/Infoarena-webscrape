#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int sol,n,t,a;
void solve()
{
    sol=0;
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>a;
        sol^=a;
    }
    if(sol)g<<"DA\n";
    else g<<"nU\n";
}
int main()
{
    f>>t;
    for(int i=1; i<=t; i++)
    {
        solve();
    }
    return 0;
}
