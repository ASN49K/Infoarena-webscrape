// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
#include <fstream>
#include <algorithm>
#define N 1026
#define Nax(x,y) (x>y?x:y)

int n, m, mat[N][N], s[N], a[N], b[N];

std::ifstream cin("cmlsc.in");
std::ofstream cout("cmlsc.out");

void Read();
void Solve();
void Form();

int main()
{
    Read();
    Solve();
    Form();
}

void Read()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
}

void Solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j]) mat[i][j] = mat[i - 1][j - 1] + 1;
            else mat[i][j] = Nax(mat[i - 1][j], mat[i][j - 1]);
            //std::cout << mat[i][j] << ' ';
        }
        //std::cout << '\n';
    }
}

void Form()
{
    cout << mat[n][m] << '\n';
    int ct = mat[n][m];
    int i = n, j = m;
    while (ct != 0)
    {
        if (ct != mat[i - 1][j] && ct != mat[i][j - 1])
        {
            s[ct] = a[i];
            i--; j--;
            ct--;
        }
        else
        {
            if (ct == mat[i - 1][j]) i--;
            else j--;
        }
    }
    for (int x = 1; x <= mat[n][m]; x++)
        cout << s[x] << ' ';
}