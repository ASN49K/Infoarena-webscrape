#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
unsigned short int a[1025],b[1025],d[1025][1025],m,n,aux;
int main()
{
    fin>>m>>n;
    for(int i=0; i<m; i++)
        fin>>a[i];
    for(int i=0; i<n; i++)
        fin>>b[i];
    if(a[0]==b[0])
        d[0][0]=1;
    for(int i=1; i<m; i++){
        d[0][i]=d[0][i-1];
        if(a[i]==b[0])
            d[0][i]=1;
    }
    for(int i=1; i<n; i++){
        d[i][0]=d[i-1][0];
        if(a[0]==b[i])
            d[i][0]=1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            d[i][j]=max(d[i-1][j],max(d[i-1][j-1],d[i][j-1]));
            if(a[j]==b[i])
                d[i][j]+=1;
        }
    }
    fout<<d[n-1][m-1]<<'\n';
    int nr=1;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(d[i][j]==nr){
                nr++;
                fout<<a[j]<<' ';
            }

    return 0;
}
