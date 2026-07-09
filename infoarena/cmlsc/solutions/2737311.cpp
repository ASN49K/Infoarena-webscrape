#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[1025], b[1025], d[1025][1025], sir[1025], bst;
int main()
{
    int m, n;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    for(int i=m,j=n;i;)
        if (a[i]==b[j])
            {
                sir[++bst]=a[i];
                i--;
                j--;
            }
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else i--;

    cout<<bst<<'\n';
    for (int i=bst;i;i--)
        cout<<sir[i]<<" ";
    return 0;
}
