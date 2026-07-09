/*Cerinta
Sa se determine subsirul de lungime maxima care apare atat in A cat si in B.

Date de intrare
Fisierul de intrare cmlsc.in contine pe prima linie M si N, numarul de elemente pentru vectorul A, respectiv pentru B. A doua linie contine M numere naturale, elementele vectorului A. A treia linie contine descrierea vectorului B sub acelasi format.

Date de iesire
Fisierul de iesire cmlsc.out va contine pe prima linie MAX, lungimea maxima a unui subsir comun. A doua linie va contine MAX numere ce reprezinta un subsir comun pentru A si B. Daca exista mai multe solutii se poate afisa oricare.
*/
#include <stdio.h>
#include <stdlib.h>
#define Nmax 1024
#define FOR(i,a,b) for(i=a;i<=b;++i)
#define max(a,b) ((a>b)?a:b)
int M,N,A[Nmax],B[Nmax],D[Nmax][Nmax],sir[Nmax];bst;
int main()
{
    int i,j;
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d,%d",&M,&N);
    FOR(i,1,M)
        scanf("%d",&A[i]);
    FOR(i,1,N)
        scanf("%d",&B[i]);
    FOR(i,1,M)
        FOR(i,1,N)
            if(A[i]==B[j]){
                D[i][j]=1+D[i-1][j-1];
            }else{
                D[i][j]=max(D[i-1][j],D[i][j-1]);
            }
    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
    printf("%d\n", bst);
    for (i = bst; i; --i)
        printf("%d ", sir[i]);
    return 0;
}
