#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int T, a, b;


int cmmdc(int a, int b)
{
    int r;

    if(a % b == 0) return b;

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
        fout << cmmdc(max(a, b), min(a, b)) << endl;
    }
}

int main()
{
    read();
}
