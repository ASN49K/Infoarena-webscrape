#include <iostream>
#include <fstream>
#include <vector>

#define max(a, b) ((a > b) ? a : b)

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int DP[1024][1024];

int main()
{
    int M, N, max = 0;
    fin >> M >> N;
    vector<int> A;
    vector<int> B;
    vector<int> sir;
    int i, j;
    
    for (i = 0; i < M + N; i++)
    {
        int x;
        fin >> x;
        if (i < M)
            A.push_back(x);
        else
            B.push_back(x);
    }

    for (i = 1; i <= M; i++)
    {
        for (j = 1; j <= N; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }
    /*verificare tabel
    for (int i = 0; i <= M; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            cout << DP[i][j] << " ";
        }
        cout << '\n';
    }
    */

    for (i = M, j = N; i > 0 && j > 0;)
    {
        if (DP[i][j] > max)
            max = DP[i][j];
        if (A[i - 1] == B[j - 1])
        {
            sir.push_back(B[j - 1]);
            i--;
            j--;
        }
        else
        {
            if (DP[i - 1][j] >= DP[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    fout << max << '\n';
    for (i = sir.size() - 1; i >= 0; i--)
    {
        fout << sir[i] << " ";
    }
}