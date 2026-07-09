#include <bits/stdc++.h>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int Q;
int euclid (int a, int b)
{
    if (b == 0)
        return a;
    return euclid (b, a % b);
}
int main()
{
    fin >> Q;
    while (Q--)
    {
        int first, second;
        fin >> first >> second;
        fout << euclid (first, second) << "\n";
    }
    return 0;
}
