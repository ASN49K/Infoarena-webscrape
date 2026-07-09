#include <fstream>
using namespace std;
ifstream in ("nim.in");
ofstream out ("nim.out");
int n,m,k,p;
void Solve()
{
    in>>m;
    while(m--)
    {
        in>>k;
        p=p^k;
    }
    if (!p)
    {
        out<<"DA"<<'\n';
        return;
    }
    out<<"NU"<<'\n';
}
void Read()
{
    in>>n;
    while(n--)
    {
        Solve();
    }
}
int main()
{
    Read();
    return 0;
}
