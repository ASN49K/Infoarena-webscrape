#include <bits/stdc++.h>
using namespace std;

const string FILENAME = "euclid2";

ifstream fin(FILENAME + ".in");
ofstream fout(FILENAME + ".out");

int t;
int a, b;

int gcd(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    fin >> t;
    while(t--)
    {
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
