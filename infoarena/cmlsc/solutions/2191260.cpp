#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m1[1025][1025],v1[1025],v2[1025],sol[1025];



int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v1[i];
    for(int i=1;i<=m;i++)
        fin>>v2[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v1[i]==v2[j])
                m1[i][j]=m1[i-1][j-1]+1;
            else
                m1[i][j]=max(m1[i-1][j],m1[i][j-1]);
        }
    }

    int a=m1[n][m],i=n,j=m,aux=1;
    while(a!=0){
        if(v1[i]==v2[j]){
            sol[aux]=v1[i];
            i--;
            j--;
            a--;
            aux++;
        }
        else{
            if(m1[i-1][j]==m1[i][j])
                i--;
            else
                j--;
        }
    }
    fout<<aux-1<<'\n';
    for(int s=aux-1;s>=1;s--)
        fout<<sol[s]<<' ';


    return 0;
}
