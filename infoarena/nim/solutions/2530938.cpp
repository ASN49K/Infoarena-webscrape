#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t,n;

int main()
{

    fin >> t;

    for(;t;t--)
    {
        fin >> n;
        int r=0,x;
        for(;n;n--)
            fin >> x, r^=x;
        if(r)
            fout << "DA\n";
        else
            fout << "NU\n";
    }

    return 0;

}
