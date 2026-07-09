#include <bits/stdc++.h>
using namespace std;

int Euclid ( int a, int b)
{
    int r;
    while (b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int a, i, b, n;
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin >> n;
    for (i=1; i<=n ; i++)
    {
        fin >> a >> b;
        fout << Euclid (a, b) << "\n";
    }
    fout.close();
    return 0;
}

