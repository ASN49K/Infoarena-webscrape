#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <set>

#define newn G[nod][i]

using namespace std;

ifstream fin("petsoft.in");
ofstream fout("petsoft.out");

const int NMAX = 1010;

struct perechi{
    int da, nu;
}V[NMAX];

int N, M, DP[NMAX][NMAX], UZ[NMAX][NMAX];
set <int> G[NMAX];
//vector <bool> viz(NMAX);

int Comp(int i, int j, int A[])
{
    if(i == j) return 0;
    if(DP[i][j]) return DP[i][j];

    if(j - i == 1)
    {
        DP[i][j] = abs(A[j] - A[i]);
        return DP[i][j];
    }

    int v1 = Comp(i + 1, j, A), v2 = Comp(i, j - 1, A);
    if(v1 > v2)
    {
        DP[i][j] = v1;
        UZ[i][j] = A[i];
    }
    else
    {
        DP[i][j] = v2;
        UZ[i][j] = A[j];
    }

    if(j - i >= 2)
    {
        int v3 = Comp(i + 1, j - 1, A);
        if(DP[i][j] <= abs(A[j] - A[i]) + v3)
        {
            UZ[i][j] = UZ[i + 1][j - 1];
            DP[i][j] = v3;
        }
    }
    return DP[i][j];
}

int Dif_Max(int A[], int n)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            DP[i][j] = UZ[i][j] = 0;
    return Comp(1, n, A);
}

void DFS(int nod)
{
    bool pus = 0;
    int A[G[nod].size() + 1], B[G[nod].size() + 1]; int nr1 = 0, nr2 = 0;
    set <int> :: iterator it = G[nod].begin();
    for(; it != G[nod].end(); it++)
        {
            DFS(*it);
            if(!pus && nod <= *it) B[++nr1] = nod, pus = 1;
            A[++nr2] = B[++nr1] = *it;
            V[nod].da += V[*it].nu;
            V[nod].nu += V[*it].da;
        }
    if(!pus) B[++nr1] = nod;
    int notuz;
    if(nr2 >= 2)
    {
        int dif = Dif_Max(A, nr2);
        V[nod].nu = max(V[nod].nu, V[nod].da + dif);
    }
    if(nr1 >= 2)
    {
        notuz = UZ[1][nr1];
        cout << notuz << endl;
        int dif = Dif_Max(B, nr1);
        V[nod].da += dif;
        if(nr1 % 2) V[nod].da = max(V[nod].da, V[nod].da - V[notuz].nu + V[notuz].da);
    }
}

int main()
{
    fin >> N;
    for(int i = 1; i < N; i++)
    {
        int x; fin >> x;
        G[x].insert(i + 1);
    }
    DFS(1);
    fout << V[1].nu;

    for(int i = 1; i <= N; i++)
       ;// cout<<V[1].da << ' ' <<V[1].nu<<endl;
    return 0;
}
