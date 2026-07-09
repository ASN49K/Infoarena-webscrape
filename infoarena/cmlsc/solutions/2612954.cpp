#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int A[1025], B[1025], D[1025][1025], v[1025];

int main()
{
    int n, m, i, j, rasp;
    cin>>m>>n;
    for(i=1; i<=m; i++)
        cin>>A[i];
    for(j=1; j<=n; j++)
        cin>>B[j];
    for(i=1; i<=m; i++)
        for(j=1;j<=n; j++)
    {
        if(A[i]==B[j])
            D[i][j]=D[i-1][j-1]+1;
        else
            D[i][j]=max(D[i][j-1], D[i-1][j]);
    }
    rasp=D[m][n];
    cout<<rasp<<'\n';
    for(i=m, j<=n; i>0 && j>0; )
    {
        if(A[i]==B[j])
        {
            v[rasp--]=A[i];
            --i;
            --j;
        }
        else
        {
            if(D[i-1][j]>=D[i][j-1])
                i--;
            else
                j--;


        }
    }
    for(i=1; i<=D[m][n]; i++)
        cout<<v[i]<<' ';

    return 0;
}
