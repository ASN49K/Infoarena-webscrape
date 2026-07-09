#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int N, M;
int matrice[1025][1025];
int direction[1025][1025];

// -1 - left element, 1 - up element, 0 - diagonal


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

bool BiggerElement(int a, int b)
{
    return a > b;
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
                direction[i][j] = 0; // diagonal;
            }
            else
            {
                matrice[i][j] = MaxCodition(matrice[i-1][j],matrice[i][j-1]);
                if(BiggerElement(matrice[i-1][j],matrice[i][j-1]))
                {
                    direction[i][j] = 1; // up
                }
                else 
                {
                    direction[i][j] = -1; // left
                }
            }
        }
    }

    return matrice[M+1][N+1];
    
}

void ShowElements(int i, int j)
{
    if(i > 1 && j > 1)
    {
       if(direction[i][j] == 0)
       {
           ShowElements(i-1,j-1);
           out << matrice[0][j] << ' ';
       }
       else if(direction[i][j] == -1)
       {
           ShowElements(i,j-1);
       }
       else
       {
           ShowElements(i-1,j);
       }
    }
}

int main()
{
    Citire();
    int maxValue = LCS();
    out << maxValue;
    out << endl;
    ShowElements(M+1,N+1);
    return 0;
}