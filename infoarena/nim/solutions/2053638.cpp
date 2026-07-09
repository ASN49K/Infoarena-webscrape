#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n, x, rez;

int main()
{
    fin>>t;
    while (t--)
    {
        fin>>n;
        rez=0;
        for (int i=1; i<=n; i++)
            fin>>x, rez^=x;
        if (rez)    fout<<"DA\n";
        else    fout<<"NU\n";
    }
    fin.close();
    fout.close();
    return 0;
}
