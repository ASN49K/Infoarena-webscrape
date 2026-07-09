#include <fstream>
using namespace std;
ifstream  fin("cmlsc.in");
ofstream fout("cmlsc.out");
int M,N,A[1030],B[1030],v[1030][1030],i,j,nx,k,x[1030];
char W[1030][1030];
int main()
{
    fin>>M>>N;

    for(i=1; i<=M; i++)
    {
        fin>>A[i];
    }

    for(i=1; i<=N; i++)
    {
        fin>>B[i];
    }

    ///v[i][j]=lungimea celui mai lung subsir comun dintre A[1....i] si B[1.....j]

    ///v[0][j]=0, v[i][0]=0

    for(i=1; i<=M; i++)
    {
        for(j=1; j<=N; j++)
        {
            if(A[i]==B[j])
            {
                v[i][j]=1+v[i-1][j-1];
                W[i][j]='d';
            }
            else
            {
                if(v[i-1][j]>v[i][j-1])
                {
                    v[i][j]=v[i-1][j];
                    W[i][j]='n';
                }
                else
                {
                    v[i][j]=v[i][j-1];
                    W[i][j]='v';
                }
            }
        }
    }

    fout<< v[M][N] << "\n";
    nx=v[M][N];

    i=M;
    j=N;
    k=nx;

    while(i>0 && j>0)
    {
        if(W[i][j]=='d')
        {
            x[k]=A[i];
            k--;
            i--;
            j--;
        }
        else
        {
            if(W[i][j]=='n')
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    for(i=1; i<=nx; i++)
    {
        fout<< x[i] << " ";
    }

    return 0;
}
