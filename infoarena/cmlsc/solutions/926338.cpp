#include <iostream>
#include <fstream>
using namespace std;

int L1, L2, i, j;

int A[1030], B[1030];

int D[1030][1030];

int REZ[1030];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(){
freopen("cmlsc.in", "r", stdin);
freopen("cmlsc.out", "w", stdout);
scanf("%d %d", &L1, &L2);

for(i=1;i<=L1;++i)
    scanf("%d", &A[i]);

for(i=1;i<=L2;++i)
    scanf("%d", &B[i]);

for(i=1;i<=L1;++i)
    for(j=1;j<=L2;++j)
        if(A[i] == B[j])
            D[i][j] = 1 + D[i-1][j-1];
        else
            D[i][j] = max(D[i-1][j], D[i][j-1]);

int ok = 0, lmax = 0;

for(i=L1,j=L2;i;)
    if(A[i] == B[j])
    {
        REZ[++lmax] = A[i];
        --i,--j;
    }
    else if(D[i-1][j] < D[i][j-1])
        --j;
    else
        --i;

    cout<<lmax<<"\n";

    for(i=lmax;i>=1;--i)
        cout<<REZ[i]<<" ";

    return 0;
}
