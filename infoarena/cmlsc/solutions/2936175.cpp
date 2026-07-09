#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int M, N, A[1050], B[1050], D[1050][1050], S[1050];

int main()
{
    int k=0;
    fin>>M>>N;
    for(int i=1;i<=M;i++)
        fin>>A[i];
    for(int i=1;i<=N;i++)
        fin>>B[i];
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
        {
            if(A[i]==B[j]){
                D[i][j]=D[i-1][j-1]+1;
                S[k++]=A[i];
            }
            else
                D[i][j]=D[i][j-1]>D[i-1][j]?D[i][j-1]:D[i-1][j];
        }
    fout<<D[M][N]<<"\n";
    for(int i=0;i<k;i++)
        fout<<S[i]<<" ";
}
