#include <fstream>
#define Nmax 1025
using namespace std;
/*Matrice caracteristica pentru implementarea programarii dinamice*/
int DP[Nmax][Nmax];

void citire(int &n, int x[], int &m, int y[])
{ifstream in("cmlsc.in");
    in>>n>>m;
/*initializare de la 1*/
    for(int i=1; i<=n; i++)
        in>>x[i];

    for(int i=1; i<=m; i++)
        in>>y[i];

in.close();
}

int cmlsc(int n, int x[], int m, int y[], int &lS, int s[])
{/*Functia determina cel mai lung subsir comun dintre x si y*/

/*Construim matricea dinamica D[i][j], i<=n, j<=m retine cate elemente comune sunt pana la x[i], respectiv y[j]*/
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(x[i] == y[j])
                DP[i][j] = 1 + DP[i-1][j-1];
            else
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);

/*Construim subsirul comun*/
    lS=0;
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(x[i] == y[j])
        {/*am gasit un element comun, micsoram ambele siruri*/
            s[lS] = x[i];
            lS++;

            i--; j--;
        }
        else
        /*in functie de valorile din matrice, pastram elementul care are mai multe elemente comune in spate*/
            if(DP[i-1][j]<DP[i][j-1])
                j--;
            else
                i--;
    }

}

void afisare(int lS, int s[])
{ofstream out("cmlsc.out");
    out<<lS<<'\n';

    for(int i=lS-1; i>=0; i--)
        out<<s[i]<<" ";

out.close();
}

int main()
{
    int n, x[Nmax];/*primul sir*/
    int m, y[Nmax];/*al doilea sir*/
    citire(n,x,m,y);

    int lS=0, s[Nmax];/*subsirul comun maximal*/
    cmlsc(n,x,m,y,lS,s);

    afisare(lS,s);

    return 0;
}
