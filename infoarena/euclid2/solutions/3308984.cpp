#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

int cmmdc(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int n;
    fin >> n;
    while (n != 0)
    {
        int a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
        n--;
    }
}