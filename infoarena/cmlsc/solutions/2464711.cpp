#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[1024] , B[1024] , M[1001][1001] , R[1024];
int N , P , K;

int main()
{
    int i , j;
    fin >> N >> P;
    for(int i = 1 ; i <= N ; i++)
    {
        fin >> A[i];
    }
    for(int j = 1 ; j <= P ; j++)
    {
        fin >> B[j];
    }
    for(i = 1 ; i <= N ; i++)
    {
        for(j = 1 ; j <= P ; j++)
        {
            if(A[i] == B[j])
            {
                M[i][j] = 1 + M[i - 1][j - 1];
            }
            else
            {
                M[i][j] = max(M[i - 1][j] , M[i][j - 1]);
            }
        }
    }
    fout << M[N][P] << "\n";
    i = N;
    j = P;
    while(M[i][j] != 0)
    {
        if(M[i][j] == M[i - 1][j])
        {
            i --;
        }
        if(M[i][j] == M[i][j - 1])
        {
            j --;
        }
        else
        {
            R[++K] = A[i];
            i--;
            j--;
        }
    }
    for(i = K ; i >= 1 ; i--)
    {
        fout << R[i] << " ";
    }

    return 0;
}
