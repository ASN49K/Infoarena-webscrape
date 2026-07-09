#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v[1025][1025],s[1025],a[1025],b[1025],N,M,sir;

int main()
{
    fin>>M>>N;
    for(int i=1;i<=M;i++)
        fin>>a[i];
    for(int i=1;i<=N;i++)
        fin>>b[i];
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
            if(a[i]==b[j]) v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=max(v[i-1][j],v[i][j-1]);
    for(int i=M,j=N;i; )
        if(a[i]==b[j])
           {s[sir++]=a[i];i--;j--;}
        else
           if(v[i-1][j]<v[i][j-1])
              j--;
           else
              i--;

    fout<<sir<<endl;
    for(int i=sir-1;i>=0;i--)
        fout<<s[i]<<" ";

    return 0;
}
