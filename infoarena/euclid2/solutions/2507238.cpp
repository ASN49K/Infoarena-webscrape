#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int t,a,b;
int main()
{
    fin>>t;
    while(t)
    {
        t--;
        fin>>a>>b;
        fout<<__gcd(a,b)<<'\n';
    }
    return 0;
}
