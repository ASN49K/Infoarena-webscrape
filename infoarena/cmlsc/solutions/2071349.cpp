#include <fstream>
using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int a[1026],b[1026],v[1026][1026],n,m;

void load ()
{
    int i,j;
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];

    for(j=1; j<=m; j++)
        f>>b[j];
}

int k=1;

void common ()
{
    int i,j;

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            v[i][j]=0;
    int u=0;

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                if( u==0 || u<j )
                {
                    v[i][j]=k;
                    k++;
                    u=j;
                }
}

void print ()
{
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(v[i][j]!=0)
                g<<a[i]<<" ";
}
int main()
{
    load ();
    common();
    print();

     /*int i,j;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++)
            g<<v[i][j]<<" ";
        g<<endl;
        } */

    return 0;
}
