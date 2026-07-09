#include <bits/stdc++.h>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int t[100001];

int main()
{
    long long a, b, n;
    fin >> n;
    for(int i = 1; i<= n;i++)
    {
        fin >> a >> b;
        while(b != 0)
        {
            long long r = a % b;
            a = b;
            b = r;
        }
        t[i] = a;
    }
    for(int i = 1; i<= n;i++)
        fout << t[i] << '\n';
    return 0;
}
