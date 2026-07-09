#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int n, i, k, act, j, x;
char c;

int main()
{
    fin>>n;
    for (i=1; i<=n; i++)
    {
        fin>>k;
        fin>>act;
        for (j=2; j<=k; j++)
        {
            fin>>x;
            act=act xor x;
        }
        if (act!=0)
            fout<<"DA";
        else
            fout<<"NU";
        fout<<'\n';
    }
    return 0;
}
