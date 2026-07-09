#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    int a,b,n,i,r;

    ifstream fin("cmmdc.in");
    ofstream fout("cmmdc.out");
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;

    fout<<__gcd(a,b)<<endl;
    }
    return 0;
}
