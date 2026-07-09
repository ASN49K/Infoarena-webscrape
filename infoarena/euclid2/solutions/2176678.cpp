#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
    if (b == 0)
        return a;
    else
        return cmmdc(b, a % b);
}

int main()
{
    int T,a,b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> T;
    for ( ; T; T--)
    {
        fin >> a >> b;
        fout << cmmdc(a,b) << "\n";
    }
    return 0;
}
