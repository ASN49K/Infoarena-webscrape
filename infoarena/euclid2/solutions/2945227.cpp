#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int T;
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        int a,b;
        fin>>a>>b;
         while(b)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<'\n';
    }
    return 0;
}