#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int primul_Numar, int aldoilea_Numar)
{
    while(primul_Numar != aldoilea_Numar)
        {
            if (primul_Numar > aldoilea_Numar)
            {
                primul_Numar = primul_Numar - aldoilea_Numar;
            }
            else
                aldoilea_Numar = aldoilea_Numar - primul_Numar;
        }
    return primul_Numar;
}

int main()
{
    int CateNumere, valoarea_unu, valoarea_doi;
    in >> CateNumere;
    for (int i=0; i<CateNumere; i++)
    {
        in >> valoarea_unu;
        in >> valoarea_doi;
        out << cmmdc(valoarea_doi,valoarea_unu) <<endl;
    }
    return 0;
}
