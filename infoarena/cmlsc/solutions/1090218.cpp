#include <fstream>
#define DMAX 1100
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

void citire();
void pd();
void afisare();

int n, m;
int a[DMAX], b[DMAX];
int LCS[DMAX][DMAX];

int main()
{
    citire();
    pd();
    afisare();

    fin.close();
    fout.close();
    return 0;
}

void citire()
{
    int i;
    fin>> n>> m;
    for (i=1; i<=n; i++) fin>> a[i];
    for (i=1; i<=m; i++) fin>> b[i];
}

void pd()
{
    int i, j;
    for (i=n; i>0; i--)
         for (j=m; j>0; j--)
              if (a[i]==b[j])
                  LCS[i][j]=1+LCS[i+1][j+1];
                  else
                  if (LCS[i][j+1]>LCS[i+1][j])
                      LCS[i][j]=LCS[i][j+1];
                      else
                      LCS[i][j]=LCS[i+1][j];
}
void afisare()
{
    int i, j;

    fout<< LCS[1][1]<< "\n";

    i=j=1;

    while (i<=n && j<=m)
        if (a[i]==b[j]) {fout<< a[i]<< ' '; i++, j++;}
            else
            if (LCS[i][j]==LCS[i+1][j]) i++;
                else j++;

    fout<< "\n";
}

/*
LCS

longest common subsequence

subsir comun maximal

an: 3 4 0 3 10 20 1
    1 2 3 4 5  6  7

bn: 10 4 5 0 7 3 1 20 30
    1  2 3 4 5 6 7 8  9

    1. subproblemele
    sa se determine LCS de i si j
    LCS = lungimea celui mai lung subsir comun PENTRU
                                               sufixul lui A face incepe la i
                                               sufixul lui B care uncepe la j

    2. recurenta

    LCS(i, j) = a. 1 + LCS(i+1, j+1),  A[i]=B[j];
                b. max {LCS(i, j+1), LCS(j, i+1)}, A[i]!=B[j];

    3. rezolvam subproblemele in mod buttom-up.
     (i de la n catre 1)
     (j de la m catre 1)

*/
