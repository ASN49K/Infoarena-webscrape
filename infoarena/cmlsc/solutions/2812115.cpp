#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int N, M;
int matrice[1025][1025];


void Citire()
{
    in >> N >> M;
    for(int i = 2 ; i <= N + 1; i++)
    {
        in >> matrice[0][i];
    }

    for (int i = 2; i <= M + 1; i++)
    {
        in >> matrice[i][0];
    }
    
}

int MaxCodition(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int LCS()
{
    for (int i = 2; i <= M + 1; i++)
    {
        for (int j = 2; j <= N + 1; j++)
        {
            if(matrice[i][0] == matrice[0][j])
            {
                matrice[i][j] = 1 + matrice[i-1][j-1];
            }
            else
            {
                matrice[i][j] = MaxCodition(matrice[i-1][j],matrice[i][j-1]);
            }
        }
    }

    return matrice[M+1][N+1];
    
}

void ShowElements()
{
    int valInitial = 1;
    
    for(int j = 2; j <= N + 1; j++)
    {
        if(matrice[M+1][j] == valInitial) {
            out << matrice[0][j] << ' ';
                ++valInitial;
        }
    }
}

int main()
{
    Citire();
    out << LCS();
    out << endl;
    ShowElements();
    return 0;
}