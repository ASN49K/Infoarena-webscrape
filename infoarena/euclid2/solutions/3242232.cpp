#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b, n, sol;
int main()
{
    fin>>n;
    for (int i=1; i<=n; ++i)
    {
        fin>>a>>b;
        while (a!=0)
        {
            a%b;
            swap(a,b);
        }
        fout<<b;
    }

    return 0;
}
