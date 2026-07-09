#include <iostream>
#include <fstream>

using namespace std;

int A[1025] , B[1025] , M[1025][1025] , R[1025];
int N , P;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int main()
{
    fin >> N >> P;
    for(int i = 1 ; i <= N ; ++i)
    {
        fin >> A[i];
    }
    for(int j = 1 ; j <= P ; ++j)
    {
        fin >> B[j];
    }
    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j = 1 ; j <= P ; ++j)
        {
            if(A[i] == B[j])
            {
                M[i][j] = M[i - 1][j - 1] + 1;
            }
            else
            {
                M[i][j] = max(M[i - 1][j] , M[i][j - 1]);
            }
        }
    }
    fout << M[N][P] << "\n";
    int i = N , j = P , K = 0;
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
            R[++K] = B[j];
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
