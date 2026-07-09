#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
long euclid (long a,long b)
{
    if (!b)
    return a;
    return euclid(b, a % b);
}
int i,n;
long a,b;
int main()
{
    fin>>n;
    for (i=1; i<=n; i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<endl;
    }

    return 0;
}
