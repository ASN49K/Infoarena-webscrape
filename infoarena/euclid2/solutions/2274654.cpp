#include <iostream>
#include <fstream>

using namespace std;

long long euclidean(long long a, long long b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (((a & 1) == 0) && ((b & 1) == 0))
        return 2 * euclidean(a >> 1, b >> 1);
    if ((a & 1) == 0)
        return euclidean(a >> 1, b);
    if ((b & 1) == 0)
        return euclidean(a, b >> 1);
    if (a > b)
        return euclidean(a - b, b);
    return euclidean(b - a, a);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t, a, b;
    fin >> t;
    for (int i=0; i<t; i++)
    {
        fin >> a >> b;
        fout << euclidean(a, b) << "\n";
    }
    return 0;
}
