// celmailungsubsircomun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N, M, a[1024], b[1024], Dp[1024][1024], rez[1024], lg;

int main()
{
    fin >> N >> M;
    for (int i = 1; i <= N; i++)
        fin >> a[i];
    for (int i = 1; i <= M; i++)
        fin >> b[i];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (a[i] == b[j])
                Dp[i][j] = Dp[i - 1][j - 1] + 1;///daca am prop
            else
                Dp[i][j] = max(Dp[i - 1][j], Dp[i][j - 1]);///daca nu am prop
        }
    }
    int x = N;
    int y = M;

    while(x and y)
    {
        if (a[x] == b[y])
            rez[++lg] = a[x], x--, y--;
        else
            if (Dp[x - 1][y] > Dp[x][y - 1])
                x--;
            else
                y--;
    }
    fout << lg << endl;
    for (int i = lg; i >= 1; i--)
        fout << rez[i] << " ";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
