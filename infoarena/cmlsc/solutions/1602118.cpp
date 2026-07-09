#include <fstream>
#include <iostream>
using namespace std;
//#define FOR(a) for(int i=1;i<=n;i++)

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, A[1025], B[1025], T[1025], L[1025];

void citire()
{
    int i;
    f>>m>>n;
    for(i=1;i<=m;i++) f>>A[i];
    for(i=1;i<=n;i++) f>>B[i];
}

void cmm(int k, int &l, int &t)
{
    for(int i=k+1;i<=n;i++)
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
        for(j=1;j<=n;j++)
            if(A[i]==B[j])
            {
                //cout<<"A "<<A[i]<<" B "<<B[j]<<"\n";
                l=t=0;
                cmm(j,l,t);
                L[j]=l+1;
                T[j]=t;
                //FOR(m) cout<<T[i]<<" "; cout<<"\n";
                //FOR(m) cout<<L[i]<<" "; cout<<"\n\n";
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
        g<<B[j]<<" ";
        j=T[j];
    }
    //for(i=1;i<=m;i++) cout<<T[i]<<" "; cout<<"\n";
    //for(i=1;i<=m;i++) cout<<L[i]<<" "; cout<<"\n";
    return 0;
}
