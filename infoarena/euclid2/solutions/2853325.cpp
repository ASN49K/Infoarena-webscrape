#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        unsigned int x, y;
        fin >> x >> y;
        int t = 0;
        while (y != 0)
        {
            t = y;
            y = x % y;
            x = t;
        }
        fout << x << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}