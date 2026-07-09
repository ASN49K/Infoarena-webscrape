#include <fstream>
using namespace std;
#define tip long long
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
tip cmmdc(tip x,tip y)
{
    tip c;
    while (y)
    {
        c=x%y;
        x=y;
        y=c;
    }
    return x;
}
tip n,i,a,b;
void solve()
{
    fin>>n;
    for (i=1 ; i<=n ; ++i) {
        fin >> a >> b;
        fout << cmmdc(a,b) << "\n";
    }
}
int main() {
    solve();
    return 0;
}

