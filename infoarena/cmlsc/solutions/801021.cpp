#include <fstream>
#include <iostream>
#include <iterator>

#define MAX_SIZE 1024

using namespace std;

int vA[MAX_SIZE+1];
int vB[MAX_SIZE+1];
int common[MAX_SIZE+1];

int mat[MAX_SIZE+1][MAX_SIZE+1];

int main()
{
    int n, m;
    fstream fin("cmlsc.in", fstream::in);
    fstream fout("cmlsc.out", fstream::out);
    
    fin >> n >> m;
    //cout << n << " " << m << endl;
    
    for (int i=1; i<=n; ++i)
    {
        fin >> vA[i];
        //cout << vA[i] << " ";
    }
    //cout << endl;
    
    for (int i=1; i<=m; ++i)
    {
        fin >> vB[i];
        //cout << vB[i] << " ";
    }
    //cout << endl << endl;
    
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=m; ++j)
        {
            if (vA[i] == vB[j])
            {
                mat[i][j] = max(mat[i-1][j-1]+1, mat[i][j]);
            }
            else
            {
                mat[i][j] = max(mat[i][j-1], mat[i-1][j]);
            }
        }
    }
    
    int len = mat[n][m];
    
    fout << len << endl;
    
    int i=n, j=m;
    while (len > 0)
    {
        int prevLen = max(mat[i-1][j-1], max(mat[i-1][j], mat[i][j-1]));
        
        if (prevLen == len-1)
        {
            common[len] = vA[i];
            len--;
        }
        
        if (prevLen == mat[i-1][j-1])
        {
            i--;
            j--;
        }
        else if (prevLen == mat[i-1][j])
        {
            i--;
        }
        else if (prevLen == mat[i][j-1])
        {
            j--;
        }
    }
    
    for (int i=1; i<=mat[n][m]; ++i)
    {
        fout << common[i] << " ";
    }
    
    fin.close();
    fout.close();
    return 0;
}
