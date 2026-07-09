//subsir comun maximal
//Fie  x prima  multime x1 x2 ...xn  si y  de  la y1 y2 y3 ...ym doua siruri de numere intregi det subsirul con de lungime maxima
#include <iostream>
#include <fstream>
#define INF 0x3f3f3f3f

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int  k,i,y[1025],x[1025],s[1025],m,n,j,z;
    k=1;
    f>>n >> m;
    for(i=1; i<=n; i++)
    {
        f>>x[i];
    }
    for(i=1; i<=m; i++)
    {
        f>>y[i];
    }
    z=0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(x[i]==y[j]&&j>z)
            {
                s[k]=x[i];
                y[j]=-INF;
                k++;
                z=j;
                j=m+1;

            }
        }
    }
    g << k-1 << '\n';
    for(i=1; i<k; i++)
        g<<s[i]<<" ";
    return 0;
}
