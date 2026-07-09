#include <iostream>
#include <fstream>
#include <vector>

#define MAXN 1025

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

inline int maxim(int a , int b)
{
    return ((a > b) ? a : b);
}

int main()
{
    int N,M,aux, best, i,j;
    int A[MAXN][MAXN];

    f>>N>>M;

    vector<int> X;
    vector<int> Y;
    vector<int> sir;

    for(i = 0; i < M ; i++)
    {
        f>>aux;
        X.push_back(aux);
    }
    for(i = 0; i < N ; i++)
    {
        f>>aux;
        Y.push_back(aux);
    }

    for(i = 0; i < M; i++)
        A[0][i] = 0;
    for(i = 0; i < N; i++)
        A[i][0] = 0;


    int start = 1;
    int m_end = M;
    int n_end = N;

    while(start <= m_end && start <= n_end && X[start] == Y[start])
        start++;
    while(start <= m_end && start <= n_end && X[m_end] == Y[m_end])
    {
        m_end--;
        n_end--;
    }

    for(i = start ; i <= m_end; i++)
        for(j = start; j <= n_end; j++)
        {
            if (X[i] = Y[j])
                A[i][j] = A[i-1][j-1] + 1;
            else
                A[i][j] = maxim(A[i][j-1], A[i-1][j]);
        }

    for(i = M, j = N; i; )
        if (X[i] == Y[j])
        {
            sir.push_back(X[i]);
            --i;
            --j;
            ++best;
        }
        else if (A[i-1][j] < A[i][j-1])
            --j;
        else
            --i;

    g<<best<<endl;
    for(i = sir.size(); i ; i--)
    {
        g<<sir[i]<<" ";
    }
    return 0;
}
