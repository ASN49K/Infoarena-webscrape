#include <fstream>
using namespace std;
ifstream f("cmlsc.in");///Andrei.in
ofstream g("cmlsc.out");

short a[1034],b[1034],m,n,c[1034],nrc;

void citire()
{   f>>m>>n;
    for(int i=1;i<=m;i++) f>>a[i];
    for(int i=1;i<=n;i++) f>>b[i];
}

int main()
{   citire();

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if( a[i] == b[j] )
            {   int i1=i+1,j1=j+1,ok=0; c[++nrc]=a[i];
                while( ok == 1 )
                {   for(int k=j1;k<=n;k++)
                    {   if( b[k] == a[i1] ) {i1++; break;}
                        else if( b[k] == a[i1] and k == n ) {c[++nrc]=a[i1]; i1++; ok=0;}
                        else if( b[k] != a[i1] and k == n ) ok=0;
                    }
                    if( ok == 1 and i1 < m ) i1++;
                    else if( i1 == m ) break;
                }
                j=j1-1;
                i=i1;
            }

    g<<nrc<<'\n';
    for(int i=1;i<=nrc;i++) g<<c[i]<<" ";

g.close();
return 0;
}
