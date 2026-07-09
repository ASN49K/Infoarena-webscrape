#include <iostream>
#include <fstream>
using namespace std;
const int nmax=1025;
int a[nmax],b[nmax],c[nmax][nmax],N,M;
void citire()
{
    ifstream fin("cmlsc.in");
    fin>>N>>M;
    for(int i=1;i<=N;++i)
        fin>>a[i];
    for(int j=1;j<=M;++j)
        fin>>b[j];

}
void formare()
{
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
    {
        if(a[i]==b[j])
            c[i][j]=c[i-1][j-1]+1;
        else
            c[i][j]=max(c[i-1][j],c[i][j-1]);
    }
}
void afisare()
{
    int lung=c[N][M],sir[nmax],j=0;
    while(N && M!=0)
    {
        if(a[N]==b[M])
        {
            sir[++j]=a[N];
            N--;
            M--;
        }
        else
        {
            if(c[N-1][M]>c[N][M-1])
                N--;
            else
                M--;
        }

    }
    ofstream fout("cmlsc.out");
    fout<<j<<"\n";
    for(int i=j;i>=1;--i)
        fout<<sir[i]<<" ";
}
int main()
{
    citire();
    formare();
    afisare();
    return 0;
}
