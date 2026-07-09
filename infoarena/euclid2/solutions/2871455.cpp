#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
int euclid(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        fin >> x >> y;
        fout << euclid(x, y) << "\n";
    }

    return 0;
}
