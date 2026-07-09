#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");



int M,N,p,i,k, v[1024], A[1024],B[1024],lp;

int distinct(int k)
{
    if(k==1)
        return 1;


for( i=1; i<k; i++)
   if((A[k]==A[i]))   //elemente distincte
        return 0;

    return 1;
}

int prezent(int k)
{
     for( i=1;i<=N;i++)     //elem din vectorul A prezent in vectorul B
    if(A[k]==B[i])
        return 1;


    return 0;
}
int valid(int k)
{


    if(distinct(k)==0)
        return 0;
    if(prezent(k)==0)
        return 0;

    return 1;

}

void afisare()
{
    g<<p<<"\n";
    for(int i=1;i<=p;i++)
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
     do
        {
            cout<<++k<<"-->"<<valid(k)<<endl;
        }
           while((valid(k)==0)&&(k<M));
            v[++p]=A[k];
            cout<<"v["<<p<<"]="<<v[p]<<endl;
    }
    while(k<M);

    afisare();
   /* cout<<prezent(1)<<endl;
    cout<<prezent(2)<<endl;
    cout<<prezent(3)<<endl;
    cout<<prezent(4)<<endl;
    cout<<prezent(5)<<endl;*/


    return 0;
}

