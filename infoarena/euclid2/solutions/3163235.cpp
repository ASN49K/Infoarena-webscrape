#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,n,i,r;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }
    return 0;
}
