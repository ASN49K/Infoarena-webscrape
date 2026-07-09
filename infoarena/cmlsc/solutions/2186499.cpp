#include <iostream>
#include <fstream>

using namespace std;

int V[1025][1025];
int maxim(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int m,n;
    int A[1025],B[1025],sir[1025];
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m>>n;
    V[0][0]=0;
    for(int i=1;i<=m;i++)
    {
        f>>A[i];
        V[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        f>>B[i];
        V[0][i]=0;
    }
    f.close();
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            if(A[i]==B[j])
                V[i][j]=V[i-1][j-1]+1;
            else
                V[i][j]=maxim(V[i-1][j],V[i][j-1]);
        }
    g<<V[m][n]<<"\n";
    int l=0;
    int i=m,j=n;
    while((i>0)&&(j>0))
    {
        if(V[i][j]==V[i-1][j])
            i--;
        else if(V[i][j]==V[i][j-1])
            j--;
        else
        {
            l++;
            sir[l]=A[i];
            i--;
            j--;
        }
    }
    for(int i=l;i>=1;i--)
        g<<sir[i]<<" ";
    return 0;
}
