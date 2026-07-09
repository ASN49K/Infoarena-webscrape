#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
   int t, x, y, l;
   fin >> t;
   for(l = 1; l <= t; l++)
   {
       fin >> x >> y;
       fout << cmmdc(x, y) << '\n';
   }
}
