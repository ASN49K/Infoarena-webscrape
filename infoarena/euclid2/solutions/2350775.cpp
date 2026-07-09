#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int Euclid(int a, int b)
{
    if(b==0) {return a;}
        else {return Euclid(b,a%b);}
}

int main()
{
    int CateNumere, valoarea_unu, valoarea_doi;
    in >> CateNumere;
    for (int i=0; i<CateNumere; i++)
    {
        in >> valoarea_unu>> valoarea_doi;
        out<<Euclid(valoarea_unu,valoarea_doi)<<'\n';
    }
    return 0;
}
