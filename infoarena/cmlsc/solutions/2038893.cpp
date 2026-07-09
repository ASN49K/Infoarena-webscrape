 #include<fstream>
using namespace std;
int v[1024],w[1024],a[1024][1024],res[1024];

int main()
{
    int n,m,i,j;
    ifstream fcin("cmlsc.in");
    ofstream fcout("cmlsc.out");

    fcin>>n>>m;
    for(i=0;i<n;i++)
        fcin>>v[i];
    for(i=0;i<m;i++)
        fcin>>w[i];

    for(i=0;i<m;i++)
        if(w[i]==v[0])
            a[0][i]=1;
        else a[0][i]=0;
    for(i=1;i<n;i++)
        if(v[i]==w[0])
            a[i][0]=1;
        else a[i][0]=0;

    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
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
    fcout<<a[n-1][m-1]<<"\n";

    i=n-1;
    j=m-1;
    int k=0;

    while(i>=0 && j>=0)
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
    for(i=k-1;i>=0;i--)
        fcout<<res[i]<<" ";

    fcin.close();
    fcout.close();
    return 0;
}
