#include <bits/stdc++.h>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int n;

int euclid(int a, int b)
{
    int c;
    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    fin >> n;
    while(n--)
    {
        int a, b;
        fin >> a >> b;
        fout << euclid(a,b) << "\n";
    }
    return 0;
}
