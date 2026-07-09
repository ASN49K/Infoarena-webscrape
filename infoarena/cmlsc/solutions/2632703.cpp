#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[1025],B[1025];
int m[1025][1025];

void afisare(int i, int j)
{
    if(m[i][j] == 0)
    {

    }
    else
    {
        if(m[i][j]==m[i-1][j])
        {
            afisare(i-1,j);
        }
        else
        {
            if(m[i][j]==m[i][j-1])
            {
                afisare(i,j-1);
            }
            else
            {
                afisare(i-1,j-1);
                fout<<A[i]<<" ";
            }
        }
    }
}

int main()
{

    int M,N;
    fin>>M>>N;
    for(int i=1;i<=M;i++)
    {
        fin>>A[i];
    }
    for(int i=1;i<=N;i++)
    {
        fin>>B[i];
    }
    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(A[i]==B[j])
            {
                m[i][j]=m[i-1][j-1]+1;
            }
            else
            {
                m[i][j]=max(m[i-1][j],m[i][j-1]);
            }
        }
    }
    fout<<m[M][N]<<endl;
    afisare(M,N);
    return 0;
}
