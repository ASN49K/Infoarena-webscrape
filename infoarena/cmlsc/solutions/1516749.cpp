#include <fstream>
#include<iostream>
using namespace std;
int c[1025][1025];
int main()
{
    int i,j,n,m,subsir[1025],a[1025],b[1025];
    //CITIRE
    ifstream fin("cmlsc.in");
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>a[i];
    for (j=1;j<=m;j++) fin>>b[j];
    fin.close();

   //CONSTRUIM MATRICEA SOLUTIE
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    if(a[i]==b[j])  c[i][j]=c[i-1][j-1]+1;
    else c[i][j]=max(c[i-1][j],c[i][j-1]);

//AFISAM SOLUTIA
    ofstream fout("cmlsc.out");
    fout<<c[n][m]<<endl;//c[n][m] - lungimea celui mai lung subsir

    int k=c[n][m];
    i=n;j=m;//vom construi subsirul de la dreapta la stanga
    while(k>0)

    {
        if (a[i]==b[j])
        {subsir[k]=a[i];k--;i--;j--;}
        else
        if(c[i-1][j]>c[i][j-1])i--;else j--;

    }

    // afisam subsirul de lungime maxima pe care l/
k=c[n][m];
        for(i=1;i<=k;i++)
            fout<<subsir[i]<<" ";
        return 0;
    }
