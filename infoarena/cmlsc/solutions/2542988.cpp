#include <iostream>
#include <fstream>
#define DIM 1025

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void citire(short v[],short l)
{
    for(short i=1; i<=l; i++)
        f>>v[i];
}

void build_matrix(short s1[], short l1, short s2[], short l2, short a[][DIM])
{
    for(int i=1; i<=l1; i++)
        for(int j=1; j<=l2; j++)
            if(s1[i] == s2[j])
                a[i][j] = a[i-1][j-1] + 1;
            else
                a[i][j] = max(a[i-1][j],a[i][j-1]);
}

void build_subsequence(short s1[], short l1, short s2[], short l2, short a[][DIM], short sir[], short &best)
{
    best = 0;
    for(int i=l1, j=l2; i!=0;)
    {
        if(s1[i] == s2[j])
        {
            sir[++best] = s1[i];
            i--; j--;
        }
        else if(a[i-1][j] > a[i][j-1])
            i--;
        else
            j--;
    }
}

short a[DIM][DIM];

int main()
{
    short M,A[DIM],N,B[DIM],sir[DIM],k;
    f>>M>>N;
    citire(A,M);
    citire(B,N);
    build_matrix(A,M,B,N,a);
    build_subsequence(A,M,B,N,a,sir,k);
    g<<k<<"\n";
    while(k!=0)
        g<<sir[k--]<<" ";
}
