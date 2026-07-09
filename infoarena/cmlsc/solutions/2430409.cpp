#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int A[1024],B[1024],M,N;
int i,j,ok,k,aux;
int C[1024];
int main()
{   f>>M>>N;
    for(i=1;i<=M;i++)
        f>>A[i];
    for(i=1;i<=N;i++)
        f>>B[i];
    if(M>=N)
    {
        for(i=1;i<=M;i++)
            for(j=aux+1;j<=N;j++)
                if(A[i]==B[j])
            {
                ok++;
                C[++k]=A[i];
                aux=j;
            }
    }
    else
    {
        for(i=1;i<=N;i++)
            for(j=aux+1;j<=M;j++)
                if(A[i]==B[j])
            {
                ok++;
                C[++k]=A[i];
                aux=j;
            }
    }
    g<<ok<<"\n";
    for(i=1;i<=ok;i++)
        g<<C[i]<<" ";
    return 0;
}
