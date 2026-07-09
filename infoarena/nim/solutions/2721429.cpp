#include <bits/stdc++.h>
using namespace std;

const string FILENAME = "nim";

ifstream fin(FILENAME + ".in");
ofstream fout(FILENAME + ".out");

int n, m, x;
int main()
{
    int val = 0;
    fin >> m;
    while(m--)
    {
        fin >> n;
        val = 0;
        for(int i = 1; i <= n; i++){
            fin >> x;
            val ^= x;
        }
        fout << ((val) ? "DA\n" : "NU\n");
    }
    fin.close();
    fout.close();
    return 0;
}