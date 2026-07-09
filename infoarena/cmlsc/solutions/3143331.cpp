#include <fstream>
using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int lungime_subsir[1025][1025] , sir[2][1025];

void Afisare (int indice_1 , int indice_2)
{
    while (lungime_subsir[indice_1][indice_2] != lungime_subsir[indice_1 - 1][indice_2 - 1] + 1 || sir[0][indice_1] != sir[1][indice_2])
    {
        if (indice_1 > 1 && lungime_subsir[indice_1 - 1][indice_2] == lungime_subsir[indice_1][indice_2])
            indice_1--;
        else
            indice_2--;
    }

    if (lungime_subsir[indice_1][indice_2] > 1) 
        Afisare(indice_1 - 1 , indice_2 - 1);

    cout << sir[0][indice_1] << ' ';
}

int main ()
{
    int lungime[2];
    cin >> lungime[0] >> lungime[1];

    for (int indice_1 = 0 ; indice_1 <= 1 ; indice_1++)
        for (int indice_2 = 1 ; indice_2 <= lungime[indice_1] ; indice_2++)
            cin >> sir[indice_1][indice_2];

    for (int indice_1 = 1 ; indice_1 <= lungime[0] ; indice_1++)
        for (int indice_2 = 1 ; indice_2 <= lungime[1] ; indice_2++)
        {
            if (sir[0][indice_1] != sir[1][indice_2])
                lungime_subsir[indice_1][indice_2] = max(lungime_subsir[indice_1][indice_2 - 1] , lungime_subsir[indice_1 - 1][indice_2]);
            else
                lungime_subsir[indice_1][indice_2] = lungime_subsir[indice_1 - 1][indice_2 - 1] + 1;
        }

    cout << lungime_subsir[lungime[0]][lungime[1]] << '\n';
    Afisare(lungime[0] , lungime[1]);
    cout.close(); cin.close();
    return 0;
}