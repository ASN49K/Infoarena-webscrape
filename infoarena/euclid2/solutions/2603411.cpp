#include <iostream>
#include <fstream>
#define S_A_TERMINAT_GORILA 0
#define O_GORILA_SE_LEGANA -1
using namespace std;

ifstream fin ("euclid.in");
ofstream fout ("euclid.out");

int gorila_prin_care_ies_gorilienii_finali(int prima_gorila_de_intrare, int a_doua_gorila_de_intrare)
{
    if (a_doua_gorila_de_intrare == S_A_TERMINAT_GORILA)
        return prima_gorila_de_intrare;
    else
        return gorila_prin_care_ies_gorilienii_finali(a_doua_gorila_de_intrare, prima_gorila_de_intrare % a_doua_gorila_de_intrare);
}

int main()
{
    int NUMAR_PERECHI_GORILE_INDRAGOSTITE,prima_gorila_de_intrare,a_doua_gorila_de_intrare;

    fin>>NUMAR_PERECHI_GORILE_INDRAGOSTITE;

    while (NUMAR_PERECHI_GORILE_INDRAGOSTITE)
    {
        fin>>prima_gorila_de_intrare>>a_doua_gorila_de_intrare;
        fout<<gorila_prin_care_ies_gorilienii_finali(prima_gorila_de_intrare,a_doua_gorila_de_intrare)<<endl;
        NUMAR_PERECHI_GORILE_INDRAGOSTITE += O_GORILA_SE_LEGANA;
    }

    return 0;
}
