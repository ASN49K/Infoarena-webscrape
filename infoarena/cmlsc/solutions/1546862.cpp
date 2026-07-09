#include<fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int v[1024],w[1024],a[1024][1024],m,n,aux[1024],k;
int maxim(int x, int y)
{
    if(x>y)
        return x;
    return y;
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v[i];
    for(int i=1;i<=m;i++)
        fin>>w[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(v[i]==w[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=maxim(a[i-1][j],a[i][j-1]);
    fout<<a[n][m]<<endl;
    int i=n;
    int j=m;
    while(i)
    {
        if(v[i]==w[j])
        {
            aux[k++]=v[i];
            i--;
            j--;
        }
        else if(a[i-1][j]<a[i][j-1])
            j--;
        else
            i--;
    }
    for(int i=k-1;i>0;i--)
        fout<<aux[i]<<" ";
    return 0;
}
