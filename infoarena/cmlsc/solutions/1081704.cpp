#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int i,j,n,m,a[100],b[100],c[100],x,k;
void citire()
{
    fin>>n;
    fin>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(j=1;j<=m;j++)
        fin>>b[j];
    fin.close();
}
void rezolvare()
{
    x=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
            {
                x++;
                c[x]=a[i];
                break;
            }
}
void afisare()
{
    fout<<x<<"\n";
    for(i=1;i<=x;i++)
        fout<<c[i];
    fout.close();
}
int main()
{
    citire();
    rezolvare();
    afisare();
    return 0;
}

