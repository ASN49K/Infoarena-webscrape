#include <iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int N,M,A[1025],B[1025],poz[1025],L[1025][1025],C[1025];
int main()
{
f>>N>>M;int MAX;
for(int i=1;i<=N;i++)
    f>>A[i];
    for(int j=1;j<=M;j++)
    f>>B[j];
for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
    if(A[i]==B[j])
        L[i][j]=L[i-1][j-1]+1;
    else L[i][j]=max(L[i-1][j],L[i][j-1]);
    MAX=L[N][M];
    g<<MAX<<"\n";
int k=0,i=N,j=M;
while(i)
    if(A[i]==B[j])
        C[k++]=A[i],i--,j--;
        else
        {if(L[i][j-1]>L[i-1][j])
            j--;
        else i--;
            }
for(int i=k-1;i>=0;i--)
    g<<C[i]<<" ";
    return 0;
}
