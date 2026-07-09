#include <iostream>
#include <fstream>
using namespace std;

    int main()
    {
    fstream f;
    f.open("flip.in", fstream::in)
    int n[50][50],i,j,a,b;

    f>>a;
    f>>b;
    for(i=0;i<n;i++)
    {for(j=0;j<m;j++)
        f>>n[i][j];
    }
    f.close()
    f.open("flip.out", fstream::out)

    for(i=0;i<n;i++)
    {for(j=0;j<m;j++)
        n[i][j]=n[i][j]*-1;
    }
    for(i=0;i<n;i++)
    {for(j=0;j<m;j++)
    g<<n[i][]j;
    }
    f.close();
return 0;
}
