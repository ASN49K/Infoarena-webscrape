#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    int r = a%b;
    while(r!=0)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

int main()
{
    int T, a, b;
    fin >> T;
    for(int i=1 ;i<=T;i++)
    {
        fin >> a >> b;
        fout<< cmmdc(a,b) <<'\n';
    }
    return 0;
}
