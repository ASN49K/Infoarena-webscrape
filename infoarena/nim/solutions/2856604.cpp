#include <bits/stdc++.h>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int t;
int main()
{
    int n, x, y;
    fin>>t;
    while(t--)
    {
        fin>>n;
        fin>>x;
        for(int i = 1; i < n; i++)
            {
                fin>>y;
                x^=y;
            }
        if(x)
            fout<<"DA \n";
        else
            fout<<"NU \n";
    }
    return 0;
}
