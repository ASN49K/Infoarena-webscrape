#include <iostream>
#include <fstream>
#define LMax 1026

using namespace std;
int M,N,Aux=1,A[LMax],B[LMax],C[LMax], maxim=-1.e20;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    fin>>M>>N; int Temp,g=0,contor,contorbun, k=0;

    for(int i=1;i<=M;i++)
        fin>>A[i];
    for(int i=1;i<=N;i++)
        fin>>B[i];
    int h=1;
    do
    {
    for(int i=h;i<=M;i++)
    {
        for(int j=1;j<=N;j++)
            {
                if(g==0)
                {
                    if(A[i]==B[j])
                    {
                        k++;
                        contor=j;
                        g=i;
                    }
                }
                else
                {
                    if(A[i]==B[j] && j>contor)
                    {
                        k++;
                        contor=j;
                    }
                }
            }
    }
    if(maxim<k) {maxim=k; contorbun=g;}
    h++; g=0; k=0;
    }
    while(h<M);
    cout<<maxim<<endl;
    g=0;
    for(int i=contorbun;i<=M;i++)
        for(int j=1;j<=N;j++)
        {
            {
                if(g==0)
                {
                    if(A[i]==B[j])
                    {
                        cout<<B[j]<<' ';
                        contor=j;
                        g=i;
                    }
                }
                else
                {
                    if(A[i]==B[j] && j>contor)
                    {
                        cout<<B[j]<<' ';
                        contor=j;
                    }
                }
            }
        }


}
