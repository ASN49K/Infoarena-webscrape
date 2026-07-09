#include <fstream>
using namespace std;
int A[1024],B[1024],D[1024][1024],sir[1024],contor;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int n,m;

    fin>>n>>m;
    for(int i = 1;i<=n;i++)
        fin>>A[i];
    for(int i = 1;i<=m;i++)
        fin>>B[i];
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            if(A[i]==B[j])
                D[i][j] = 1+D[i-1][j-1];
            else
                D[i][j] = ((D[i-1][j]>D[i][j-1])?D[i-1][j]:D[i][j-1]);
    for(int i = n,j = m;i;)
    {
        if(A[i]==B[j])
            sir[++contor]=A[i],--i,--j;
        else if(D[i-1][j]<D[i][j-1])
            --j;
        else
            --i;
    }
    fout<<contor<<endl;
    for(;contor;contor--)
        fout<<sir[contor]<<" ";
    return 0;
}
