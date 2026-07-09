#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define N 1025

short M[N][N], v1[N], v2[N], sir[N];
short n, m;

void Citire()
{
    fin >> n >> m;
    for(short i = 1; i <= n; i++)
        fin >> v1[i];
    for(short i = 1; i <= m; i++)
        fin >> v2[i];
}

void PD()
{
    ///Formam matricea de echivalenta
    ///Daca gasim v1[i] = v2[j] atunci vom creste elementul i si j
    ///Apoi vom creste in continuare si celelalte elemente ce nu au elemente comune, pentru a pastra legatura sirului
    for(short i = 1; i <= n; i++)
        for(short j = 1; j <= m; j++)
            if(v1[i] == v2[j])
                M[i][j] = M[i - 1][j - 1] + 1;
            else
                M[i][j] = max(M[i - 1][j], M[i][j - 1]);
    fout << M[n][m] << "\n"; ///<- Am scris cel mai lung drum comun
    ///Constituirea sirului comun
    ///Daca cele 2 elem sunt egale il punem in sir si mergem pe linia si coloana anterioara in matrice
    ///daca nu, vedem daca nu cumva avem un element comun pentru cele 2 siruri, valoarea coloanei anterioare este mai mare decat a liniei anterioare
    ///mergem acolo, daca nu, mergem pe cealalta linie
    for(short i = n, j = m; i;)
        if (v1[i] == v2[j])
            sir[++sir[0]] = v1[i], i--, j--;
        else if (M[i - 1][j] < M[i][j - 1]) j--;
        else i--;
    for(short i = sir[0]; i >= 1; i--)
        fout << sir[i] << " ";
    fout << "\n";
}

int main()
{
    Citire();
    PD();
    return 0;
}
