#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");



int M,N,p,i,k, v[1024], A[1024],B[1024];

int valid(int k)
{

for(int i=1; i<k; i++)
   if(A[k]<A[i])
        return 0;
 for(int i=1;i<=N;i++)
    if(A[k]==B[i])
        return 1;
    return 0;

}

void afisare()
{
    g<<p-1<<"\n";
    for(int i=1;i<p;i++)
        g<<v[i]<<" ";
        g<<"\n";
}


int main()
{
    f>>M>>N;
    for(i=1;i<=M;i++)
        f>>A[i];
    for(i=1; i<=N;i++)
        f>>B[i];


    do
    {
        p++;
     do
        {
            k++;
            v[p]=A[k];
        }
        while(valid(k)==0);
    }
    while(k<M);

    afisare();



    return 0;
}



