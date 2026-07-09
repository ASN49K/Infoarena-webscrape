#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int n, i, x, y, r;
    fin >> n;

    for(i=1; i<=n; i++)
    {
        fin >> x >> y;
        while(y != 0)
        {
            r = x  % y;
            x = y;
            y = r;
        }
        fout << x << "\n";
    }
    return 0;
}
