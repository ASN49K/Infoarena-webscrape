#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T;
int a, b, tmp;

int main()
{
    fin >> T;

    while (T)
    {
        fin >> a >> b;
        while (b > 0)
        {
            tmp = b;
            b = a % b;
            a = tmp;
        }
        fout << a << "\n";
        T --;
    }
    return 0;
}
