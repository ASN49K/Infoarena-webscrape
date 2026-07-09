#include <iostream>
#include <vector>
#include <fstream>

std::ifstream f("cmlsc.in");
std::ofstream g("cmlsc.out");

std::vector<int> A;
std::vector<int> B;

int M, N, K, x, v[20][20], min, nr = 0;

int main()
{
    f >> M >> N;
    for (int i = 1; i <= M; i++)
    {
        f >> x;
        A.push_back(x);
    }

    for (int i = 1; i <= N; i++)
    {
        f >> x;
        B.push_back(x);
    }

    for (int i = 0; i < M; i++)
        v[i][0] = i;
    for (int i = 0; i < N; i++)
        v[0][i] = i;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                v[i][j] = v[i - 1][j - 1];
                g << v[i][j] << " ";
                nr++;
            }
            else
            {
                min = v[i - 1][j];
                if (v[i - 1][j - 1] < min)
                    min = v[i - 1][j - 1];
                else if (v[i][j - 1] < min)
                    min = v[i][j - 1];

                v[i][j] = min + 1;
            }
        }
    }
    g << "\n"
      << nr;

    return 0;
}