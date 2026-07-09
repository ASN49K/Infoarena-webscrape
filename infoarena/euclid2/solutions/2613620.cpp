#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

#define pb push_back
#define x first
#define y second
#define Nmax 100005

int euclid(int a, int b)
{
    if (a < b)
        swap(a, b);

    if (b == 0)
        return a;

    return euclid(b, a % b);
}

int n;
int main()
{
    fin >> n;

    for (int i = 1, nr1, nr2; i <= n; ++i)
    {
        fin >> nr1 >> nr2;
        fout << euclid(nr1, nr2) << '\n';
    }

    return 0;
}