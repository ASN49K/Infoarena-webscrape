#include <bits/stdc++.h>
#define inFile "euclid2.in"
#define outFile "euclid2.out"

using namespace std;

ofstream fout(outFile);

int n;

void Euclid2(int x, int y)
{
    int r;
    while(y > 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    fout << x << "\n";
}

void Read()
{
    int x, y, i;
    ifstream fin(inFile);
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> x >> y;
        Euclid2(x, y);
    }
    fin.close();
    fout.close();
}

int main()
{
    Read();
    return 0;
}
