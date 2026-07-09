#include <fstream>

using namespace std;

#pragma GCC optimize ("Ofast")

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int x, y, n;

int euclid(int a, int b)
{
    if(b == 0)
        return a;
    return euclid(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    fin >> n;
    while(n--)
    {
        int x, y;
        fin >> x >> y;
        if(x < y)
            swap(x, y);
       fout << euclid(x, y) << '\n';
    }
    return 0;
}
