#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int sht(int a, int b)
{
    while(b)
    {
        int r=a%b;
         a=b;
         b=r;
    }
    return a;
}

int a, b, N;

int main()
{
    f>>N;
    for(int i = 1; i<= N; i++)
    {
        f>>a>>b;
        g<<sht(a, b)<<endl;
    }
    f.close();g.close();return 0;
}
