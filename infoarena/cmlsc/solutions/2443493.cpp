#include <iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1000],b[1000];
void citire()
{f>>n>>m;
for(int i=1;i<=n;i++)
    f>>a[i];
for(int i=1;i<=m;i++)
    f>>b[i];
}
int secv[1000][1000];
int numere[100],k=1;

int main()
{citire();
    int i,j;
    for(i=0;i<=n;i++)
        {secv[0][i]=0;
        }
    for(i=0;i<=m;i++)
        secv[i][0]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            {secv[i][j]=1+secv[i-1][j-1];
            if(secv[i][j]!=0)
            {
                numere[k++]=secv[i][j];
            }
            }
        else
            {secv[i][j]=max(secv[i-1][j],secv[i][j-1]);
            if(secv[i][j]!=0)
            {
                numere[k++]=secv[i][j];
            }
            }
    }
k--;
 g<<secv[n][m]<<endl;
 for(i=1;i<=k;i++)
    g<<numere[i]<<" ";
    return 0;
}
