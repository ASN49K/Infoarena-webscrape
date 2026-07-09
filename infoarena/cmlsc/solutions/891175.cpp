#include <fstream>

using namespace std;

//Functia ce determina maximul dintre doua numere
int maxim(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

//v1,v2 - sirurile initiale de numere, matrice - matricea dinamica
int v1[1025],v2[1025],matrice[1025][1025];

int main()
{
    //Deschiderea fisierelor de intrare si iesire
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    //m,n - lungimile vectorilor v1 si v2, i,j - contoare
    int m,n,i,j;

    //Se citesc m si n
    fin>>m;
    fin>>n;

    //Se citeste v1
    for(i=1;i<=m;i++)
        fin>>v1[i];

    //Se citeste v2
    for(i=1;i<=n;i++)
        fin>>v2[i];

    //Se aplica binecunoscuta relatie de recurenta
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(v1[i]==v2[j])
                matrice[i][j]=matrice[i-1][j-1]+1;
            else
                matrice[i][j]=maxim(matrice[i-1][j],matrice[i][j-1]);

    //lung - lungimea subsirului comun maximal
    int lung=matrice[m][n];

    //sol - subsirul comun maximal
    int sol[1025];

    //Se afiseaza lungimea subsirului comun maximal
    fout<<lung<<'\n';

    //Aceasta variabila va scadea
    i=lung;

    //Se reconstruieste sbsirul comun maximal
    while(i>0)
        if(v1[m]==v2[n]) //Cand intalnim doua caractere identice, actualizam sol-ul
        {
            sol[i--]=v1[m];
            m--;
            n--;
        }
        else //In rest, facem ca si cand am rezolva problema recursiv, doar ca valorile functiei recursive deja sunt in matrice
        {
            if(maxim(matrice[m-1][n],matrice[m][n-1])==matrice[m-1][n])
            {
                m--;
            }
            else
            {
                n--;
            }
        }

    //Afisam vectorul sol, in care acum se afla solutia
    for(i=1;i<=lung;i++)
        fout<<sol[i]<<' ';

    //Inchiderea fisierelor de intrare si iesire
    fin.close();
    fout.close();
    return 0;
}
