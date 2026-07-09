#include <fstream>
#include <stack>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

#define MAX 1030


short int mat[MAX][MAX];
short int X[MAX], Y[MAX], T[MAX];

void lcs_length(int m /* length of X */, int n /* length of Y */)
{
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(X[i]==Y[j])
                mat[i][j] = 1 + mat[i-1][j-1];
            else
                // equivalent of: mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
                mat[i][j] = (mat[i-1][j] > mat[i][j-1])? mat[i-1][j] : mat[i][j-1];

}

void construct(int i, int j)
{
    if(mat[i][j] > mat[i][j-1] && mat[i][j] > mat[i-1][j]){
            construct(i-1, j-1);
        }
        else
            if(mat[i-1][j] == mat[i][j]){
                construct(i-1, j);
            }
            else if(mat[i][j-1] == mat[i][j]){
                construct(i, j-1);
            }
}


int main()
{
    int m, n;
    in>>m>>n;
    for(int i = 1; i <= m; i++)
        in>>X[i];
    for(int i = 1; i <= n; i++)
        in>>Y[i];

    LCS(m,n);
    out<<mat[m][n]<<'\n';
    reconstruct(m,n);


    return 0;
}
