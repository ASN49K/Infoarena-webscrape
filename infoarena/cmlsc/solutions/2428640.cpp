#include <fstream>
using namespace std;
int A[1025],B[1025],D[1025][1025],sir[1025],contor;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int n,m;

    fin>>n>>m;
    for(int i = 0;i<n;i++)
        fin>>A[i];
    for(int i = 0;i<m;i++)
        fin>>B[i];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            if(A[i]==B[j])
                D[i][j] = 1+D[i-1][j-1];
            else
                D[i][j] = ((D[i-1][j]>D[i][j-1])?D[i-1][j]:D[i][j-1]);
    for(int i = n-1,j = m-1;i;)
    {
        if(A[i]==B[j])
            sir[contor++]=A[i],--i,--j;
        else if(D[i-1][j]<D[i][j-1])
            --j;
        else
            --i;
    }
    fout<<contor--<<endl;
    for(;contor>=0;contor--)
        fout<<sir[contor]<<" ";
    return 0;
}
