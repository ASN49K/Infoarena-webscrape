#include <fstream>
#define InFile  "euclid2.in"
#define OutFile "euclid2.out"

using namespace std;

ifstream fin  (InFile);
ofstream fout (OutFile);

unsigned int euclid (unsigned int a, unsigned int b);

unsigned int T;
unsigned int a, b;

unsigned int i;

int main ()
{
    fin >> T;
    for (i=0; i<T; i++)
    {
        fin >> a >> b;
        fout << euclid(a,b);
        fout << '\n';
    }
    return 0;
}

unsigned int euclid (unsigned int a, unsigned int b)
{
    unsigned short int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
