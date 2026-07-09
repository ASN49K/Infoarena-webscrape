#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int CateNumere, valoarea_unu, valoarea_doi,div;
    in >> CateNumere;
    for (int i=0; i<CateNumere; i++)
    {
        in >> valoarea_unu;
        in >> valoarea_doi;
        if(valoarea_unu>valoarea_doi)
        {
            for(int k=1;k<=valoarea_unu;k++)
            {
                if(valoarea_doi%k==0 && valoarea_unu%k==0)
                {
                    div=k;
                }
            }
        }
        else
        {
            for(int k=1;k<=valoarea_doi;k++)
            {
                if(valoarea_doi%k==0 && valoarea_unu%k==0)
                {
                    div=k;
                }
            }
        }

        out<<div<<'\n';
    }
    return 0;
}
