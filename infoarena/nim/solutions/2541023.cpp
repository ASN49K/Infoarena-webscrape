#include <bits/stdc++.h>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n;

int main()
{
    int j, i, sum, x;
    fin >> t;
    for(i = 0; i < t; i++)
    {
        fin >> n;
        sum = 0;
        for(j = 0; j < n; j++)
        {
            fin >> x;
            sum = sum ^ x;
        }
        if(sum == 0)
            fout << "NU" << '\n';
        else
            fout << "DA" << '\n';
    }
    return 0;
}
