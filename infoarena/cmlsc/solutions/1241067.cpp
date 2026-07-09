#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int na,nb,i,j,matrice[1030][1030],a[1030],b[1030],nc,ic,result[1030];

int maxim(int a,int b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    f>>na;
    f>>nb;
    for(i=1; i<=na; i++)
        f>>a[i];
    for(i=1; i<=nb; i++)
        f>>b[i];

    for(i=1; i<=na; i++)
        for(j=1; j<=nb; j++)
        {
            if(a[i]==b[j])
            {
                matrice[i][j]=matrice[i-1][j-1]+1;
            }
            else
            {
                matrice[i][j]=maxim(matrice[i-1][j],matrice[i][j-1]);
            }
        }

    nc=ic=matrice[na][nb];
    i=na;
    j=nb;
    do
    {
        if(a[i]==b[j])
        {
            result[ic]=a[i];
            i--;
            j--;
            ic--;
        }
        else if(matrice[i][j]==matrice[i-1][j])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    while(i*j!=0);

    g<<nc<<'\n';
    for(i=1; i<=nc; i++)
    {
        g<<result[i]<<" ";
    }

    return 0;
}
