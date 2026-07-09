#include <fstream>
#define maxim(a, b) ((a > b) ? a : b)
using namespace std;
int d[1024][1024], c[1024];
int main()
{
    int m, n, a[1024], b[1024], i, j, s=0, x=0;
    ifstream file1 ("cmlsc.in");
    ofstream file2 ("cmlsc.out");
    file1>>m;
    file1>>n;
    //cout<<m<<" "<<n<<endl;
    for(i=1;i<=m;i++)
    {
        file1>>a[i];
       // cout<<a[i];
    }
    //cout<<endl;
    for(i=1;i<=n;i++)
    {
        file1>>b[i];
       // cout<<b[i];
    }
    //cout<<endl;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if (a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j] = maxim(d[i-1][j], d[i][j-1]);
    s=d[m][n];
       /* for(i=0;i<=m;i++)
            for(j=0;j<=n;j++)
        {
                cout<<d[i][j];
                if(j==n)
                    cout<<endl;
        }*/

    file2<<s<<endl;
    x=s;
    i=m;
    j=n;
    while(i)
    {

        if(a[i]==b[j])
        {
            c[x]=a[i];
            i--;
            j--;
            x--;
        }
        else
        {
            if(d[i-1][j] < d[i][j-1])
                j--;
            else
                i--;
        }
    }
    for(i=1;i<=s;i++)
        file2<<c[i]<<" ";

    file1.close();
    file2.close();
    return 0;
}
