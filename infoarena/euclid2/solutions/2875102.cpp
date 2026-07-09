#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int nrperechi, nr1, nr2, rest;

int main()
{
    fin >> nrperechi;
    while(nrperechi)
    {
        fin >> nr1 >> nr2;
        while(nr1%nr2 !=0)
        {
            rest = nr1%nr2;
            nr1 = nr2;
            nr2 = rest;
        }
        fout << nr2 <<'\n';
        nrperechi--;
    }
    return 0;
}
