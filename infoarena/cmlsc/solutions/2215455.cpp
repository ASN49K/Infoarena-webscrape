#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[100],b[100],c[100],n,m,k,i,j,L[10][10];

void citire(int v[],int &dim)
{
    f>>dim;
    for(i=1; i<=dim; i++)
        f>>v[i];
}

void construire_L()
{
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                L[i][j]=1+L[i-1][j-1];
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
}

void tiparire()
{
    for(i=k; i>=1; i--)
        g<<c[i]<<" ";

}

void construire_solutie_recursiv(int i,int j)
{
    if(i && j)
    {
        if(a[i]==b[j])
        {
            k++;
            c[k]=a[i];
            construire_solutie_recursiv(i-1,j-1);
        }
        else
        if(L[i-1][j]>L[i][j-1])
        {
            construire_solutie_recursiv(i-1,j);
        }
        else
            construire_solutie_recursiv(i,j-1);

    }
}

int main()
{
    citire(a,n);
    citire(b,m);
    construire_L();
    construire_solutie_recursiv(n,m);
    tiparire();
    return 0;
}
