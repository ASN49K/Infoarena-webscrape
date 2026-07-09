#include <iostream>
#include <fstream>

using namespace std;

#define maxim(a,b) ((a)>(b)?(a):(b))

int l[1025][1025],n,m,a[1025],b[1025],sol[1025];

int main()
{
    ifstream fin("cmlsc.in");
    fin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                l[i][j]=l[i-1][j-1]+1;
            else
                l[i][j]=(maxim(l[i][j-1],l[i-1][j]));
    ofstream fout("cmlsc.out");
    fout<<l[n][m]<<"\n";
    i=n;j=m;
    while(i!=0&&j!=0)
    {
        if(a[i]==b[j])
        {
            sol[l[i][j]]=a[i];
            i--;
            j--;
        }
        else
         if(l[i][j-1]>l[i-1][j])
           j--;
           else
           i--;
    }
    for(i=1;i<=l[n][m];i++)
     fout<<sol[i]<<" ";
     fout<<"\n";

    return 0;
}
