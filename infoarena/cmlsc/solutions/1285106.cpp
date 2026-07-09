/*Fie v un vector cu N elemente. Se numeste subsir de lungime K al vectorului v un nou vector v' = (vi1, vi2, ... viK), cu i1 < i2 < ... < iK. De exemplu, vectorul v = (5 7 8 9 1 6) contine ca subsir sirurile (5 8 6) sau (7 8 1), dar nu contine subsirul (1 5). Se dau doi vectori A si B cu elemente numere naturale nenule.

Cerinta
Sa se determine subsirul de lungime maxima care apare atat in A cat si in B.

Date de intrare
Fisierul de intrare cmlsc.in contine pe prima linie M si N, numarul de elemente pentru vectorul A, respectiv pentru B. A doua linie contine M numere naturale, elementele vectorului A. A treia linie contine descrierea vectorului B sub acelasi format.

Date de iesire
Fisierul de iesire cmlsc.out va contine pe prima linie MAX, lungimea maxima a unui subsir comun. A doua linie va contine MAX numere ce reprezinta un subsir comun pentru A si B. Daca exista mai multe solutii se poate afisa oricare.

Restrictii
1 ≤ M, N ≤ 1024
Numerele din cei doi vectori nu depasesc 256
*/
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int LCS[1024][1024],sir[1024],A[1024],B[1024];
int N,M,k;

int main()
{
    in>>N>>M;
    for(int j=1;j<=N;j++)
        in >> B[j];
    for(int i=1;i<=M;i++)
        in >> A[i];

    int cont =0;
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
        {
            if(A[i] == B[j])
                 LCS[i][j] = 1+ LCS[i-1][j-1];
            else
                LCS[i][j] = max(LCS[i][j-1],LCS[i-1][j]);
        }
    for(int i=M,j=N;i;)
        if(A[i]==B[j])
        {
            sir[++k] =A[i];
            i--;
            j--;
        }
        else if(LCS[i-1][j]<LCS[i][j-1])
            --j;
        else
            --i;

    out<<k<<"\n";
    for(int i=k;i;--i)
        out << sir[i] <<" ";
    return 0;
}
