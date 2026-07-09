#include <bits/stdc++.h>

using namespace std;

int cmmdc(int a, int b)
{
    if(!b) return a;
    return cmmdc(b, a%b);
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
        fout<<cmmdc(a, b)<<endl;
    }

    return 0;
}
