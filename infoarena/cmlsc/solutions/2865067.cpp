#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <climits>
#include <unordered_map>

#define NMAX 1030

using namespace std;

int n, m;
int a[NMAX], b[NMAX];
int mat[NMAX][NMAX];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{

    fin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fin>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        fin>>b[i];
    }

    

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else{
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }

    fout<<mat[n][m]<<"\n";
    int lin=n,col=m;
    vector<int>sol;
    while(mat[lin][col]!=0 && lin>0 && col>0)
    {
        while(mat[lin][col]==mat[lin-1][col] && lin>0)
        {
            lin--;
        }
        while(mat[lin][col]==mat[lin][col-1] && col>0)
        {
            col--;
        }

        sol.push_back(a[lin]);
        lin--;
        col--;
    }
    for(int i=sol.size()-1; i>=0; i--)
    {
        fout<<sol[i]<<" ";
    }
    return 0;
}