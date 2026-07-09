#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1027],b[1027],na,nb,sir[1027],m[1027][1027],i,j,lg=0;
int main()
{
    f>>na>>nb;
    for(i=1;i<=na;i++)
        f>>a[i];
    for(i=1;i<=nb;i++)
        f>>b[i];
    for(i=1;i<=na;i++)
        for(j=1;j<=nb;j++)
        {
            if(a[i]==b[j])
                m[i][j]=m[i-1][j-1]+1;
            else m[i][j]=max(m[i-1][j],m[i][j-1]);
        }
    i=na;j=nb;
    while(i>0)
    {
        if(a[i]==b[j])
        {
            sir[++lg]=a[i--];
            j--;
        }
        else if(m[i-1][j]<m[i][j-1])j--;
        else i--;
    }
    for(i=lg;i>0;i--)g<<sir[i]<<" ";
}
