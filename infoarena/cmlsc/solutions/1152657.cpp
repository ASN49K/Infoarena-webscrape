#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1050],b[1050],ma[1050][1050],i,j,m,n,val[1050],q;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;++i) fin>>a[i];
    for(i=1;i<=m;++i) fin>>b[i];

    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    {

        if(a[i]==b[j])
            ma[i][j]=ma[i-1][j-1]+1;
        else
            ma[i][j]=max(ma[i-1][j],ma[i][j-1]);
    }
    for(i=n,j=m;i;)
    {
        if(a[i]==b[j])
        val[++q]=a[i],i--,j--;
        else
        {
            if(ma[i][j-1]>ma[i-1][j])
                j--;
            else
            i--;
        }
    }
    fout<<q<<'\n';
    while(q)
    {
        fout<<val[q]<<" ";
        q--;
    }

    return 0;
}
