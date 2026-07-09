#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int N,M;
int main()
{
    int i,j;
    in>>N>>M;
    int A[N],B[M];
    for(i=1;i<=N;i++)
        in>>A[i];
    for(i=1;i<=M;i++)
        in>>B[i];
    int nr=0;
    int C[N];
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            if(A[i]==B[j])
            {
                ++nr;
                C[nr]=A[i];
            }
    out<<nr<<endl;
    for(i=1;i<=nr;i++)
        out<<C[i]<<" ";
    
}
