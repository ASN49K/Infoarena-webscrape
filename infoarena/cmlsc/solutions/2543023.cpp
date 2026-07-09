#include <iostream>
#include <fstream>
#define DIM 1025

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void citire(int v[],int l)
{
    for(int i=1; i<=l; i++)
        f>>v[i];
}

short a[DIM][DIM];

int main()
{
    int  M,A[DIM],N,B[DIM],sir[DIM],k=0;
    f>>M>>N;
    citire(A,M);
    citire(B,N);
    for(int i=1; i<=M; i++)
        for(int j=1; j<=N; j++)
            if(A[i] == B[j])
                a[i][j] = a[i-1][j-1] + 1;
            else
                a[i][j] =max(a[i][j-1],a[i-1][j]);
    for(int i=M,j=N; i;)
    {
        if(A[i] == B[j])
        {
            sir[++k] = A[i];
            i--, j--;
        }
        else if(a[i-1][j] < a[i][j-1])
            j--;
        else
            i--;
    }
    g<<k<<"\n";
    while(k!=0)
        g<<sir[k--]<<" ";
}
