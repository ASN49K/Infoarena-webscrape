#include<fstream>
using namespace std;
#define dim 1001
short int s1[dim],s2[dim],m,n; short int l[dim][dim],v[dim],k;
short int maxim(short int x,short int y)
{
    if(x>=y) return x;
    return y;
}
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    short int i,j;
    f>>m>>n;
    for(i=1;i<=m;i++) f>>s1[i];
    for(i=1;i<=n;i++) f>>s2[i];
    f.close();
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    {
        if(s1[i]==s2[j]) l[i][j]=l[i-1][j-1]+1;
        else l[i][j]=maxim(l[i-1][j],l[i][j-1]);
    }
    g<<l[m][n]<<'\n';
    while(l[m][n])
    {
        if(s1[m]==s2[n])
        {
            v[++k]=s1[m];
            m--; n--;
        }
        else if(l[m][n]==l[m-1][n]) m--;
        else n--;
    }
    for(i=k;i>=1;i--) g<<v[i]<<' '; g<<'\n';
    g.close();
    return 0;
}
