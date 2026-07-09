#include<bits/stdc++.h>
using namespace std;
ofstream fout("cmlsc.out");
ifstream fin("cmlsc.in");
int main()
{
    int n , m;
    fin >> n >> m;
    int first[n] = {};
    int second[m] = {};
    int matrix[n+1][m+1];
    vector<int> out;
    for(int i = 0; i < n; i++)
    {
        fin >> first[i];
    }
    for(int j = 0; j < m ; j++)
    {
        fin >> second[j];
    }
    for(int x = 0; x < m+1; x++)
    {
        matrix[0][x] = 0;
    }
    for(int y = 1; y < n+1; y++)
    {
        matrix[y][0] = 0;
    }
    for(int down = 0; down < n; down++)
    {
        for(int left = 0; left < m; left++)
        {
            if(first[down] == second[left])
            {
                matrix[down+1][left+1] = matrix[down][left] + 1;
            }
            else
            {
                matrix[down+1][left+1] = max(matrix[down][left+1],matrix[down+1][left]);
            }
        }
    }

    int k = matrix[n][m];
    int y = n, x = m;
    while(k != 0)
    {
        if(k > matrix[y][x-1] && k > matrix[y-1][x])
        {
            out.push_back(first[y-1]);
            --y;--x;
            k = matrix[y][x];
        }
        else if(k == matrix[y-1][x])
        {
            --y;
            k = matrix[y][x];
        }
        else
        {
            --x;
            k = matrix[y][x];
        }
    }
    fout << out.size() << '\n';
    for(int i = 0; i < out.size(); i++)
    {
        fout << out[out.size()-1-i] << ' ';
    }

}
