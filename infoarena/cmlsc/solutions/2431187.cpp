#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int A[1024],B[1024],M,N;
int i,j,ok1,ok2,k,aux;
int C[1024],D[1024];
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
                ok1++;
                C[++k]=A[i];
                aux=j;
            }
        }
        if(M<=N)
        {
            for(i=1;i<=N;i++)
                for(j=aux+1;j<=M;j++)
                if(A[i]==B[j])
            {
                ok2++;
                D[++k]=A[i];
                aux=j;
            }
        }
    if(ok1>=ok2)
    {
        g<<ok1<<"\n";
        for(i=1;i<=ok1;i++)
        g<<C[i]<<" ";
    }
    else
    {
        g<<ok2<<"\n";
        for(i=1;i<=ok2;i++)
        g<<C[i]<<" ";
    }
    return 0;
}
