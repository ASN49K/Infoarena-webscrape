#include <fstream>
#include <iostream>
using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int A[1025],B[1025],i,j,D[1025][1025],M,N,sir[1025],n;
int main()
{
    f>>M>>N;
    for(i=1;i<=M;i++)   //citire
        f>>A[i];
    for(i=1;i<=N;i++)
        f>>B[i];

    for(i=0;i<=M+1;i++)   //conturare cu 0
        D[i][0]=D[i][N+1]=0;
    for(i=0;i<=N+1;i++)
        D[0][i]=D[M+1][i]=0;

    for(i=1;i<=M;i++)                      //formare matrice
        for(j=1;j<=N;j++)
        if(A[i]==B[j]) D[i][j]=D[i-1][j-1]+1;
        else D[i][j]=max(D[i-1][j],D[i][j-1]);

    i=M;j=N;
    while(i)                            //formare sir
    {
        if(A[i]==B[j]) {n++;
                        sir[n]=A[i];
                        i--;j--;

                        }
        else if(D[i-1][j]<D[i][j-1]) j--;
              else i--;
    }

    g<<n<<'\n';

    for(i=n;i>=1;i--)                           //afisare sir
        g<<sir[i]<<" ";
    return 0;
}
