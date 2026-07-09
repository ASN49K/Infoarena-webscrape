#include <iostream>
#include <fstream>

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
using namespace std;

int main()
{
    int marime_sir_unu, marime_sir_doi, cel_mai_lung_subsir_comun[100], plusez = 0;

        in >> marime_sir_unu;
        in >> marime_sir_doi;
        int sir_unu[marime_sir_unu];
        for (int i = 0; i < marime_sir_unu; i++)
        {
            in >> sir_unu[i];
        }
        int sir_doi[marime_sir_doi];
        for (int j = 0; j < marime_sir_doi; j++)
        {
            in >> sir_doi[j];
        }
        bool found = false;
        for (int i = 0; i < marime_sir_unu; i++)
        {
            for (int j = 0; j < marime_sir_doi; j++)
            {
                if (sir_unu[i] == sir_doi[j])
                {
                    cel_mai_lung_subsir_comun[plusez] = sir_unu[i];
                    plusez++;
                    found = true;
                }
            }
        }
        if (found)
        {
        for (int k = 0; k < plusez; k++)
            {
            out << cel_mai_lung_subsir_comun[k]<<endl;
            }
        }
        else
           out << "Inexistent";
}




