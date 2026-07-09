#include <fstream>
using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int cmmdc (int numar_1 , int numar_2)
{
    if (!numar_2)
        return numar_1;
    else
        return cmmdc (numar_2 , numar_1 % numar_2);
}

int main ()
{
    int teste;
    cin >> teste;

    int numar_1 , numar_2;
    for (int indice = 1 ; indice <= teste ; indice++)
    {
        cin >> numar_1 >> numar_2;
        cout << cmmdc (numar_1 , numar_2) << '\n';
    }

    cout.close() , cin.close();
    return 0;
}