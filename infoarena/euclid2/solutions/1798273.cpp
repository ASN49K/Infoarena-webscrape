#include <bits/stdc++.h>
#define in "euclid2.in"
#define out "euclid2.out"

using namespace std;

ifstream fin(in);
ofstream fout(out);

int n;

int main()
{
    fin>>n;
    while(n--)
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
