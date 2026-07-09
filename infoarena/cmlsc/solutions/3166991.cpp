#include<fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n, i, j, a[1030], b[1030], sir[1030], d[1030][1030], m;
void construire(int i, int j, int k)
{
    if(k!=0)
    {
        if(a[i]==b[j])
        {
            construire(i-1, j-1, k-1);
            cout<<a[i]<<" ";
        }
        else
        {
            if(d[i-1][j]>d[i][j-1])
                construire(i-1, j, k);
            else
                construire(i, j-1, k);

        }
    }
}
int main()
{
    cin>>n>>m;
    for(i=1; i<=n; i++)
        cin>>a[i];
    for(j=1; j<=m; j++)
        cin>>b[j];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (a[i] == b[j])
            {
                d[i][j] = 1 + d[i-1][j-1];
            }
            else
            {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
    cout<<d[n][m]<<"\n";
    construire(n, m, d[n][m]);

}
