#include <bits/stdc++.h>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n;
int nr;
int main()
{
    fin>>n;
    int xorsum=0;
    for(int i=0;i<n;i++)
    {
        xorsum=0;
        fin>>nr;
        for(int j=0;j<nr;j++)
        {
            int x;
            fin>>x;
            xorsum^=x;
        }
        if(xorsum>0)
            fout<<"DA\n";
        else fout<<"NU\n";
    }
    return 0;
}
