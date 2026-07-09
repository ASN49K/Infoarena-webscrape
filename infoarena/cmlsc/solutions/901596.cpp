# include <iostream>
# include <fstream>
# define n_max 1024

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int X[n_max],Y[n_max];
int L[n_max][n_max];
int d[n_max];
int lx,ly;

int MAX (int a, int b) { return a>b?a:b;}
void Citire()
{
    f >> lx >> ly;
    int i;

    for(i=1; i<=lx; i++)
    {
        f >> X[i];
        L[i][0] = 0;
    }
    for(i=1; i<=ly; i++)
    {
        f >> Y[i];
        L[0][i] = 0;
    }
    f.close();
}

void Alg_Dinamic()
{
    int i,j;
    for (i=1; i<=lx; i++)
    for (j=1; j<=ly; j++)
    {
        if (X[i]==Y[j])
         L[i][j] = 1+ L[i-1][j-1];
         else
         L[i][j] = MAX(L[i-1][j],L[i][j-1]);

    }

}
void Afisare()
{

    int i=lx,j=ly,h=1;
    while(L[i][j])
    {
        if(X[i]==Y[j])
        {
            d[h++] = X[i];
            i--;
            j--;
        }
        else
        {
            if(L[i-1][j] >= L[i][j-1])
            i--;
            else
            j--;
        }

    }
    g << h-1 << "\n";
    for(i=h-1; i>=1; i--)
        g << d[i] << " ";
        g<< '\n';
        g.close();
}

int main ()
{

    Citire();
    Alg_Dinamic();
    Afisare();
}

