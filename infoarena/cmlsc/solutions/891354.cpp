#include <iostream>
#include <fstream>
#define maxim(a,b) ((a>b)?a:b)
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int main()
{
    int a[1024], b[1024], s[1024], i, j, n, m, k;
    in>>m>>n;
    for(i=1; i<=m; i++)
        in>>a[i];
    for(i=1; i<=n; i++)
        in>>b[i];
    for(i=1; i<m; i++)
        for(j=1; j<n; j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j], c[i][j-1]));
    i=m; j=n; k=c[m][n];
    while(i && j)
        if(a[i]==b[j])
        {
            s[k]=a[i];
            k--;
            i--;
            j--;
        }
        else
            if(c[i-1][j]<c[i][j-1])
                j--;
            else
                i--;
    out<<c[m][n];
    for(i=1; i<=c[m][n]; i++)
        cout<<s[i]<<" ";
    out.close();
    return 0;
}
