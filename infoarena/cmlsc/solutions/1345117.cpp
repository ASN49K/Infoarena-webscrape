#include <iostream>
#include <fstream>

using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
short int m(short int a,short int b)
{
    if (a<b) return a;
    return b;
}
void read(short int v[],short int x)
{
    for (int i=0;i<x;i++)
    {
        fi>>v[i];
    }
}
int main()
{
    short int M,N;
    fi>>M>>N;
    short int A[M],B[N],v[m(M,N)],i,j,k=0,y=0;
    read(A,M);
    read(B,N);
    if (m(M,N)==M)
    {
        for(i=y;i<N;i++)
        {
            for (j=y;j<M;j++)
            {
                if (A[j]==B[i])
                {
                    v[k]=A[j];
                    k++;
                    y=i;
                }
            }
        }
    }
    else
    {
        for (i=y;i<M;i++)
        {
            for (j=y;j<N;j++)
            {
                if (A[i]==B[j])
                {
                    v[k]=A[i];
                    k++;
                    y=i;
                }
            }
        }
    }
    fo<<k<<"\n";
    for (i=0;i<k;i++)
    {
        fo<<v[i]<<" ";
    }
    return 0;
}
