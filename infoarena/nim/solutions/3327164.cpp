#include <fstream>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int t, n, v;

int main()
{
    int i, j, rez;
    fin>>t;
    for(i = 1; i <= t; i++)
    {
        fin>>n;
        rez = 0;
        for(j = 1; j <= n; j++)
        {
            fin>>v;
            rez = rez ^ v;
        }

        if(rez == 0)
           fout<<"NU\n";
           else
           fout<<"DA\n";
    }
    return 0;
}
