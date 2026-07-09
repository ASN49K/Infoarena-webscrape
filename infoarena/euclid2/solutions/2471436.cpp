#include <bits/stdc++.h>
#define ll long long
#define uns unsigned
#define newline '\n'
using namespace std;
///******************
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b;

int main()
{
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> a >> b;
        fout << __gcd(a, b) << newline;
    }

    return EXIT_SUCCESS;
}
