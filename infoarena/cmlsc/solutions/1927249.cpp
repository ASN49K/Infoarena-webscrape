#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define Max 1025
int A[Max], B[Max], D[Max][Max], S[Max];

int max(int a, int b){
    if(a<=b)
        return b;
    return a;
}

int main()
{
    int n, m, i, j, rez, lung;
    f >> n >> m;
    for(i = 1; i <= n; i++)
        f >> A[i];
    for(i = 1; i <= n; i++)
        f >> B[i];

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(A[i] == B[j])
                D[i][j] = D[i-1][j-1] + 1;
            else
                D[i][j] = max(D[i-1][j],D[i][j-1]);
    lung = D[n][m];
    i = n;
    j = m;
    while(lung){
        if(A[i] == B[j]){
            S[lung--] = A[i];
            i--;
            j--;
        }
        else if( D[i-1][j] > D[i][j-1] )
            i--;
        else
            j--;
    }
    g << D[n][m] << '\n';
    for(i = 1; i <= D[n][m]; i++)
        g << S[i] << " ";
    return 0;
}
