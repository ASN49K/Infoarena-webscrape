#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");



int M,N,p,i,k, v[1024], A[1024],B[1024],lp;



int valid(int k)
{

for( i=1; i<k; i++)
   if(A[k]==A[i])   //elemente distincte
        return 0;

 for( i=1;i<=N;i++)     //elem din vectorul A prezent in vectorul B
    if(A[k]==B[i])
        return 1;
    else
    B[i]=0;

    return 0;

}

void afisare()
{
    g<<p-1<<"\n";
    for(int i=1;i<=p-1;i++)
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
        {   k++;
            v[p]=A[k];
        }
        while((valid(k)==0)&&(k<M));
    }
    while((k<M)&&(B[N]!=0));

    afisare();



    return 0;
}



