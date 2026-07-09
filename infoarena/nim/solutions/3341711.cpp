#include <bits/stdc++.h>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

void solve_testcase()
{
    int n, XOR = 0;
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        int val;
        fin >> val;
        XOR ^= val;
    }
    fout << (XOR == 0 ? "NU" : "DA") << "\n";
}

int main()
{
    int t;
    fin >> t;
    while(t--)
        solve_testcase();

    fin.close();
    fout.close();
    return 0;
}
