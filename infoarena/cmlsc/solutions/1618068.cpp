#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[1027],B[1027],AB[1027][1027],i,j,m,n,rez[1027],nr=0;;
int main()
{
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>A[i];
    for(j=1;j<=n;j++)
        fin>>B[j];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(A[i]==B[j])AB[i][j]=AB[i-1][j-1]+1;
            else AB[i][j]=max(AB[i][j-1],AB[i-1][j]);
        }
    i=m;j=n;
    while(i>0 and j>0)
    {
        if(A[i]==B[j]){rez[++nr]=A[i];i--;j--;}
        if(AB[i-1][j]<AB[i][j-1])j--;
        else i--;
    }
    fout<<nr<<"\n";
    for(i=nr;i>=1;i--)
        fout<<rez[i]<<" ";

    return 0;
}
