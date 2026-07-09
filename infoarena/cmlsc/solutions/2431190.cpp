#include <iostream>
#include <fstream>
using namespace std;
int A[1024],B[1024],C[1024],M,N,i,j,k,y,ok,v,t[1024][1024];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
    fin>>M>>N;
    for(i=1;i<=M;i++)
        fin>>A[i];
    for(j=1;j<=N;j++)
        fin>>B[j];

    for(i=1;i<=M;i++)
        for(j=1;j<=N;j++)
        {
            if(A[i]==B[j])
            {
                t[i][j]=t[i-1][j-1]+1;
                k++;
            }
            else if(A[i]!=B[j])
                t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
        y=1;
        ok=1;
        v=2;
    for(i=1;i<=M;i++)
       {
          for(j=1;j<=N;j++)
        {
            if(t[i][j]==1 && ok==1)
            {
                C[y]=A[i];
                y++;
                ok=0;
            }
            else if(t[i][j]==t[i][j-1]+1 && v==t[i][j] )
            {
                C[y]=A[i];
                y++;
                v++;
            }
        }

       }
       fout<<k<<"\n";
       for(i=1;i<=k;i++)
        fout<<C[i]<<" ";

    fin.close();
    fout.close();
    return 0;
}
