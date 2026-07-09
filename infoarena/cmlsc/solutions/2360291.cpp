#include <iostream>
#include <fstream>
#include <cstdlib>

#define LMax 1025
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

short int A[LMax],B[LMax],C[LMax][LMax],N,M,Sir[LMax];
int maxim(int x, int y)
{
    if(x>y)
        return x;
    return y;
}
void citire()
{
    f>>N>>M;
    short int i;
    for(i=1;i<=N;i++)
        f>>A[i];
    for(i=1;i<=M;i++)
        f>>B[i];
    f.close();
}
void p_dinamica()
{
    short int i,j;
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            if(A[i]==B[j])
                C[i][j]=1+C[i-1][j-1];
            else
                C[i][j]=maxim(C[i-1][j],C[i][j-1]);
    i=N; j=M;
    short int k=0;
    while(i)
    {
        if(A[i]==B[j])
        {
            k++;
            Sir[k]=A[i];
            i--;
            j--;
        }
        else if(C[i-1][j]<C[i][j-1])
            j--;
        else
            i--;
    }
    g<<k<<'\n';
    for(i=k;i>=1;i--)
        g<<Sir[i]<<" ";
}
int main()
{
    citire();
    p_dinamica();
    return 0;
}
