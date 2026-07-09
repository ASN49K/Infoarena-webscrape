#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int x, int y)
{
    while(y != 0)
    {
        int r = x%y;
        x = y;
        y = r;
    }

    return x;
}

int main()
{
    int n;
    int x, y;
    fin >> n;
    for(int i = 0 ; i < n; i++)
    {
        fin >> x >> y;
        fout << cmmdc(x, y) << '\n';
    }
    return 0;
}
