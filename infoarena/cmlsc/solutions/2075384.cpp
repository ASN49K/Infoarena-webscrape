#include <iostream>
#include <fstream>

using namespace std;

int a[1025],b[1025],d[1025][1025], s[1025];
int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    int n,m,i,j;
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(i=1; i<=m; i++)
        fin>>b[i];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j]) d[i][j] = d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    i=n;
    j=m;
    int k=0;
    fout<<d[i][j]<<"\n";
    while(j)
    {
        if(a[i]==b[j]){
            s[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
        }
    }
    for(i=k;i>0;i--)
        fout<<s[i]<<" ";
    return 0;
}
