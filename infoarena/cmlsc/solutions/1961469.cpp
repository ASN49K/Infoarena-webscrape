#include <iostream>
#include <fstream>

using namespace std;

int a[1030],b[1030],vcmlsc[1030][1030],cmlsc[1030];

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int i,j,k,m,n,vmax,aux;
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
    for(i=0;i<=m;i++)
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)vcmlsc[i][j]=0;
            else if(a[i]==b[j])vcmlsc[i][j]=vcmlsc[i-1][j-1]+1;
            else vcmlsc[i][j]=max(vcmlsc[i-1][j],vcmlsc[i][j-1]);
        }
    aux=vmax=vcmlsc[m][n];
    fout<<vmax<<"\n";
    i=m;j=n;
    while(vcmlsc[i][j])
        if(a[i]==b[j])cmlsc[aux--]=a[i],i--,j--;
        else if(vcmlsc[i-1][j]>vcmlsc[i][j-1])i--;
        else j--;
    for(i=1;i<=vmax;i++)
        fout<<cmlsc[i]<<" ";
    return 0;
}
