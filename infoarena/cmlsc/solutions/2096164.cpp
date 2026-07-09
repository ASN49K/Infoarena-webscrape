#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int L[1025][1025],A[1025],B[1025],S[1025];
int k;
void creare(int i,int j)
{
    if(i>=1&&j>=1)
        if(A[i]==B[j])
            {creare(i-1,j-1);
            k++;
            S[k] = A[i];
            }
        else if(L[i-1][j]>L[i][j-1]) creare(i-1,j);
                else creare(i,j-1);

}



int main()
{
    int j,i,M,N;
    fin>>M>>N;

    for(i=1;i<=M;i++)
        fin>>A[i];
    for(i=1;i<=N;i++)
        fin>>B[i];
    for(i=0;i<=M;i++)
        L[i][0] = 0;
    for(j=1;j<=N;j++)
        L[0][j] = 0;
    for(i=1;i<=M;i++)
        for(j=1;j<=N;j++)
            if(A[i]==B[j]) L[i][j] = L[i-1][j-1] + 1;
        else L[i][j] = max(L[i-1][j],L[i][j-1]);
    /*
    for(i=1;i<=M;i++)
        {for(j=1;j<=N;j++)
            fout<<L[i][j]<<" ";
            fout<<'\n';
        }
    */

    k = 0;
    creare(M , N);
    fout<< k <<'\n';
    for(i=1;i<=k;i++)
        fout<<S[i]<<" ";


    return 0;
}
