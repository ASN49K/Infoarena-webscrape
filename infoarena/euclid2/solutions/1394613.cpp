#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int euclid (int a,int b)
{
    if (!b)
    return a;
    return euclid(b, a % b);
}
int i,n;
int a,b;
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
