#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,cmsc[1027][1027],sir[1025],maxi;
int maxim(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
void citire()
{
    fin>>n>>m;
    for(int i=2;i<=n+1;i++)
        fin>>cmsc[0][i];
        for(int j=2;j<=m+1;j++)
        fin>>cmsc[j][0];
}
void build()
{
     int sw=1;
     for(int i=2;i<=m+1;i++)
                for(int j=2;j<=n+1;j++)
                if(cmsc[i][0]==cmsc[0][j])
                cmsc[i][j]=1+cmsc[i-1][j-1];
            else
                cmsc[i][j]=maxim(cmsc[i][j-1],cmsc[i-1][j]);

}
void parcurgere()
{
    int i=m+1,j=n+1;
    maxi=cmsc[m+1][n+1];
    fout<<maxi<<endl;
    while(cmsc[i][j]!=0)
    {
        if(cmsc[i-1][j]==cmsc[i][j])
            i=i-1;
        else
        if(cmsc[i][j]==cmsc[i][j-1])
            j=j-1;
        else
        {
            i=i-1;
            j=j-1;
            sir[maxi]=cmsc[0][j+1];
            maxi=maxi-1;
        }
    }
    for(i=1;i<=cmsc[m+1][n+1];i++)
    fout<<sir[i]<<"  ";

}
int main()
{
    citire();
    build();
    parcurgere();
    return 0;
}
