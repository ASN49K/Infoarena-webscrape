#include <iostream>
#include <fstream>

using namespace std;

int A[1025] , B[1025] , Sol[1025][1025] , R[1025] , N , M;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    fin >> N >> M;
    for(int i = 1 ; i <= N ; i++)
    {
        fin >> A[i];
    }
    for(int j = 1 ; j <= M ; j++)
    {
        fin >> B[j];
    }
    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= M ; j++)
        {
            if(A[i] == B[j])
            {
                Sol[i][j] = Sol[i - 1][j - 1] + 1;
            }
            else
            {
                Sol[i][j] = max(Sol[i-1][j] , Sol[i][j - 1]);
            }
        }
    }
    fout << Sol[N][M] << endl;
    int i = N , j = M , K = 0;
    while(Sol[i][j] != 0)
    {
        if(Sol[i][j] == Sol[i - 1][j])
        {
            i--;
        }
        else if(Sol[i][j] == Sol[i][j - 1])
        {
                j--;
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
