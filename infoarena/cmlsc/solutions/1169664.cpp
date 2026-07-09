#include <iostream>
#include <fstream>
#include <math.h>
#define inFile "cmlsc.in"
#define outFile "cmlsc.out"

using namespace std;

int a[1025],b[1025],w[1025][1025],rez[1024],maxim,i,j,m,n;

int main()
{
    ifstream fin(inFile);
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(j=1;j<=n;j++)
        fin>>b[j];
    fin.close();

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                w[i][j]=1+w[i-1][j-1];
            else
                w[i][j]=max(w[i-1][j],w[i][j-1]);
    for(i=m,j=n;i;)
        if(a[i]==b[j])
            rez[++maxim]=a[i],i--,j--;
        else
            if(w[i-1][j]<w[i][j-1])
                j--;
            else
                i--;

    ofstream fout(outFile);
    for(i=maxim;i;i--)
        fout<<rez[i]<<" ";
    fout.close();
}
