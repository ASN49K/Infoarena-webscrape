#include <fstream>
#include <algorithm>
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int n,m,i,j,A[1024],B[1024],D[1024][1024],R[1024],rez;
int main()
{
    fi>>n>>m;
    for(i=1; i<=n; i++)
        fi>>A[i];
    for(i=1; i<=m; i++)
        fi>>B[i];
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(A[i]==B[j])
            {
                D[i][j]=1+D[i-1][j-1];
            }
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);
        }
    }
    for(i=n, j=m; i;)
    {
        if(A[i]==B[j])
        {
            R[++rez]=A[i];
            i--;
            j--;
        }
        else
        {
            if(D[i-1][j]<D[i][j-1])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    fo<<rez<<"\n";
    for(i=rez; i>=1; i--)
    {
        fo<<R[i]<<" ";
    }
    fo<<"\n";
    fi.close();
    fo.close();
    return 0;
}
