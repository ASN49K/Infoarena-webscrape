#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int CateNumere, valoarea_unu, valoarea_doi;
    in >> CateNumere;
    for (int i=0; i<CateNumere; i++)
    {
        in >> valoarea_unu;
        in >> valoarea_doi;
        while(valoarea_unu != valoarea_doi)
        {
            if(valoarea_unu>valoarea_doi)
            {
                valoarea_unu-=valoarea_doi;
            }else  valoarea_doi-=valoarea_unu;
        }
        out<<valoarea_doi<<'\n';
    }
    return 0;
}
