#include <bits/stdc++.h>

std::ifstream fin ("cmlsc.in");
std::ofstream fout("cmlsc.out");

std::size_t M, N;
std::vector< std::vector < unsigned short int> > matrix;
std::vector < unsigned short int > A, B, C;

int main()
{
    fin >> M >> N;

    for(std::size_t i = 0; i < M; ++i)
    {
        unsigned short int temp;
        fin >> temp;

        A.push_back(temp);
    }

    for(std::size_t i = 0; i < N; ++i)
    {
        unsigned short int temp;
        fin >> temp;

        B.push_back(temp);
    }

    fin.close();

    matrix.resize(M + 1);
    for(std::size_t i = 0; i < matrix.size(); ++i)
        matrix[i].resize(N + 1, 0);

    for(std::size_t i = 1; i < matrix.size(); ++i)
    {
        for(std::size_t j = 1; j < matrix[i].size(); ++j)
            if(A[i-1] == B[j-1])
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else if(A[i-1] != B[j-1])
                matrix[i][j] = std::max(matrix[i-1][j], matrix[i][j-1]);
    }

    fout << matrix[M][N] << "\n";

    std::size_t i = M, j = N;
    while(i > 0 && j > 0)
    {
        if(A[i-1] == B[j-1])
        {
            C.push_back(A[i-1]);
            --i;
            --j;
        }
        else
        {
            if(matrix[i-1][j] > matrix[i][j-1])
                --i;
            else
                --j;
        }
    }

    for(std::size_t x = C.size(); x > 0; --x)
        fout << C[x-1] << " ";
    fout.close();

    return 0;
}

