#include <bits/stdc++.h>
using namespace std;

vector <int> row, col, v;

int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n, m, mn;
    cin >> n >> m;
    row.resize(n+1);
    col.resize(m+1);
    vector<vector<int>> mat(n+1, vector<int>(m+1, 0));
    
    for(int i=1; i<=n; i++)
    {
        cin >> row[i];
    }
    for(int i=1; i<=m; i++)
    {
        cin >> col[i];
    }
    
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<m+1; j++)
        {
            mat[i][j]=max(mat[i-1][j], mat[i][j-1]);
            if(row[i]==col[j])
                mat[i][j]=max(mat[i-1][j-1]+1, mat[i][j]);
        }
    }
    cout << mat[n][m] << "\n";
    
    int i, j;
    int cnt=0;
    i=n;
    j=m;
    while(i>0 && j>0)
    {
        cout << i << " " << j << "\n";
        if(row[i]==col[j] && mat[i-1][j-1]==mat[i][j]-1)
        {
            v.push_back(row[i]);
            i--;
            j--;
            cnt++;
        }
        else
        {
            if(mat[i][j-1]>mat[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    for(int i=cnt-1; i>=0; i--)
    cout << v[i] << " ";
    

    return 0;
}