#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int s[1030][1030];
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout ("cmlsc.out");
    int n, m,a[1030],b[1030],i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
              if(a[i]==b[j])
                 s[i][j]=s[i-1][j-1]+1;
              else
                  s[i][j]=max(s[i-1][j],s[i][j-1]);
    fout<<s[n][m]<<"\n";
    i=n;
    j=m;
    int v[1030],k=0;
    while(i!=0&&j!=0)
    {
        if(a[i]!=b[j])
            {if(s[i-1][j]<s[i][j-1])
               j--;
            else
                i--;}
        else
        {
            v[++k]=a[i];
            i--;
            j--;
        }

    }
    for(i=k;i>0;i--)
        fout<<v[i]<<" ";



    return 0;
}
