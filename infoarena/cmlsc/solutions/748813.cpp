#include <fstream>
using namespace std;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int M,N,a[1026],b[1026],c[1025][1025],i,j,v;
    f>>M>>N;
    for(i=1;i<=M;i++)
    {
        f>>a[i];
    }
    for(i=1;i<=N;i++)
    {
        f>>b[i];
    }

    for(i=0;i<=max(M,N);i++)
    {
        c[i][0]=c[0][i]=0;
    }


    for(i=1;i<=M;i++)
    for(j=1;j<=N;j++)
    {
        if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
        else c[i][j]=max(c[i][j-1],c[i-1][j]);
    }
    g<<c[M][N]<<endl;
    v=0;
    for(i=1;i<=M;i++)
    for(j=1;j<=N;j++)
    {
        if(c[i][j]>v)
        {
            g<<b[j]<<" ";
            v=c[i][j];
        }
    }


    f.close();
    g.close();
    return 0;
}
