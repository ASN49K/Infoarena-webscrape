#include <fstream>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int v[1030][1030], a[1030],b[1030],c[1030], n, m, i, j, crt=1;

int main()
{
    fin>>n>>m;
    for ( i = 1 ; i <= n ; i++ )
        fin>>a[i];
    for ( j = 1 ; j <= m ; j++ )
        fin>>b[j];

    for ( i = 1 ; i <= n ; i++ )
        for ( j = 1 ;j <= m ; j++ )
            if(a[i]==b[j])
                v[i][j]=1+v[i-1][j-1];
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);

    i=n;j=m;
    while(i!=0&&j!=0)
    {
        if(a[i]==b[j])
            c[crt++]=a[i],i--,j--;
        else
            if(v[i-1][j]<v[i][j-1])
                j--;
            else
                i--;
    }
    fout<<crt-1<<"\n";
    for( i = crt-1 ; i ; i-- )
        fout<<c[i]<<" ";
    return 0;
}
