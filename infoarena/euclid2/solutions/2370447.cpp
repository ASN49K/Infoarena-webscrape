#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a, b, t;

//recursiv
int gcd1(int x, int y)
{
    if(y==0)
        return x;
    return gcd1(y, x%y);
}

//impartiri
int gcd2(int x, int y)
{
    while(y>0)
    {
        int r=x%y;
        x=y;
        y=r;
    }
    return x;
}

//scaderi
int gcd3(int x, int y)
{
    while(x!=y)
    {
        if(x>y)
            x-=y;
        else
            y-=x;
    }
    return x;
}

int main()
{
    fin >> t;
    while(t--)
    {
        fin >> a >> b;
        fout << gcd1(a, b) << "\n";
    }
    return 0;
}
