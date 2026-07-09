#include <iostream>
#include <fstream>


using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

char a[1030],b[1030],rez[1030];
int r[1030][1030],k;
int n,m;




int main()
{
    int i,j,maxim;
    f>>n>>m;
    for (i=1; i<=n; i++)
        f>>a[i];
    for (j=1; j<=m; j++)
        f>>b[j];

    for (i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i]==b[j])

                r[i][j]=1+r[i-1][j-1];

            else r[i][j]=max(r[i-1][j],r[i][j-1]);




    g<<r[n][m]<<'\n';

     i=n;
     j=m;

     while (i && j)
     {
         if (a[i]==b[j])
         {
             rez[++k]=a[i];
             i--;j--;
         }

         else if (r[i-1][j]<r[i][j-1])
            j--;
         else i--;
    }

    for (i=k;i>=1;i--)
        g<<rez[i]<<" ";
}


