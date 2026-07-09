#include <iostream>
#include <fstream>
#include <stack>
#define MAX 1034

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int mat[MAX][MAX], N[MAX], M[MAX];

stack <int> stack1;

enum direction
{
    diag, st, sus
};

direction dir[MAX][MAX];

int main()
{
    int n, m;
    f >> n >> m;
    for(int i = 1; i <= n; i++)
        f >> N[i];
    for(int i = 1; i <= m; i++)
        f >> M[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
    {
        if(N[i] == M[j])
        {
            mat[i][j] = mat[i - 1][j - 1] + 1;
            dir[i][j] = diag;
        }
        else
        {
            int maxim = max(mat[i][j - 1], mat[i - 1][j]);
            if(maxim == mat[i][j - 1])
            {
                dir[i][j] = st;
            }
            else dir[i][j] = sus;
            mat[i][j] = maxim;

        }
    }
    g << mat[n][m] << '\n';
    while(mat[n][m])
    {
        if(N[n] == M[m]) stack1.push(N[n]);
        if(dir[n][m] == diag)
        {
            n--;
            m--;
        }
        else if(dir[n][m] == st) m--;
        else n--;
    }

    while(!stack1.empty())
    {
        g << stack1.top() << ' ';
        stack1.pop();
    }
    f.close();
    g.close();

    return 0;
}
