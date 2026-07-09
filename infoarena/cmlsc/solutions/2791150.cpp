#include <fstream>
#define Nmax 1024
using namespace std;
 ifstream cin ("cmlsc.in");
 ofstream cout ("cmlsc.out");
int m, n, A[Nmax], B[Nmax], D[Nmax][Nmax], sir[Nmax], bst;
int main()
{
    int i, j;
    cin>>m>>n;
    for(i=1;i<=m;i++)
        cin>>A[i];
    for(i=1;i<=n;i++)
        cin>>B[i];
   for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(A[i]==B[j])
                D[i][j]=1+D[i-1][j-1];
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);

    for (i=m,j=n;i;)
        if(A[i]==B[j])
        {
            sir[++bst]=A[i];
            --i;
            --j;
        }
        else
        if(D[i-1][j]<D[i][j-1])
            --j;
        else
            --i;

    cout<<bst<<'\n';
    for(i=bst;i;--i)
        cout<<sir[i]<<" ";

    return 0;
}
