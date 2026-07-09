 #include<fstream>
using namespace std;
int v[1025],w[1025],a[1025][1025],res[1025];

int main()
{
    int n,m,i,j;
    ifstream fcin("cmlsc.in");
    ofstream fcout("cmlsc.out");

    fcin>>n>>m;
    for(i=1;i<=n;i++)
        fcin>>v[i];
    for(i=1;i<=m;i++)
        fcin>>w[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(v[i]==w[j])
        {
            a[i][j]=a[i-1][j-1]+1;
        }
        else
        {
            a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    }
    fcout<<a[n][m]<<"\n";

    i=n;
    j=m;
    int k=1;

    while(i>0 && j>0)
    {
        if(v[i]==w[j])
        {
            res[k++]=v[i];
            i--; j--;
        }
        else
        {
                if(a[i-1][j]>a[i][j-1])
                    i--;
                else
                    j--;
        }
    }
    for(i=k-1;i>0;i--)
        fcout<<res[i]<<" ";

    fcin.close();
    fcout.close();
    return 0;
}
