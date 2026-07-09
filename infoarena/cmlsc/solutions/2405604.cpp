#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int m, n, a[1025], b[1025], d[1025][1025], sir[1025], bst=0, x,y,maxs=0;
int main()
{
    int i,j;
    cin>>m>>n;
    // citesc sirul a
    for(i=1; i<=m; i++)
        cin>>a[i];
    //citesc sirul b
    for(j=1; j<=n; j++)
        cin>>b[j];

    for(i=1; i<=m; ++i)
        for(j=1; j<=n; ++j)
        {
            if(a[i]==b[j])
            {
                d[i][j]=1+d[i-1][j-1];
                if(d[i][j]>maxs)
                {
                    maxs=d[i][j];
                    x=i;
                    y=j;
                }
            }
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
        }

    /*cout << "max sir:" << maxs << endl;
    for(i=x-maxs+1; i<=x; i++)
    {
      cout << a[i] <<" " ;
    }
    cout<<endl;*/

    //cout<<endl;
    //cout<<endl;

    //cout<<endl;
    cout << d[m][n] << endl;
    for (i = m, j = n; i; )
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
            for(i=bst;i>=1;i--)
            cout<<sir[i]<<" ";

    return 0;
}
