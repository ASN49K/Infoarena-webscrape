#include <bits/stdc++.h>

using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

int main()
{
    int T,a,b;
    fin>>T;
    while(T>0)
    {
        fin>>a>>b;
        fout<<__gcd(a,b);
        T--;
    }
    return 0;
}
