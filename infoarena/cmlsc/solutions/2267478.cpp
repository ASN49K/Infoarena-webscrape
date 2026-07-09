#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int A[10000],B[10000],i,j,N,M,c[10000],q;
int main()
{
    f>>M>>N;
    for(i=1;i<=M;i++)
        f>>A[i];
    for(i=1;i<=N;i++)
        f>>B[i];
        q=0;
    for(i=1;i<=M;i++)
    for(j=1;j<=N;j++)
    if(A[i]==B[j])
    {
        q++;
        c[q]=A[i];
    }
    for(i=1;i<=q-1;i++)
        for(j=i+1;j<=q;j++)
        if(c[i]>c[j])
        swap(c[i],c[j]);
    for(i=1;i<=q;i++)
        g<<c[i]<<" ";
    return 0;
}
