#include <fstream>
#define InFile  "euclid2.in"
#define OutFile "euclid2.out"
#define MAX 100001

using namespace std;

ifstream fin  (InFile);
ofstream fout (OutFile);

unsigned int euclid (unsigned int x, unsigned int y);

unsigned int T;
unsigned int a, b;

unsigned int i;

int main ()
{
    fin >> T;
    for (i=0; i<T; i++)
    {
        fin >> a >> b;
        fout << euclid (a, b);
        fout << '\n';
    }
    return 0;
}

unsigned int euclid (unsigned int x, unsigned int y)
{
    unsigned int r;
    while (y)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
