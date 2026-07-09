#include <bits/stdc++.h>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int n, m;
int x, y;

int main()
{
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fout.tie(0);
    int i;
    fin >> n;
    while(n--)
    {
        fin >> m;
        fin >> x;
        m--;
        while(m--)
        {
            fin >> y;
            x = x ^ y;
        }
        if(x == 0) fout << "NU\n";
        else fout << "DA\n";
    }
    fin.close();
    fout.close();
    return 0;
}
