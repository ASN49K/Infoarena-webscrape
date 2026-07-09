#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1024 + 5;

int n, m;
int a[NMAX], b[NMAX];
int dp[NMAX][NMAX];
int rec[NMAX][NMAX];
bool viz[NMAX][NMAX];

vector <int> sol;

void Read()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i <= m; ++i)
        fin >> b[i];
}

void Print(int i, int j)
{
    if (i > n)
        return;
    if (j > m)
        return;
    if(rec[i][j] == 0)
    {
        sol.push_back(a[i]);
        Print(i + 1, j + 1);
    }
    else if(rec[i][j] == 1)
    {
        Print(i + 1, j);
    }
    else
        Print(i, j + 1);
}
/*
int Back(int i, int j)
{
    if (i > n)
        return 0;
    if (j > m)
        return 0;

    if (viz[i][j])
        return dp[i][j];
    viz[i][j] = true;
    int &ans = dp[i][j];
    int &father = rec[i][j];

    if (a[i] == b[j])
    {
        ans = 1 + Back(i + 1, j + 1);
    }
    else
    {
        if (Back(i + 1, j) > Back(i, j + 1))
        {
            ans = Back(i + 1, j);
            father = 1;
        }
        else
        {
            ans = Back(i, j + 1);
            father = 2;
        }
    }

    return ans;
}*/

int main()
{
    Read();
//    fout << Back(1, 1) << '\n';
    for(int i = n; i >= 1; --i)
        for(int j = m; j >= 1; --j)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else
            {
                if(dp[i + 1][j] > dp[i][j + 1])
                {
                    dp[i][j] = dp[i + 1][j];
                    rec[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i][j + 1];
                    rec[i][j] = 2;
                }
            }
        }

    fout<<dp[1][1]<<'\n';
    Print(1, 1);
    for(int i=0; i<sol.size(); ++i)
        fout<<sol[i]<<" \n"[i+1==sol.size()];
    cout<<a[n+1]<<b[m+1];
    return 0;
}
