#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int M,N,a[1026],b[1026],c[102][102],i,j,v,sir[1024],bst=0;
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
    for(i=M,j=N;i;)
        if (a[i] == b[j])
        sir[++bst] = a[i], --i, --j;
        else if (c[i-1][j] < c[i][j-1])
        --j;
        else
        --i;
    for (i = bst; i; --i)
    g<<sir[i]<<" ";

    f.close();
    g.close();
    return 0;
}
