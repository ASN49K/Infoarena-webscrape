#include <iostream>
#include <fstream>
using namespace std;
int a[1025],b[1025],c[1025][1025];

  ofstream fout("cmlsc.out");
void matrix(int i,int j)
{
    if(i==0||j==0)
        c[i][j]=0;
    else if(a[i]==b[j])
        c[i][j]=1+c[i-1][j-1];
    else  if(c[i-1][j]>c[i][j-1])
        c[i][j]=c[i-1][j];
    else c[i][j]=c[i][j-1];


}

void printsol(int i,int j)
{
    if(i==0 || j==0) fout<<"";
    else if(a[i]==b[j])
    {
        printsol(i-1,j-1);
        fout<<a[i]<<" ";
    }
    else if(c[i-1][j]>c[i][j-1])
        printsol(i-1,j);
    else printsol(i,j-1);
}
int main()
{
    ifstream fin("cmlsc.in");

    int m,n,i=1,j=1;
    fin>>m>>n;
    for(int i=1; i<=m; i++)
        fin>>a[i];
    for(int i=1; i<=n; i++)
        fin>>b[i];

    for(int i=0; i<=m; i++)
        for(int j=0; j<=n; j++)
            matrix(i,j);

    fout<<c[m][n]<<'\n';

 printsol(m,n);
fin.close();
fout.close();
    return 0;
}
