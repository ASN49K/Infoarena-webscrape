#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int primul_Numar, int aldoilea_Numar)
{
    if(primul_Numar == 0 || aldoilea_Numar == 0)
        return 0;
    else
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
    cin >> CateNumere;
    for (int i=0; i<CateNumere; i++)
    {
        cin >> valoarea_unu;
        cin >> valoarea_doi;
        cout << cmmdc(valoarea_doi,valoarea_unu) <<endl;
    }
    return 0;
}
