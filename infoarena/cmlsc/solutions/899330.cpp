#include <iostream>
#include <fstream>
#define LMax 1026

using namespace std;
int M,N,Aux=1,A[LMax],B[LMax],C[LMax],D[LMax], maxim=-1.e20;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    fin>>M>>N; int Temp,g=0,contor,contorbun, k=0, l=0;

    for(int i=1;i<=M;i++)
        fin>>A[i];
    for(int i=1;i<=N;i++)
        fin>>B[i];
    int h=1;
    do
    {
    for(int i=h;i<=M;i++)
    {
        l=0;
        for(int j=1;j<=N && l==0;j++)
            {
                if(g==0)
                {
                    if(A[i]==B[j])
                    {
                        C[k++]=B[j];
                        contor=j;
                        g=i; l=1;
                    }
                }
                else
                {
                    if(A[i]==B[j] && j>contor)
                    {
                        C[k++]=B[j];
                        contor=j; l=1;
                    }
                }
            }
    }
    if(maxim<k) {maxim=k; contorbun=g; for(int f=0;f<k;f++) D[f]=C[f];}
    h++; g=0; k=0;
    }
    while(h<=M);
    fout<<maxim<<endl;
    for(int f=0;f<maxim;f++) fout<<D[f]<<' ';
}
