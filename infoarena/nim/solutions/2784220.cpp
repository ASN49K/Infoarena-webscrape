#include <bits/stdc++.h>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int t,n,x,y;
int main()
{
    fin>>t;
    while(t--)
    {
        fin>>n;
        y=0;
        while(n--)
        {
            fin>>x;
            y^=x;
        }
        fout<<(y?"DA\n":"NU\n");
    }
    return 0;
}
