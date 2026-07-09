#include <iostream>
#include<fstream>
using namespace std;ifstream f("cmlsc.in");ofstream g("cmlsc.out");

int gasit(int v[1025],int n,int x)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(v[i]==x)
            return 1;
    }
    return 0;
}
int main()
{
    int M,N,A[1025],B[1025],i,max=0;
    f>>M>>N;
    for(i=1;i<=M;i++)
        f>>A[i];
    for(i=1;i<=N;i++)
        {f>>B[i];
        if (gasit(A,M,B[i])==1)
        max++;}
    g<<max<<"\n";
    for(i=1;i<=N;i++)
        if (gasit(A,M,B[i])==1)
            g<<B[i]<<" ";
    return 0;
}
