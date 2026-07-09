
#include <bits/stdc++.h>

using namespace std;

int cmmdc(int a, int b)
{
    int x;
    while(b)
    {
        x = a%b;
        a = b;
        b = x;
    }

    return a;
}

int main()
{
    int t, a, b;

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for(int i = 0; i < t; i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a, b)<<'\n';
    }

    return 0;
}
