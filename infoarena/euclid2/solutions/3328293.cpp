#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a, b, n;

int main()
{
    fin >> n;
    while(n--)
    {
        int r;
        fin >> a >> b;
        if(a < b) swap(a, b);
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
