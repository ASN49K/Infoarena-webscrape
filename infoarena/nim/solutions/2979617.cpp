#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");ofstream fout("nim.out");

void Rezolvare()
{
    int n;
    fin >> n;
    int r=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        fin >> x;
        r= (r^x);
    }
    if( r!=0 )fout << "Da\n";
    else fout << "NU\n";
}

int main()
{
    int q;
    fin >> q;
    for(int i=1;i<=q;i++)Rezolvare();

    return 0;
}
