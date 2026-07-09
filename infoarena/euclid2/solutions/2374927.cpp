#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int T, a, b, r;


int cmmdc(int a, int b)
{
    r = b;

    while(a % b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return r;
}

void read()
{
    fin >> T;

    while( fin >> a >> b )
    {
        fout << cmmdc(a, b) << endl;
    }
}

int main()
{
    read();
}
