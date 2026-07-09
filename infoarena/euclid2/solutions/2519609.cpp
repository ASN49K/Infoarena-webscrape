#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int nrnr, rest, nr1, nr2;

int func(int nr1, int nr2)
{
    while(nr2){
        rest = nr1 % nr2;
        nr1 = nr2;
        nr2 = rest;
    }
    return nr1;
}

int main()
{
    fin >> nrnr;
    for(int index = 0; index < nrnr; index++){
        fin >> nr1 >> nr2;
        fout << func(nr1, nr2) << endl;
    }
    return 0;
}
