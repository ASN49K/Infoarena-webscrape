#include <iostream>
#include <fstream>
using namespace std;

void sort1(int v[1025], int length)
{
    int i,j,aux;
    for(i=1; i<length; i++)
        for(j=i+1; j<=length; j++)
            if(v[i]>v[j])
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
}

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int M, N, A[1025], B[1025],C[1025], i, j, k;

    f>>M>>N;

    for(i=1; i<=M; i++)
        f>>A[i];
    for(j=1; j<=N; j++)
        f>>B[j];

    sort1(A,M);
    sort1(B,N);

    i=1;
    j=1;
    k=1;
    while(i<=M && j<=N)
    {
        if(A[i]<B[j])
            i++;
        else if(B[j]<A[i])
            j++;
        else
            C[k++]=B[j++];
    }
    g<<k-1<<"\n";
    for(i=1; i<k; i++)
        g<<C[i]<<" ";
    f.close();
    g.close();
    return 0;
}
