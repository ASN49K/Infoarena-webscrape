#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{

    int n, a, b;
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        fin >> a >> b;
        int r =1;
        while(b!=0)
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
