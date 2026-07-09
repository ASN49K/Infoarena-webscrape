#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n, x, y, r;
    fin >> n;
    while(n != 0)
    {
        fin >> x >> y;
        if (x == 0 || y == 0)
                fout << 1;
        else
        {
            r = x % y;
            while(r > 0 || r < 0)
            {
                x = y;
                y = r;
                r = x % y;
            }
            fout << y << endl;
        }

        n--;
    }
    return 0;
}
