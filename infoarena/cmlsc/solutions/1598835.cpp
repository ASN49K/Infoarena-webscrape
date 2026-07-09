#include <fstream>
#include <iostream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, A[1500], B[1500], T[1500], L[1500];

void citire()
{
    int i;
    f>>m>>n;
    for(i=1;i<=m;i++) f>>A[i];
    for(i=1;i<=n;i++) f>>B[i];
}

void cmm(int k, int &l, int &t)
{
    for(int i=k+1;i<=m;i++)
        if(L[i]>l)
        {
            l=L[i];
            t=i;
        }
}

int main()
{
    int i, j, l, t;
    citire();
    for(i=m;i>=1;i--)
        for(j=n;j>=1;j--)
            if(A[i]==B[j])
            {
                l=t=0;
                cmm(i,l,t);
                L[i]=l+1;
                T[i]=t;
            }
    int maxim=0;
    for(i=1;i<=m;i++)
        if(L[i]>maxim)
        {
            maxim=L[i];
            j=i;
        }
    g<<maxim<<"\n";
    for(i=1;i<=maxim;i++)
    {
        g<<A[j]<<" ";
        j=T[j];
    }
    return 0;
}
