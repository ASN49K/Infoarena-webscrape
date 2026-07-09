#include <iostream>
#include <fstream>
using namespace std;
int A[1026],B[1026],C[1026],M,N,i,j,k,y=1,t[1026][1026];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int da(int i,int j)
{
    if(t[i][j]==t[i-1][j-1]+1)
    {
        C[y]=A[i];
        y++;
        return da(i-1,j-1);
    }
    else if(t[i][j]==t[i-1][j])
    {
        return da(i-1,j);
    }
    else if(t[i][j]==t[i][j-1])
    {
        return da(i,j-1);
    }
    else return 0;
}
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
            else if(t[i-1][j]>=t[i][j-1])
            {
                t[i][j]=t[i-1][j];

            }
            else
            {
                t[i][j]=t[i][j-1];

            }
        }
    da(i-1,j-1);
    fout<<k<<"\n";
    for(i=k;i>=1;i--)
        fout<<C[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}
