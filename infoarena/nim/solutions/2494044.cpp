#include <bits/stdc++.h>
using namespace std;
ifstream fin ("nim.in");
ofstream fout ("nim.out");
int T, n, x, s;
int main()
{
    fin >> T;
    while(T--)
    {
        fin >> n;
        int s = 0;
        for(int i=1; i<=n; i++)
        {
            fin >> x;
            s^=x;
        }
        if(!s)
            fout << "NU\n";
        else fout << "DA\n";
    }
    return 0;
}
