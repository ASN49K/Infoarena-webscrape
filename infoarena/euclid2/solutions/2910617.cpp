#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,a,b,r;

int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>a>>b;
        if(a<b)
        {
            int aux=a;
            a=b;
            b=aux;
        }
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<'\n';
    }
    return 0;
}
