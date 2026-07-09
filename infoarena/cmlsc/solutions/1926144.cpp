
#include<fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int i,j,n,m,a[1025],b[1025],c[1025][1025],Max,jmax;
void construire ()
{
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if (a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
}

int drum (int i,int j)
{
    if(i>=1 && j>=1)
    {
        if(a[i]==b[j]) drum(i-1,j-1);
        else if (c[i-1][j]>c[i][j-1]) drum(i-1,j);
        else drum(i,j-1);

        if(a[i]==b[j]) g<<a[i]<<" ";
    }
}
int main()
{
    f>>m>>n;

    for(i=1; i<=m; i++)
        f>>a[i];

    for(i=1; i<=n; i++)
        f>>b[i];

    construire();


    for(i=1;i<=m;i++)
   {

    for(j=1;j<=n;j++)
    g<<c[i][j]<<" ";

    g<<endl;
   }

    g<<c[m][n]<<endl;
    drum(m,n);


    return 0;
}
