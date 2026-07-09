#include <bits/stdc++.h>
#define in "euclid2.in"
#define out "euclid2.out"
using namespace std;
ifstream fin(in);
ofstream fout(out);

int n;

int CMMDC(int a, int b)
{
    int r;

    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int i,x,y;

    fin >> n;
    for (i = 1; i <= n; i++)
    {
        fin >> x >> y;
        fout << CMMDC(x,y) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
