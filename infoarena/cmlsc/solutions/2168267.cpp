#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],d[1025][1025],sir[1025],n,m,bst;
void Citire()
{
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
}
void Calc()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
}
/*void Afisare()
{
    int i,j;
    for(i=n,j=m;i>=1;)
    {
        if(a[i]=b[j])
            sir[++bst]=a[i],i--,j--;
        else if(d[i-1][j]<d[i][j-1])
                --j;
             else i--;
    }
    fout<<bst<<"\n";
    for(i=bst;i>=1;i--)
        fout<<sir[i]<<" ";
}
*/
void Afisare()
{
    int i,j;
    for(i=n,j=m;i>=1;)
        if(a[i]==b[j])
            {
             sir[++bst]=a[i];
             i--;
             j--;
            }
         else
            if(d[i-1][j]<d[i][j-1]) j--;
            else i--;
     fout<<bst<<"\n";
     for(i=bst;i>=1;i--)
        fout<<sir[i]<<" ";
}

int main()
{   Citire();
    Calc();
    Afisare();
    return 0;
}
