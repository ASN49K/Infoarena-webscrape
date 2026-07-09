#include <iostream>
#include <fstream>
using namespace std;
int main()
{

int A[255], B[255],i,j,M,N,k=0,C[255];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

f>>M;
f>>N;
for(i=0;i<M;i++)
    f>>A[i];
for(j=0;j<N;j++)
    f>>B[j];
if(M>N)
{for(i=0;i<M;i++)
for(j=0;j<N;j++)
if(A[i]==B[j])
{
    k++;
    C[k]=A[i];
}
}


else
    for(j=0;j<N;j++)
    for(i=0;i<M;i++)
        if(A[i]==B[j])
{
        k++;
    C[k]=A[i];
}
g<<k;
g<<endl;
for(i=1;i<=k;i++)
    g<<C[i]<<" ";
f.close();
g.close();
return 0;
}


