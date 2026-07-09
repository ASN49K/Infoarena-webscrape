#include <fstream>
using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int lungime_subsir[1025][1025] , sir[2][1025] , subsir[1025];

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
                if ((lungime_subsir[indice_1][indice_2] = lungime_subsir[indice_1 - 1][indice_2 - 1] + 1) > subsir[0]) 
                    subsir[++subsir[0]] = sir[0][indice_1];
        }

    cout << subsir[0] << '\n';
    for (int indice = 1 ; indice <= subsir[0] ; indice++)
        cout << subsir[indice] << ' ';

    cout.close(); cin.close();
    return 0;
}