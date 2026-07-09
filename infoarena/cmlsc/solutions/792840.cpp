#include <cstdio>
#define max(a,b) ((a > b) ? a : b)

using namespace std;

int A[1025];
int B[1025];
int sol[1025][1025];
int lungimeA;
int lungimeB;

void citesteSir(int sir[], int lungime){
    for (int i = 1; i <= lungime; ++ i){
        scanf ("%d", &sir[i]);
    }
}

void citire(){
    scanf ("%d%d", &lungimeA, &lungimeB);
    citesteSir (A, lungimeA);
    citesteSir (B, lungimeB);
}

void dinamica(){
    /**
     * daca A[i] = B[j], inseamna ca mai am un element comun
     * si adaug 1 la sol de pe diagonala (daca adun la maximu de sus, stanga exista
     * riscul sa ia un element deja folosit)
     * daca nu, iau maxium din poz din stanga, si sus,
     * sol se afla pe ultima poz;
     **/
    for (int i = 1; i <= lungimeA; ++ i){
        for (int j = 1; j <= lungimeB; ++ j){
            if (A[i] == B[j]){
                sol[i][j] = 1 + sol[i - 1][j - 1];
                continue;
            }
            sol[i][j] = max (sol[i - 1][j], sol[i][j - 1]);
        }
    }
}

void afisare(int i, int j){
    /**
      * plec din coltul dreapta jos, refacand drumul
      * daca am un element comun, il afisez (dupa reapelarea pe diagonala)
      * daca nu am element comun, merg in maximul dintre pos de sus, si cea din stanga
      **/
    if (sol[i][j] == 0){
        return;
    }
    if (A[i] == B[j]){
        afisare (i - 1, j - 1);
        printf("%d ", A[i]);
        return;
    }
    if (sol[i - 1][j] > sol[i][j - 1]){
        afisare (i - 1, j);
        return;
    }
    afisare (i, j - 1);
}

int main()
{
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);

    citire();
    dinamica();
    printf ("%d\n", sol[lungimeA][lungimeB]);
    afisare(lungimeA, lungimeB);

    return 0;
}
