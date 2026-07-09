#include <fstream>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int main()
{
    int t, n, i, j, x, s=0;
    fin>>t;
    for (i=1;i<=t;i++)
    {
        fin>>n;
        s=0;
        for (j=1;j<=n;j++)
        {
            fin>>x;
            s^=x;
        }
        if (s)
        {
            fout<<"DA"<<'\n';
        }
        else
            fout<<"NU"<<'\n';
    }
    return 0;
}
