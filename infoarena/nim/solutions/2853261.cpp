#include <bits/stdc++.h>

using namespace std;
ifstream fin ("nim.in");
ofstream fout ("nim.out");

int t, n;

int main()
{
    fin >> t;
    for(int i = 1 ; i <= t ; i++)
    {
        fin >> n;
        int s = 0;
        for(int j = 1 ; j <= n ; j++)
        {
            int x;
            fin >> x;
            s = s ^ x;
        }
        if(s > 0)
            fout << "DA";
        else
            fout << "NU";
        fout << '\n';
    }
    return 0;
}
