#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, s[1050], p[1050];
int mat[1024][1024];
vector<int> solutie;
void citire()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> s[i];
    for(int j = 1; j <= m; j++)
        fin >> p[j];
}

int dp(int i, int j)
{
//    cout << i << ' ' << j << ' ' << mat[i][j+1] << ' ' << mat[i+1][j] << '\n';
    if(i == n+1 || j == m+1)
        return 0;
    if(s[i] == p[j])
    {
        if(!mat[i+1][j+1])
            mat[i+1][j+1] = dp(i+1, j+1);
        mat[i][j] = 1+mat[i+1][j+1];
        return mat[i][j];
    }
    else
    {
        if(!mat[i][j+1])
            mat[i][j+1] = dp(i, j+1);
        if (!mat[i+1][j])
        {
            mat[i+1][j] = dp(i+1, j);
        }

        mat[i][j] = max(mat[i][j+1], mat[i+1][j]);
        return max(mat[i][j+1], mat[i+1][j]);
    }
}

int main()
{
    citire();
    int maxim = dp(1,1);
    fout << maxim;
    for(int i = 1; i <= n; i++)
    {
        if(maxim == 0)
            break;
        for(int j = 1; j <= m; j++)
        {
            if(maxim == 0)
                break; 
            if(mat[i][j] == maxim)
            {
                while(mat[i][j] == maxim)
                    j++;
//                cout << j << '\n';
                solutie.push_back(p[j-1]);
            }
        }
        maxim--;
    }
    
//
//    for(int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++) {
//            cout << mat[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << "\n\n";
    fout << '\n';
    for (int i = 0; i < solutie.size(); i++)
    {
        fout << solutie[i] << ' ';
    }
    return 0;
}
