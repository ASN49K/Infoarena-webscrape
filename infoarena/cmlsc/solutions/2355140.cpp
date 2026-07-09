#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m[1030][1030];

int main()
{
    int M,N,a[1030],b[1030],i,j,v[50],x=0;
    fin>>M>>N;
    for(i=1;i<=M;i++)
        fin>>a[i];
    for(i=1;i<=N;i++)
        fin>>b[i];
    for(i=1;i<=M;i++)
        for(j=1;j<=N;j++)
            if(a[i]==b[j])
                m[i][j]=m[i-1][j-1]+1;
            else
                m[i][j]=max(m[i-1][j],m[i][j-1]);
    fout<<m[M][N]<<'\n';
    i=M;j=N;
    while(m[i][j])
        if(a[i]==b[j])
        {
            x++;
            v[x]=a[i];
            i--;
            j--;
        }
        else
            if(max(m[i-1][j],m[i][j-1])==m[i-1][j])
                i--;
            else
                j--;
    for(i=x;i>=1;i--)
        fout<<v[i]<<' ';
    fin.close();
    fout.close();
}
