#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int tst,a,b;
int main()
{
    cin>>tst;
    while(tst--)
        cin>>a>>b,
        cout<<__gcd(a,b)<<'\n';
    return 0;
}
