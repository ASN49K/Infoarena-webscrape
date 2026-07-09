#include <iostream>
#include <fstream>

using namespace std;

int n,m,i,j,A[1024],B[1024],M[1024][1024],MAX,sir[1024],c;
int nrmax(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>A[i];
    for(i=1;i<=m;i++)
        fin>>B[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(A[i]==B[j])
                M[i][j]=1+M[i-1][j-1];
            else M[i][j] = nrmax(M[i-1][j],M[i][j-1]);

    for(i=n,j=m;i; )
    {
        if(A[i]==B[j])
        {
            sir[c++]=A[i];
            i--; j--;
        }
        else if(M[i][j-1]>M[i-1][j])
                j--;
            else
                i--;
    }

    fout<<M[n][m]<<'\n';
    for(i=c-1;i>=0;i--)
        fout<<sir[i]<<' ';


    return 0;
}
