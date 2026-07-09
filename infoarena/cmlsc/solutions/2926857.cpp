#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v[1025][1025],stringu[1025],substringu[1025],rez[1025];


int main()
{int a,b,i,j,k,x=0;
    fin>>a>>b;
    for (i=1;i<=a;++i)
        fin>>stringu[i];
    for (i=1;i<=b;++i)
        fin>>substringu[i];
    for (i=1;i<=a;++i)
    for (j=1;j<=b;++j)
    if (stringu[i]==substringu[j])
        v[i][j]=v[i-1][j-1]+1;
    else
        v[i][j]=max(v[i-1][j],v[i][j-1]);
    fout<<v[a][b]<<endl;
    k=v[a][b];
    i=a;
    j=b;
    while (k>0 && (i>0 || j>0))
    {
        if (stringu[i]==substringu[j])
        {
            --k;
            rez[++x]=stringu[i];
            --i;
            --j;
        }
        else
            if (v[i-1][j]>v[i][j-1])
                --i;
            else
                --j;
    }
    for (i=x;i>=1;--i)
        fout<<rez[i]<<" ";
        return 0;
}
