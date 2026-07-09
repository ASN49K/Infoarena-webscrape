#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    short n,m,k=1;
    short a[1025],b[1025],com[2050];

    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];

    for(int i=1;i<=m;i++)
        f>>b[i];

    short c[1025];
    /*for(int i=0;i<=n+m;i++)
    {
        if(i<=n)
            c[i]=a[i];
        else if(i>n)
            c[i]=b[i-n];

    }*/
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {if(b[i]==a[j])
         {c[k]=b[i];
         k++;}
        }
    }

    g<<k<<"\n";
    for(int i=1;i<k;i++)
        g<<c[i]<< " ";

    return 0;
}
