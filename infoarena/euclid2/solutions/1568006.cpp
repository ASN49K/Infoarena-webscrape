#include <fstream>

using namespace std;

ifstream fin  ("euclid2.in");
ofstream fout ("euclid2.out");

unsigned int T;
unsigned int a, b;

unsigned int i;

unsigned int GCD (unsigned int x, unsigned int y);

int main ()
{
    fin >> T;
    for (i=0; i<T; i++)
    {
        fin >> a >> b;
        fout << GCD (a, b) << "\n";
    }
    return 0;
}

unsigned int GCD (unsigned int x, unsigned int y)
{
    unsigned short int r;
    r = 0;
    while (y)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
