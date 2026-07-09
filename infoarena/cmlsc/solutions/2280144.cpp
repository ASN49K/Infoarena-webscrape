#include <iostream>
#include <fstream>
#include <stack>
#define NMAX 1050

using namespace std;

int matrix[NMAX][NMAX], input1[NMAX], input2[NMAX];
stack<int> sol;

int maxValue(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void solve(int n, int m)
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (input1[i] == input2[j])
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else
                matrix[i][j] = maxValue(matrix[i-1][j], matrix[i][j-1]);

}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int n, m, ind1, ind2;
    fin >> n >> m;
    for (int i=1; i<=n; i++)
        fin >> input1[i];
    for (int j=1; j<=m; j++)
        fin >> input2[j];
    solve(n, m);
    fout << matrix[n][m] << "\n";
    ind1 = n;
    ind2 = m;
    while(matrix[ind1][ind2] > 0)
    {
        while(input1[ind1] != input2[ind2])
        {
            if (matrix[ind1-1][ind2] == matrix[ind1][ind2])
                ind1--;
            if (matrix[ind1][ind2-1] == matrix[ind1][ind2])
                ind2--;
        }
        sol.push(input1[ind1]);
        ind1--, ind2--;
    }
    while(!sol.empty())
    {
        fout << sol.top() << " ";
        sol.pop();
    }
    return 0;
}
