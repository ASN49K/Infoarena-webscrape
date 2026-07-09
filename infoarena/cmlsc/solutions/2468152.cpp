#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");



int M,N,p,i,k, v[5], A[5],B[5];

int valid(int k)
{
 for(i=1;i<=N;i++)
    if(A[k]==B[i])
        return 1;
    return 0;

}

void afisare()
{
    g<<p<<"\n";
    for(i=1;i<=p;i++)
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



