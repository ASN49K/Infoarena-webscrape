//Problema cel mai lung subsir comun (care este de fapt subsecventa)
//este o aplicatie directa a problemei introductive e programare dinamica.
//CMLSC- infoarena si varena
#include<iostream>
#include<fstream>
using namespace std;
#define LMAX 1024
#define ORIZ 1
#define DIAG 2
#define VERT 3

int a[LMAX+1], b[LMAX+1], c[LMAX+1]; // vectorii input si solutia
int Max[LMAX+1][LMAX+1];   // max[i][j] = subsir maxim intre a[1..i], b[1..j]
char drum[LMAX+1][LMAX+1]; // de unde provine max[i][j]

int main() {
  int m, n, i, j, mmax;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m>>n;
    for ( i=1; i<=m; i++ )
        f>>a[i];
    for ( j=1; j<=n; j++ )
        f>>b[j];
    f.close();

  for ( i = 1; i <=m; i++ )
    for ( j = 1; j <= n; j++ )
      if ( a[i] == b[j] ) { // avem egalitate la pozitiile i, j?
        Max[i][j] = Max[i-1][j-1] + 1; // adaugam un caracter la subsirul comun
        drum[i][j] = DIAG;             // tinem minte de unde am venit
      } else if ( Max[i-1][j] >Max[i][j-1] ) { // subsirul maximal existent
        Max[i][j] = Max[i-1][j]; // vom alege intre max[i-1][j] si max[i][j-1]
        drum[i][j] = VERT;       // tinind minte care din ele prin directie
      } else {
        Max[i][j] = Max[i][j-1];
        drum[i][j] = ORIZ;
      }

  // colectam drumul, caracterele vor fi in ordine inversa
  // am putea evita aceasta daca am calcula matricele de la coada la cap
  i = m;
  j = n;
  mmax = 0;
  while ( drum[i][j] ) {
    switch ( drum[i][j] ) {
    case DIAG:
      c[mmax++] = a[i];
      i--;
      j--;
      break;
    case ORIZ:
      j--;
      break;
    case VERT:
      i--;
    }
  }

  g<<mmax<<'\n';
  for ( i = mmax-1; i >= 0; i-- )
    g<<c[i]<<' ';
  g<<'\n';
  g.close();

  return 0;
}
