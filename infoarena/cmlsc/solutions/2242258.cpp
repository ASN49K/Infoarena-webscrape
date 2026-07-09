#include <fstream>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int nr1, nr2, v[2004], t[2004], matrice[1050][1050];

void refa(int l, int c)
{
    if(l <= 0 || c <= 0)
    return;

    if(matrice[l][c] == matrice[l][c-1])
    refa(l,c-1);
    else
    if(matrice[l][c] == matrice[l-1][c])
    refa(l-1, c);
    else
    {
        refa(l-1, c-1);
        cout << v[l] << ' ';
    }
}

int main()
{
    cin >> nr1 >> nr2;
    for(int i=1; i <= nr1; i++)
    cin >> v[i];
    for(int i=1; i <= nr2; i++)
    cin >> t[i];

    for(int i=1; i <= nr1; i++)
    {
        for(int j=1; j <= nr2; j++)
        {
            if(v[i] == t[j])
            matrice[i][j] = matrice[i-1][j-1]+1;
            else
            matrice[i][j] = max(matrice[i-1][j], matrice[i][j-1]);
        }
    }

    cout << matrice[nr1][nr2] << '\n';
    refa(nr1, nr2);
}
