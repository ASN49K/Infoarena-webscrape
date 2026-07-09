#include <fstream>
#include<stack>
using namespace std;
#define maxx(a, b) ((a > b) ? a : b)
int main()
{
    int n, m, A[1024], B[1024], D[1024][1024], v[1024], nr = 0;
    stack<int> st;
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin >> m >> n;
    for(int i = 1; i<= m ; ++i)
        fin >> A[i];
    for(int i = 1; i<= n ; ++i)
        fin >> B[i];

    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            if(A[i] == B[j])
                D[i][j] = D[i-1][j-1]+1;
            else
                D[i][j]=maxx(D[i-1][j], D[i][j-1]);
    fout<< D[m][n]<< endl;
    int i, j;
    for(i = m, j = n; i;)
       if (A[i] == B[j]){
          v[++nr] = A[i];
          --i; --j;
          }
        else if (D[i-1][j] < D[i][j-1])
             --j;
        else --i;
     for (int i = nr; i; --i)
          fout << v[i]<< ' ' ;
    return 0;
}
