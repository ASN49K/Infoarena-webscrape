#include <fstream>
#define InFile  "euclid2.in"
#define OutFile "euclid2.out"
#define MAX 100001

using namespace std;

void read ();
void solve ();
void print ();
unsigned int euclid (unsigned int x, unsigned int y);

unsigned int T;
unsigned int a[MAX], b[MAX];

unsigned short int gcd[MAX];
unsigned int i;

int main ()
{
    read ();
    solve ();
    print ();
    return 0;
}

void read ()
{
    ifstream fin (InFile);
    fin >> T;
    for (i=0; i<T; i++)
        fin >> a[i] >> b[i];
}

void solve ()
{
    for (i=0; i<T; i++)
        gcd[i] = euclid(a[i],b[i]);
}

void print ()
{
    ofstream fout (OutFile);
    for (i=0; i<T; i++)
        fout << gcd[i] << '\n';
}

unsigned int euclid (unsigned int x, unsigned int y)
{
    unsigned short int r;
    while (y)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
