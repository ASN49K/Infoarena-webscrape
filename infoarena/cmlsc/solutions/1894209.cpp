#include <fstream>
#include<vector>
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int A[1025], B[1025], C[1025][1025];
vector <int> V;

int main()
{

    int i,j,n,m;
    int l,c;
    fi>>n>>m;
    for(i=1; i<=n; i++)
        fi>>A[i];
    for(j=1; j<=m; j++)
        fi>>B[j];
     for(i=0;i<=n; i++)
        C[i][0]=0;
    for(j=0; j<=m; j++)
        C[0][j]=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
    {
        if(A[i]==B[j])
            C[i][j]=C[i-1][j-1]+1;
        else
            C[i][j]=max(C[i][j-1], C[i-1][j]);
    }
    /*
        for(i=1;i<=n; i++)
    {
        for(j=1; j<=m; j++)
            fo<<C[i][j]<<" ";
        fo<<"\n";
    }
    */
    fo<<C[n][m]<<"\n";
    l=n;
    c=m;
    while(l || c)
    {
        if(C[l][c]==C[l-1][c])
            l--;
        else
            if(C[l][c]==C[l][c-1])
                c--;
            else
                if(C[l][c]==C[l-1][c-1]+1)
            {
                V.push_back(A[l]);
                l--;
                c--;
            }
    }
    for(vector<int>::reverse_iterator it = V.rbegin();
        it != V.rend(); ++it )
        fo<<*it<<" ";
    fi.close();
    fo.close();
}
