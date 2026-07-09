#include <fstream>

#define NMAX 10002
using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int t, n, v[NMAX];

int main()
{
    int i, j, rez;
    fin>>t;
    for(i = 1; i <= t; i++)
    {
        fin>>n;
        if(n == 1) {fout<<"NU\n"; continue;}
        for(j = 1; j <= n; j++) fin>>v[j];
        rez = v[1] ^ v[2];
        for(j = 3; j <= n; j++)
            rez = rez ^ v[j];
        if(rez == 0)
           fout<<"NU\n";
           else
           fout<<"DA\n";
    }
    return 0;
}
