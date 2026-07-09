#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n;

int main()
{
    fin >> n;
    for(int i = 1, a, b; i <= n; ++i)
    {
        fin >> a >> b;
        if(b > a)swap(a, b);

        while(b != 0)
        {
            int c = a % b;
            a = b;
            b = c;
        }

        fout << a << '\n';
    }
    return 0;
}
