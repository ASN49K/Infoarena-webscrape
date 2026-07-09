#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[99], B[99], MAX=0, M, N, i, j, C[99], D[99], k=0, MAX1;

int cmlsc(int a[99], int b[99], int c[99], int x, int y)
{
    for(x=0; x<M-1; x++)
    {
        for(y=k; y<N-1; y++)
            {
               if(a[x]==b[y])
                {
                   c[MAX]=a[x];
                   MAX++;
                   k=y;
                   if(k==N-1)
                    return 0;
                   break;
                }
            }
     }
return 0;
}
int main(void)
{
    fin>>M>>N;
    for(i=0; i<M-1; i++)
        fin>>A[i];
    for(j=0; j<N-1; j++)
        fin>>B[j];
    cmlsc(A, B, C, i, j);
    MAX1=MAX;
    MAX=0; k=0;
    cmlsc(A, B, D, j, i);
    if(MAX1>=MAX){
        fout<<MAX1<<"\n";
        for(i=0; i<MAX1-1; i++)
            fout<<C[i];}
    else
        {fout<<MAX<<"\n";
        for(i=0; i<MAX-1; i++)
            fout<<D[i];}
fin.close();
fout.close();
    return 0;
}
