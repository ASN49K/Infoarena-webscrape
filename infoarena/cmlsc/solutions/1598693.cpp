#include <fstream>
#include <iostream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, A[1500], B[1500], sub[1500], cml[1500], cm=0;

void citire()
{
    int i;
    f>>m>>n;
    for(i=1;i<=m;i++) f>>A[i];
    for(i=1;i<=n;i++) f>>B[i];
}

int subs(int l)
{
    int i,j;
    for(i=1,j=0;i<=n&&j!=l;i++)
        if(B[i]==sub[j+1])
            j++;
    if(j==l) return 1;
    else return 0;
}

void backt(int k, int l)
{
    int i;
    sub[l]=A[k];
    if(subs(l))
    {
        if(l>cm)
        {
            cm=l;
            for(i=1;i<=l;i++)
                cml[i]=sub[i];
        }
        if(l<m)
            for(i=k+1;i<=m;i++)
                backt(i,l+1);
    }
}

int main()
{
    int i;
    citire();
    if(n<m)
    {
        for(i=1;i<=m;i++)
            swap(A[i],B[i]);
        swap(m,n);
    }
    for(i=1;i<=m;i++) backt(i,1);
    g<<cm<<"\n";
    for(i=1;i<=cm;i++) g<<cml[i]<<" ";
    return 0;
}
