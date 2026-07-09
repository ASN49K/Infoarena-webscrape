#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int CateNumere, valoarea_unu, valoarea_doi;
    cin >> CateNumere;
    for (int i=0; i<CateNumere; i++)
    {
        cin >> valoarea_unu;
        cin >> valoarea_doi;

        if(valoarea_unu == 0 || valoarea_doi == 0)
        cout << 0;
    else
        {
        while(valoarea_unu != valoarea_doi)
            {
                if (valoarea_unu > valoarea_doi)
                {
                    valoarea_unu = valoarea_unu - valoarea_doi;
                }
                else
                    valoarea_doi = valoarea_doi - valoarea_unu;
            }cout << valoarea_unu;

        }
    }
    return 0;
}
