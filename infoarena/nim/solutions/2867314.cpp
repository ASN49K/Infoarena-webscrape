#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n;

int main()
{
    int xor_sum, x;
    fin >> t;
    while(t--)
    {
        xor_sum = 0;
        fin >> n;
        for(int i = 1; i <= n; i++)
        {
            fin >> x;
            xor_sum ^= x;

        }
        if(xor_sum == 0)
            fout << "NU\n";
        else fout << "DA\n";
    }
    fout.close();
    return 0;
}
