#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int sir[1030],m,n,i,j,k,H[1030][1030],A[300],B[300],bst;
int main()
{
    f>>m>>n;
    for(i=1;i<=m;i++)
    f>>A[i];
    for(i=1;i<=n;i++)
    f>>B[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
           if(A[i]==B[j]) H[i][j]=1+H[i-1][j-1];
            else
                H[i][j] = max(H[i-1][j], H[i][j-1]);

      for (i = m, j = n; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (H[i-1][j]<H[i][j-1])
            --j;
        else
            --i;
            g<<bst<<'\n';
for(i=bst;i>1;--i)
    g<<sir[i]<<" ";
    return 0;
}
