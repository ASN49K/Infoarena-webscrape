/*
Cel mai lung subsir comun
Fie v un vector cu N elemente. Se numeste subsir de lungime K al vectorului v un nou vector v' = (vi1, vi2, ... viK), cu i1 < i2 < ... < iK. De exemplu, vectorul v = (5 7 8 9 1 6) contine ca subsir sirurile (5 8 6) sau (7 8 1), dar nu contine subsirul (1 5). Se dau doi vectori A si B cu elemente numere naturale nenule.

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
#include <bits/stdc++.h>
#define NMAX 1025
#define MMAX 1025

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

stack < int > r;
int dp[NMAX][MMAX];

int main()
{
    int n, m, i, j, nr, a[NMAX], b[MMAX];

    fin >> n >> m;
    for ( i = 1 ; i <= n ; i++ ) fin >> a[i];
    for ( i = 1 ; i <= m ; i++ ) fin >> b[i];

    for ( i = 1 ; i <= n ; i++ ) if ( a[i] == b[1] ) while ( i <= n ) dp[i][1] = 1, i++;
    for ( i = 1 ; i <= m ; i++ ) if ( a[1] == b[i] ) while ( i <= m ) dp[1][i] = 1, i++;

    for ( i = 2 ; i <= n ; i++ )
        for ( j = 2 ; j <= m ; j++ )
            if ( a[i] == b[j] ) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max ( dp[i-1][j], dp[i][j-1] );

    fout << dp[n][m] << '\n';
    nr = dp[n][m];
    for ( i = n; i >=1; i-- )
        for ( j = m; j >= 1; j-- )
            if ( a[i] == b[j] && dp[i][j] == nr ) r.push ( a[i] ), i--, nr--;

    while ( r.empty() == 0 ) fout << r.top() << ' ', r.pop();


    return 0;
}
/*
IN:
5 3
1 7 3 9 8
7 5 8

OUT:
2
7 8
*/
