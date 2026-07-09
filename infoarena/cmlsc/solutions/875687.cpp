#include <fstream>
#define NMax 1024
using namespace std;

int m,n,a[NMax],b[NMax],c[NMax][NMax],sir[NMax],opt,i,j;

int maxim(int a, int b)
{
    if(a>b)
    return a;
    return b;
}

int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");

    cin>>m>>n;
   for(i=1;i<=m;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        cin>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if (a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=maxim(c[i-1][j],c[i][j-1]);

    for(i=m;i>=1;i--)
        for(j=n;j>=1;j--)
        if (a[i]==b[j])
            sir[++opt]=a[i],--i,--j;
        else
        if(c[i-1][j]<c[i][j-1])
            --j;
        else
            --i;

    cout<<opt<<"\n";
    for (i=opt;i>=1;--i)
        cout<<sir[i]<<' ';

    return 0;
}
