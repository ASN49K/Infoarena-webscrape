#include <iostream>
#include <fstream>
#include <vector>

const int SIZE = 1001;

int n, m;

int sir_a[SIZE], sir_b[SIZE];
int matrix[SIZE][SIZE];
std::vector<int> answear;

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int main()
{
    fin >> n >> m;

    for(int i = 1; i <= n; ++i)
        fin >> sir_a[i];

    for(int j = 1; j <= m; ++j)
        fin >> sir_b[j];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(sir_a[i] == sir_b[j]) // Daca un element din sirul a exista in sirul b
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            else
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);

    fout << matrix[n][m] << '\n';

    short lin = n, col = m, lg = matrix[n][m];

    while(matrix[lin][col])
    {
        if(matrix[lin][col] == lg && sir_a[lin] == sir_b[col])
        {
            answear.push_back(sir_a[lin]);
            --lin; --col; --lg;
        }
        else
            if(matrix[lin - 1][col] > matrix[lin][col - 1])
                --lin;
            else
                --col;
    }

    for(int i = answear.size() - 1 ; i >= 0 ; i--)
        fout << answear[i] << ' ';

    /**
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
    */
    return 0;
}
